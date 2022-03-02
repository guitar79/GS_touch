void sensorDHT22Report() 
    {
        chkSensor = digitalRead(DHT22_PIN);
        switch (chkSensor) 
            {
                case 1:
                    // Reading temperature or humidity takes about 250 milliseconds!
                    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
                    float h = dht.readHumidity();
                    // Read temperature as Celsius (the default)
                    float t = dht.readTemperature();
                    // Read temperature as Fahrenheit (isFahrenheit = true)
                    float f = dht.readTemperature(true);

                    // Check if any reads failed and exit early (to try again).
                    if (isnan(h) || isnan(t) || isnan(f)) 
                        {
                            Serial.println(F("Failed to read from DHT sensor!"));
                            return;
                        }

                    // Compute heat index in Fahrenheit (the default)
                    float hif = dht.computeHeatIndex(f, h);
                    // Compute heat index in Celsius (isFahreheit = false)
                    float hic = dht.computeHeatIndex(t, h, false);

                    Serial.print(F("Humidity: "));
                    Serial.print(h);
                    Serial.print(F("%  Temperature: "));
                    Serial.print(t);
                    Serial.print(F("°C "));
                    Serial.print(f);
                    Serial.print(F("°F  Heat index: "));
                    Serial.print(hic);
                    Serial.print(F("°C "));
                    Serial.print(hif);
                    Serial.println(F("°F"));
                    break;
                case 0:
                    Serial.println("DHT22: CHECKSUMERROR");
                    break;
                default:
                    Serial.println("DHT22: UNKNOWNERROR");
                    break;
            }
    }


/** * for DHT routine */
void humidityTemperatureReport() 
  {
    extern String Temperature;
    extern String Humidity;
    extern int chkSensor;
    chkSensor = digitalRead(DHT22_PIN);
    Temperature =  String(dht.readTemperature(),1);
    Humidity = String(dht.readHumidity(),1);
    switch (chkSensor) {
      case 1:
        Serial.print("TEMPERATURE:");
        Serial.print(Temperature);
        Serial.println("*");
        delay(50);
        Serial.print("HUMIDITY:");
        Serial.print(Humidity);
        Serial.println("*");
        delay(50);
        break;
      case 0:
        Serial.print("TEMPERATURE:");
        Serial.print("CHECKSUMERROR");
        Serial.println("*");
        Serial.print("HUMIDITY:");
        Serial.print("CHECKSUMERROR");
        Serial.println("#");
        break;
      default:
        Serial.print("TEMPERATURE:");
        Serial.print("UNKNOWNERROR");
        Serial.println("*");
        Serial.print("HUMIDITY:");
        Serial.print("UNKNOWNERROR");
        Serial.println("*");
        break;
    }
  }
