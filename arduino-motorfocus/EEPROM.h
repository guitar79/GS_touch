// https://roboticsbackend.com/arduino-write-string-in-eeprom/

// ----------------------------------------------------------------
// for the EEPROM
#include <EEPROM.h>
// ----------------------------------------------------------------

int writeStringToEEPROM(int addrOffset, const String &strToWrite)
    {
        byte len = strToWrite.length();
        EEPROM.write(addrOffset, len);
        for (int i = 0; i < len; i++)
            {
                EEPROM.write(addrOffset + 1 + i, strToWrite[i]);
            }
        return addrOffset + 1 + len;
    }
    

int readStringFromEEPROM(int addrOffset, String *strToRead)
    {
        int newStrLen = EEPROM.read(addrOffset);
        char data[newStrLen + 1];
        for (int i = 0; i < newStrLen; i++)
            {
                data[i] = EEPROM.read(addrOffset + 1 + i);
            }
        data[newStrLen] = '\0'; // !!! NOTE !!! Remove the space between the slash "/" and "0" (I've added a space because otherwise there is a display bug)
        *strToRead = String(data);
        return addrOffset + 1 + newStrLen;
    }

/*
String readStringFromEEPROM(int addrOffset)
{
  int newStrLen = EEPROM.read(addrOffset);
  char data[newStrLen + 1];
  for (int i = 0; i < newStrLen; i++)
  {
    data[i] = EEPROM.read(addrOffset + 1 + i);
  }
  data[newStrLen] = '\ 0'; // !!! NOTE !!! Remove the space between the slash "/" and "0" (I've added a space because otherwise there is a display bug)
  return String(data);
}
*/


void checkFWEEPROM() 
    {   
        String firmwareName = "GS_touch";
        //unsigned long now = now()
        String firmwareVer  = "0.89";
        String firmwareDate = "2022-02-26";
        String SerialNo     = "GS_T000001";

        Serial.print("Current firmware: ");
        Serial.print(firmwareName);
        Serial.print(" ");
        Serial.print(firmwareVer);
        Serial.print(" ");
        Serial.println(firmwareDate);
        Serial.print("Current Serial No: ");
        Serial.println(SerialNo);
    
        //EEPROM
        Serial.println("Read float from EEPROM...");
        int eepromOffset = 0;
        
        // Reading
        String eepfirmwareName;
        String eepfirmwareVer;
        String eepfirmwareDate;
        String eepSerialNo;

        int newStr1AddrOffset = readStringFromEEPROM(eepromOffset, &eepfirmwareName);
        int newStr2AddrOffset = readStringFromEEPROM(newStr1AddrOffset, &eepfirmwareVer);
        int newStr3AddrOffset = readStringFromEEPROM(newStr2AddrOffset, &eepfirmwareDate);
        readStringFromEEPROM(newStr3AddrOffset, &eepSerialNo);
    
        Serial.print("EEPRom firmware: ");
        Serial.print(eepfirmwareName);
        Serial.print(" ");
        Serial.print(eepfirmwareVer);
        Serial.print(" ");
        Serial.println(eepfirmwareDate);
        Serial.print("EEPRom Serial No: ");
        Serial.println(eepSerialNo); 
        if (firmwareName == eepfirmwareName && firmwareVer == eepfirmwareVer && firmwareDate == eepfirmwareDate && SerialNo == eepSerialNo)
            {
                Serial.println("Firmware is same...");
            }
        else 
            {
                Serial.println("EEPRom is update...");
                int str1AddrOffset = writeStringToEEPROM(eepromOffset, firmwareName);
                int str2AddrOffset = writeStringToEEPROM(str1AddrOffset, firmwareVer);
                int str3AddrOffset = writeStringToEEPROM(str2AddrOffset, firmwareDate);
                writeStringToEEPROM(str3AddrOffset, SerialNo);
            }
        delay(20);
    }