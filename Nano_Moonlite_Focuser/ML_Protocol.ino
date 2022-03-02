// Moonlite-compatible stepper controller
//
// Uses AccelStepper (http://www.airspayce.com/mikem/arduino/AccelStepper/)
//1  2 3 4 5 6 7 8
//: C #             N/A         Initiate a temperature conversion; the conversion process takes a maximum of 750 milliseconds. The value returned by the :GT# command will not be valid until the conversion process completes.
//: F G #           N/A         Go to the new position as set by the ":SNYYYY#" command.
//: F Q #           N/A         Immediately stop any focus motor movement.
//: G C #           XX#         Returns the temperature coefficient where XX is a two-digit signed (2’s complement) hex number.
//: G D #           XX#         Returns the current stepping delay where XX is a two-digit unsigned hex number. See the :SD# command for a list of possible return values.
//: G H #           00# OR FF#  Returns "FF#" if the focus motor is half-stepped otherwise return "00#"
//: G I #           00# OR 01#  Returns "00#" if the focus motor is not moving, otherwise return "01#"
//: G N #           YYYY#         Returns the new position previously set by a ":SNYYYY" command where YYYY is a four-digit unsigned hex number.
//: G P #           YYYY#         Returns the current position where YYYY is a four-digit unsigned hex number.
//: G T #           YYYY#         Returns the current temperature where YYYY is a four-digit signed (2’s complement) hex number.
//: G V #           DD#         Get the version of the firmware as a two-digit decimal number where the first digit is the major version number, and the second digit is the minor version number.
//: S C X X #       N/A         Set the new temperature coefficient where XX is a two-digit, signed (2’s complement) hex number.
//: S D X X #       N/A         Set the new stepping delay where XX is a two-digit, unsigned hex number. Valid values to send are 02, 04, 08, 10 and 20, which correspond to a stepping delay of 250, 125, 63, 32 and 16 steps per second respectively.
//: S F #           N/A         Set full-step mode.
//: S H #           N/A         Set half-step mode.
//: S N Y Y Y Y #   N/A         Set the new position where YYYY is a four-digit unsigned hex number.
//: S P Y Y Y Y #   N/A         Set the current position where YYYY is a four-digit unsigned hex number.
//: + #             N/A         Activate temperature compensation focusing.
//: - #             N/A         Disable temperature compensation focusing.
//: P O X X #       N/A         Temperature calibration offset, XX is a two-digit signed hex number, in half degree increments.
//:     Y       M       #                                               N/A             Enhance temperature reading (0.125 degree)
//:     Y       B       X       X       #                               N/A             Set backlash where XX is a two-digit unsigned hex number
//:     Z       B       #                                               XX#             Get backlash
//:     Y       T       Y       Y       Y       Y       #               N/A             Set max steps where YYYY is a four-digit unsigned hex number
//:     Z       T       #                                               YYYY#           Get max steps
//:     Y       X       X       X       #                               N/A             Set TempComp threshold where XX is a two-digit unsigned hex number in unit of 0.25 degree
//:     Z       X       #                                               XX#             Get TempComp threshold
//: Y       + #           N/A         Activate temperature compensation focusing.
//: Y       - #           N/A         Disable temperature compensation focusing.
//: Z       + #           00 or 01#       Get temperature compensation.
//: Z A #           YYYY#         Returns the average temperature * 100 where YYYY is a four-digit signed (2’s complement) hex number.
//Example 1: :PO02# offset of +1°C
//Example 2: :POFB# offset of -2.5°C


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
