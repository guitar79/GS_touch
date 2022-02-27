// https://roboticsbackend.com/arduino-write-string-in-eeprom/
// ----------------------------------------------------------------
#include <EEPROM.h>

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



void checkFWEEPROM() 
    {   
        extern String firmwareName;
        extern String firmwareVer  ;
        extern String firmwareDate ;
        extern String SerialNo     ;
        
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
        extern int eepromFIRMOffset ;
        
        // Reading
        String eepfirmwareName;
        String eepfirmwareVer;
        String eepfirmwareDate;
        String eepSerialNo;

        int newStr1AddrOffset = readStringFromEEPROM(eepromFIRMOffset, &eepfirmwareName);
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
        
        //check firmware
        if (firmwareName == eepfirmwareName && firmwareVer == eepfirmwareVer && firmwareDate == eepfirmwareDate && SerialNo == eepSerialNo)
            {
                Serial.println("Firmware is same...");
            }
        else 
            {
                Serial.println("Firmware is defferent...");
                Serial.println("EEPRom is updating now...");
                int str1AddrOffset = writeStringToEEPROM(eepromFIRMOffset, firmwareName);
                int str2AddrOffset = writeStringToEEPROM(str1AddrOffset, firmwareVer);
                int str3AddrOffset = writeStringToEEPROM(str2AddrOffset, firmwareDate);
                writeStringToEEPROM(str3AddrOffset, SerialNo);
            }
        delay(20);
    }