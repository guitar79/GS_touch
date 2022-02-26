/*------------------------------------------------------------------------
Command   Response    Description
GP        XXXX        Get Current Motor 1 Positon, Unsigned Hexadecimal
GN        XXXX        Get the New Motor 1 Position, Unsigned Hexadecimal
GT        XXXX        Get the Current Temperature, Signed Hexadecimal
GD        XX          Get the Motor 1 speed, valid options are “02, 04, 08, 10, 20”
GH        XX          “FF” if half step is set, otherwise “00”
GI        XX          “01” if the motor is moving, otherwise “00”
GB        XX          The current RED Led Backlight value, Unsigned Hexadecimal
GV        XX          Code for current firmware version
SPxxxx                Set the Current Motor 1 Position, Unsigned Hexadecimal
SNxxxx                Set the New Motor 1 Position, Unsigned Hexadecimal
SF                    Set Motor 1 to Full Step
SH                    Set Motor 1 to Half Step
SDxx                  Set the Motor 1 speed, valid options are “02, 04, 08, 10, 20”
FG                    Start a Motor 1 move, moves the motor to the New Position.
FQ                    Halt Motor 1 move, position is retained, motor is stopped.

Serial Commands: 
All commands are preceded by a “:” symbol and 
finished with a “#” symbol. “x” represents a 
hexadecimal digit.

Example: To set a new position: :SN0537#
For motor 2 all of the above commands are available, just precede the command with a “2”.
Motor 2 Example: To set Motor 2 to a new position: :2SN0537#

------------------------------------------------------------------------*/
/*------------------------------------------------------------------------
Generic serial commands can be used to operate the controllers if needed. 
Please see table below for command set.

Command Char #        Return Variable         Comments
1 2 3 4 5 6 7 8 
: C #                 N/A                     
Initiate a temperature conversion; the conversion process takes a maximum of 750 milliseconds. The value returned by the :GT# command will not be valid until the conversion process completes.

: F G #               N/A 
Go to the new position as set by the ":SNYYYY#" command.

: F Q #               N/A 
Immediately stop any focus motor movement.

: G C #               XX# 
Returns the temperature coefficient where XX is a two-digit signed (2’s complement) hex number.

: G D #               XX# 
Returns the current stepping delay where XX is a two-digit unsigned hex number. See the :SD# command for a list of possible return values.

: G H #               00# OR FF# 
Returns "FF#" if the focus motor is half-stepped otherwise return "00#"

: G I #               00# OR 01# 
Returns "00#" if the focus motor is not moving, otherwise return "01#"

: G N #               YYYY# 
Returns the new position previously set by a ":SNYYYY" command where YYYY is a four-digit unsigned hex number.

: G P #               YYYY# 
Returns the current position where YYYY is a four-digit unsigned hex number.

: G T #               YYYY# 
Returns the current temperature where YYYY is a four-digit signed (2’s complement) hex number.

: G V #               DD# 
Get the version of the firmware as a two-digit decimal number where the first digit is the major version number, and the second digit is the minor version number.

: S C X X #           N/A 
Set the new temperature coefficient where XX is a two-digit, signed (2’s complement) hex number.

: S D X X #           N/A 
Set the new stepping delay where XX is a two-digit, unsigned hex number. Valid values to send are 02, 04, 08, 10 and 20, which correspond to a stepping delay of 250, 125, 63, 32 and 16 steps per second respectively.

: S F #               N/A 
Set full-step mode.

: S H #               N/A 
Set half-step mode.

: S N Y Y Y Y #       N/A 
Set the new position where YYYY is a four-digit unsigned hex number.

: S P Y Y Y Y #       N/A 
Set the current position where YYYY is a four-digit unsigned hex number.

: + #                 N/A 
Activate temperature compensation focusing.

: - #                 N/A 
Disable temperature compensation focusing.

: P O X X #           N/A 
Temperature calibration offset, XX is a two-digit signed hex number, in half degree increments. 
Example 1: :PO02# offset of +1°C  
Example 2: :POFB# offset of -2.5°C
------------------------------------------------------------------------*/


#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AccelStepper.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TimerOne.h>
#include <Stream.h>
#include "DummySerial.h"
#include "EEPROM.h"
#include "DHT22.h"

#define BTN_IN 7
#define BTN_OUT 8
#define BTN_STEP 32

#define PIN_DRIVER_ENABLE 4
#define PIN_DRIVER_DIR 3
#define PIN_DRIVER_STEP 5

// temp sensor
#define ONE_WIRE_BUS 2 

// for EEPROM set
#include <EEPROM.h>
int eepromPOSOffset = 48;

#define PERIOD_US 2000

#define DEBUG
#ifdef DEBUG
    SoftwareSerial debugSerial(9, 10);
#else
    DummySerial debugSerial;
#endif

// initialize the stepper library
// #define USE_DRIVER
#ifdef USE_DRIVER
    AccelStepper stepper(AccelStepper::DRIVER, PIN_DRIVER_STEP, PIN_DRIVER_DIR);
#else
    AccelStepper stepper(AccelStepper::FULL4WIRE, 6, 4, 5, 3, false);
#endif

// temperature
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// multiplier of SPEEDMUX, currently max speed is 480.
int speedFactor = 16;
int speedFactorRaw = 4;
int speedMult = 30;

float t_coeff = 0;

// button
unsigned long currentPosition = 0;
long targetPosition = 0;
unsigned long lastSavedPosition = 0;
long millisLastMove = 0;
const long millisDisableDelay = 15000;
bool isRunning = false;

// read commands
bool eoc = false;
String line;

// function declarations
long hexstr2long(String line);
static void intHandler();

/*************************************
 * SETUP
*************************************/
void setup()
    {
        Serial.begin(9600);
        debugSerial.begin(9600);
        
        // change firmware in eepROM
        checkFWEEPROM();
        
        // setup pins
        pinMode(LED_BUILTIN, OUTPUT);
        digitalWrite(LED_BUILTIN, LOW);

        // initalize motor
        debugSerial.println("init motor driver...");
        stepper.setMaxSpeed(speedFactor * speedMult);
        stepper.setAcceleration(100);
        #ifdef USE_DRIVER
          stepper.setEnablePin(PIN_DRIVER_ENABLE);
        #endif
        millisLastMove = millis();

        // read saved position from EEPROM
        // EEPROM.put(0, (long)0);
        EEPROM.get(eepromPOSOffset, currentPosition);
        // prevent negative values if EEPROM is empty
        currentPosition = max(0, currentPosition);

        stepper.setCurrentPosition(currentPosition);
        lastSavedPosition = currentPosition;
        Serial.print("Last position in EEPROM: ");
        Serial.println(lastSavedPosition);
        debugSerial.print("Last position in EEPROM: ");
        debugSerial.println(lastSavedPosition);

        // init temperature sensor
        sensors.begin();


        // setup buttons
        pinMode(BTN_IN, INPUT_PULLUP);
        pinMode(BTN_OUT, INPUT_PULLUP);

        // init timer
        Timer1.initialize(PERIOD_US);
        Timer1.attachInterrupt(intHandler);
    }

/*************************************
 * LOOP
*************************************/
void loop()
  {
    humidityTemperatureReport();
    // process the command we got
    if (eoc)
    {
        Serial.print("Got new command: ");
        Serial.println(line);
        debugSerial.print("Got new command: ");
        debugSerial.println(line);

        if (line.startsWith("2"))
            {
                debugSerial.println("Got Dual focuser command(?) starting with 2. Send values of first motor");
                // remove first character and parse command
                line = line.substring(1);
            }

        String cmd, param;
        int len = line.length();
        if (len >= 2)
            {
                cmd = line.substring(0, 2);
            }
        if (len > 2)
            {
                param = line.substring(2);
            }
        Serial.print(cmd);
        Serial.print(":");
        Serial.println(param);
        Serial.println(line);
        debugSerial.print(cmd);
        debugSerial.print(":");
        debugSerial.println(param);
        debugSerial.println(line);

        line = "";
        eoc = false;

        // LED backlight value, always return "00"
        if (cmd.equalsIgnoreCase("GB"))
            {
                Serial.print("00#");
            }
        // home the motor, hard-coded, ignore parameters since we only have one motor
        if (cmd.equalsIgnoreCase("PH"))
            {
                stepper.setCurrentPosition(8000);
                stepper.moveTo(0);
                isRunning = true;
            }
        // firmware value, always return "10"
        if (cmd.equalsIgnoreCase("GV"))
            {
                Serial.print("10#");
            }
        // get the current motor position
        if (cmd.equalsIgnoreCase("GP"))
            {
                currentPosition = stepper.currentPosition();
                char tempString[6];
                sprintf(tempString, "%04X", currentPosition);
                Serial.print(tempString);
                Serial.print("#");

                Serial.print("current motor position: 0x");
                Serial.print(tempString);
                Serial.print(" = ");
                Serial.println(currentPosition);
                debugSerial.print("current motor position: 0x");
                debugSerial.print(tempString);
                debugSerial.print(" = ");
                debugSerial.println(currentPosition);
            }
        // get the new motor position (target)
        if (cmd.equalsIgnoreCase("GN"))
            {
                //pos = stepper.targetPosition();
                char tempString[6];
                sprintf(tempString, "%04X", targetPosition);
                Serial.print(tempString);
                Serial.print("#");

                Serial.print("target motor position: ");
                Serial.println(tempString);
                debugSerial.print("target motor position: ");
                debugSerial.println(tempString);
            }
        // get the current temperature from DS1820 temperature sensor
        if (cmd.equalsIgnoreCase("GT"))
            {
                sensors.requestTemperatures();
                float temperature = sensors.getTempCByIndex(0);
                debugSerial.print("temperature: ");
                debugSerial.println(temperature);
                if (temperature > 100 || temperature < -50)
                    {
                        // error
                        temperature = 0;
                    }
                byte t_int = (byte)temperature << 1;
                t_int += round(temperature - (byte)temperature);
                Serial.print(t_int, HEX);
                Serial.print('#');
            }

        // get the temperature coefficient
        if (cmd.equalsIgnoreCase("GC"))
            {
                //Serial.print("02#");
                Serial.print((byte)t_coeff, HEX);
                Serial.print('#');
            }

        // set the temperature coefficient
        if (cmd.equalsIgnoreCase("SC"))
            {
            //debugSerial.println(param);
                if (param.length() > 4)
                    {
                        param = param.substring(param.length() - 4);
                    }
                debugSerial.println(param);

                if (param.startsWith("F"))
                    {
                        //debugSerial.println("negative");
                        //debugSerial.println(strtol("FFFF", NULL, 16));
                        //debugSerial.println(strtol(param.c_str(), NULL, 16));
                        t_coeff = ((0xFFFF - strtol(param.c_str(), NULL, 16)) / -2.0f) - 0.5f;
                    }
                else
                    {
                        t_coeff = strtol(param.c_str(), NULL, 16) / 2.0f;
                    }
                debugSerial.print("t_coeff: ");
                debugSerial.println(t_coeff);
                //Serial.print("02#");
            }

        // get the current motor speed, only values of 02, 04, 08, 10, 20
        if (cmd.equalsIgnoreCase("GD"))
            {
                char tempString[6];
                sprintf(tempString, "%02X", speedFactorRaw);
                Serial.print(tempString);
                Serial.print("#");

                debugSerial.print("current motor speed: ");
                debugSerial.println(tempString);
            }

        // set speed, only acceptable values are 02, 04, 08, 10, 20
        if (cmd.equalsIgnoreCase("SD"))
            {
                speedFactorRaw = hexstr2long(param);

                // SpeedFactor: smaller value means faster
                speedFactor = 32 / speedFactorRaw;
                stepper.setMaxSpeed(speedFactor * speedMult);
            }

        // whether half-step is enabled or not, always return "00"
        if (cmd.equalsIgnoreCase("GH"))
            {
                Serial.print("00#");
            }

        // motor is moving - 01 if moving, 00 otherwise
        if (cmd.equalsIgnoreCase("GI"))
            {
                if (abs(targetPosition - currentPosition) > 0)
                    {
                        Serial.print("01#");
                    }
                else
                    {
                        Serial.print("00#");
                    }
            }
        // set current motor position
        if (cmd.equalsIgnoreCase("SP"))
            {
                currentPosition = hexstr2long(param);
                stepper.setCurrentPosition(currentPosition);
            }
        // set new motor position
        if (cmd.equalsIgnoreCase("SN"))
            {
                debugSerial.print("new target position ");
                debugSerial.print(targetPosition);
                debugSerial.print(" -> ");
                targetPosition = hexstr2long(param);
                debugSerial.println(targetPosition);
                Serial.println(param);
                Serial.print("new target position ");
                Serial.print(targetPosition);
                Serial.print(" -> ");
                Serial.println(targetPosition);

                //stepper.moveTo(pos);
            }
        // initiate a move
        if (cmd.equalsIgnoreCase("FG"))
            {
                //isRunning = 1;
                //running = true;
                stepper.enableOutputs();
                stepper.moveTo(targetPosition);
            }
        // stop a move
        if (cmd.equalsIgnoreCase("FQ"))
            {
                //isRunning = 0;
                //stepper.moveTo(stepper.currentPosition());
                //stepper.run();
                //running = false;
                stepper.stop();
            }
    }

    int btn_in = digitalRead(BTN_IN);
    int btn_out = digitalRead(BTN_OUT);

    // move motor if not done
    if (stepper.distanceToGo() != 0)
        {
            isRunning = true;
            millisLastMove = millis();
        }

    // handle manual buttons
    else if (btn_in == LOW || btn_out == LOW)
        {
            stepper.enableOutputs();

            while (btn_in == LOW || btn_out == LOW)
                {
                    if (btn_in == LOW)
                        {
                            stepper.move(BTN_STEP);
                        }
                    else
                        {
                            stepper.move(-BTN_STEP);
                        }
                    stepper.runSpeedToPosition();
                    btn_in = digitalRead(BTN_IN);
                    btn_out = digitalRead(BTN_OUT);
                }
            stepper.stop();
            stepper.disableOutputs();
            millisLastMove = millis();
            currentPosition = stepper.currentPosition();
        }
    else
        {
            isRunning = false;
            if (millis() - millisLastMove > millisDisableDelay)
                {
                    // Save current location in EEPROM
                    if (lastSavedPosition != currentPosition)
                        {
                            EEPROM.put(eepromPOSOffset, currentPosition);
                            lastSavedPosition = currentPosition;
                            Serial.println("Save last position to EEPROM");
                            debugSerial.println("Save last position to EEPROM");
                        }
                    // set motor to sleep state
                    stepper.disableOutputs();
                    Serial.println("Disabled output pins");
                    debugSerial.println("Disabled output pins");
                }
        }

    digitalWrite(LED_BUILTIN, isRunning);
    //delay(20);
    }

// read the command until the terminating # character
void serialEvent() 
    {
    // read the command until the terminating # character
    while (Serial.available() && !eoc)
        {
            char c = Serial.read();
            if (c != '#' && c != ':')
                {
                    line = line + c;
                }
            else
                {
                    if (c == '#')
                        {
                            eoc = true;
                        }
                }
        }
    }

long hexstr2long(String line)
    {
        char buf[line.length() + 1];
        line.toCharArray(buf, line.length() + 1);
        return strtol(buf, NULL, 16);
    }

static void intHandler()
    {
        stepper.run();
    }
