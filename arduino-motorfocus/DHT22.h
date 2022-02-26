
/** * for DHT routine */
// ----------------------------------------------------------------
// for the temperature and hubmidity sensor
#include <DHT_U.h>
#include <DHT.h>
#define DHT22_PIN 2
#define DHTTYPE DHT22
DHT dht(DHT22_PIN, DHTTYPE);
int chkSensor;
String Temperature;
String Humidity;
// ----------------------------------------------------------------

void humidityTemperatureReport() 
  {
    chkSensor = digitalRead(DHT22_PIN);
    Temperature = String(dht.readTemperature(),1);
    Humidity = String(dht.readHumidity(),1);
    switch (chkSensor) {
      case 1:
        Serial.print("TEMPERATURE:");
        Serial.print(Temperature);
        Serial.println("#");
        delay(50);
        Serial.print("HUMIDITY:");
        Serial.print(Humidity);
        Serial.println("#");
        delay(50);
        break;
      case 0:
        Serial.print("TEMPERATURE:");
        Serial.print("CHECKSUMERROR");
        Serial.println("#");
        Serial.print("HUMIDITY:");
        Serial.print("CHECKSUMERROR");
        Serial.println("#");
        break;
      default:
        Serial.print("TEMPERATURE:");
        Serial.print("UNKNOWNERROR");
        Serial.println("#");
        Serial.print("HUMIDITY:");
        Serial.print("UNKNOWNERROR");
        Serial.println("#");
        break;
    }
  }
