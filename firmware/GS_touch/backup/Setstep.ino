void setstep()
  {
    switch(stepmode)
    {
      case 1:    //full step
      digitalWrite(MS0,LOW);
      digitalWrite(MS1,LOW);
      digitalWrite(MS2,LOW);
        break;  
        
      case 2:    //half step
      digitalWrite(MS0,HIGH);
      digitalWrite(MS1,LOW);
      digitalWrite(MS2,LOW);
        break;
        
      case 3:    // 4 microstep
      digitalWrite(MS0,LOW);
      digitalWrite(MS1,HIGH);
      digitalWrite(MS2,LOW);
        break;
        
      case 4:   // 8 microstep
      digitalWrite(MS0,HIGH);
      digitalWrite(MS1,HIGH);
      digitalWrite(MS2,LOW);
        break;

      case 5:   // 16 microstep
      digitalWrite(MS0,LOW);
      digitalWrite(MS1,LOW);
      digitalWrite(MS2,HIGH);
        break;

      case 6:   // 32 microstep
      digitalWrite(MS0,HIGH);
      digitalWrite(MS1,LOW);
      digitalWrite(MS2,HIGH);
        break;


      default:
      Serial.println("Microstepping mode should be from 1 to 6");
    }
        Serial.print("Microstepping mode:"); Serial.print(stepmode);
}
