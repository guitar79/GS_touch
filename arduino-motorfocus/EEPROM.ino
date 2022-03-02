// ----------------------------------------------------------------
// https://roboticsbackend.com/arduino-write-string-in-eeprom/
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
        extern String firmName;
        extern String firmVer  ;
        extern String firmDate ;
        extern String SerialNo  ;

        Serial.print("Current firmware: ");
        Serial.print(firmName);
        Serial.print(" ");
        Serial.print(firmVer);
        Serial.print(" ");
        Serial.println(firmDate);
        Serial.print("Current Serial No: ");
        Serial.println(SerialNo);
    
        //EEPROM
        Serial.println("Read float from EEPROM...");
        extern int eepromFIRMOffset ;
        
        // Reading
        String eepfirmName;
        String eepfirmVer;
        String eepfirmDate;
        String eepSerialNo;

        int newStr1AddrOffset = readStringFromEEPROM(eepromFIRMOffset, &eepfirmName);
        int newStr2AddrOffset = readStringFromEEPROM(newStr1AddrOffset, &eepfirmVer);
        int newStr3AddrOffset = readStringFromEEPROM(newStr2AddrOffset, &eepfirmDate);
        readStringFromEEPROM(newStr3AddrOffset, &eepSerialNo);
    
        Serial.print("EEPRom firmware: ");
        Serial.print(eepfirmName);
        Serial.print(" ");
        Serial.print(eepfirmVer);
        Serial.print(" ");
        Serial.println(eepfirmDate);
        Serial.print("EEPRom Serial No: ");
        Serial.println(eepSerialNo); 
        
        //check firmware
        if (firmName == eepfirmName && firmVer == eepfirmVer && firmDate == eepfirmDate && SerialNo == eepSerialNo)
            {
                Serial.println("Firmware is same...");
            }
        else 
            {
                Serial.println("Firmware is defferent...");
                Serial.println("EEPRom is updating now...");
                int str1AddrOffset = writeStringToEEPROM(eepromFIRMOffset, firmName);
                int str2AddrOffset = writeStringToEEPROM(str1AddrOffset, firmVer);
                int str3AddrOffset = writeStringToEEPROM(str2AddrOffset, firmDate);
                writeStringToEEPROM(str3AddrOffset, SerialNo);
            }
        delay(20);
    }

// ----------------------------------------------------------------


/*---------------------------------------------------------
extern String cipherkey  ;
void EEPROMWriteInt(int p_address, unsigned int p_value) 
    {
        byte lByte = ((p_value >> 0) & 0xFF);
        byte hByte = ((p_value >> 8) & 0xFF);
        
        EEPROM.update(p_address, lByte);
        EEPROM.update(p_address + 1, hByte);
    }

unsigned int EEPROMReadInt(int p_address) 
    {
        byte lByte = EEPROM.read(p_address);
        byte hByte = EEPROM.read(p_address + 1);
        
        return ((lByte << 0) & 0xFF) + ((hByte << 8) & 0xFF00);
    }

void EEPROMWriteLong(int p_address, unsigned long p_value) 
    {
        byte b0 = ((p_value >> 0) & 0xFF);
        byte b1 = ((p_value >> 8) & 0xFF);
        byte b2 = ((p_value >> 16) & 0xFF);
        byte b3 = ((p_value >> 24) & 0xFF);
        
        
        EEPROM.update(p_address, b0);
        EEPROM.update(p_address + 1, b1);
        EEPROM.update(p_address + 2, b2);
        EEPROM.update(p_address + 3, b3);
    }

unsigned long EEPROMReadLong(int p_address) 
    {
        byte b0 = EEPROM.read(p_address);
        byte b1 = EEPROM.read(p_address + 1);
        byte b2 = EEPROM.read(p_address + 2);
        byte b3 = EEPROM.read(p_address + 3);
        
        
        return (((unsigned long)b0 << 0) & 0xFF) + (((unsigned long)b1 << 8) & 0xFF00) + (((unsigned long)b2 << 16) & 0xFF0000) + (((unsigned long)b3 << 24) & 0xFF000000);
    }

void writeSerialNo(unsigned int srno) {
  unsigned int srno_encoded = srno ^ cipherKey;
  unsigned int srno_chksum = (srno<<8 | srno>>8) ^ cipherKey ^ cipherKey ^ cipherKey;
  EEPROMWriteInt(14, srno_encoded);
  EEPROMWriteInt(16, srno_chksum);
}

unsigned int readSerialNo() {
  unsigned int srno = EEPROMReadInt(14);
  unsigned int srno_chksum = EEPROMReadInt(16);
  unsigned int chksum_decoded = srno_chksum ^ cipherKey ^ cipherKey ^ cipherKey;
  chksum_decoded = (chksum_decoded<<8 | chksum_decoded>>8);
  srno = srno ^ cipherKey;
  if (srno != chksum_decoded) {
    Serial.println(F("Mem corrupt"));
    delay(1000);
    return 9999;
  }
  return srno;
}
------------------------------------------------------------------------------------------*/
