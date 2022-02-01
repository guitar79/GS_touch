int ct=0;
int pt=0;

void motorControl(){
  int stp = 0;
  switch(power)
  {
    case 1: stp=1; break;
    case 2: stp=10; break;
    case 3: stp=30; break;
    case 4: stp=100; break;
    case 5: stp=300; break;
    case 6: stp=1000; break;
  }
  if(!now[0]||!now[1])
  {
    int _nextPosition = stepper.currentPosition();
    if(!now[0]) _nextPosition += stp;
    else _nextPosition -= stp;
      if(_nextPosition != stepper.currentPosition())
      {
        stepper.moveTo(_nextPosition);
        stepper.runToPosition();
      }
  }
  else
  {
    if(S[2] && power<5) power++;
    else if(S[3] && power>1) power--;
    else if(S[3]) subm=0;
    stepper.setSpeed(300*stp);
  }
}

void MSmodeControl(){
  
  if(S[0] && stepmode<4 && !rm) stepmode++;
  else if(S[1] && stepmode>1 && !rm) stepmode--;

  if(S[0] && _resetPosition < 500000 && rm==1) _resetPosition = (_resetPosition+100)/100*100;
  else if(S[1] && _resetPosition > 0 && rm==1) _resetPosition = (_resetPosition-100)/100*100;
  
  if(S[2] && rm != 2) rm++;
  else if(S[2] && rm==2) 
    {
      rm--; subm=0;
      stepper.setCurrentPosition(_resetPosition); // reset position setting
      _resetPosition = 0;
      
      setMicrostep(); //microstepping setting
    }

  else if(S[3] && !rm) subm--;
  else if(S[3] && rm) rm--;
}
