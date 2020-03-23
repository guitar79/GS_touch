// JS's pcb
//#define PCB_1

//Kevin's PCB
#define PCB_2 

//스위치 핀 번호
#ifdef PCB_1 
  #define UPpin 8
  #define DOWNpin 9
  #define RIGHTpin 7
  #define LEFTpin 10
#endif
#ifdef PCB_2
  #define UPpin 8
  #define DOWNpin 9
  #define RIGHTpin 10
  #define LEFTpin 7
#endif

//about button switch
short S[4]={0}; short now[4]={1}; short was[4]={0};
//
int _resetPosition = 0;

//어떻게 입력이 되었나?
void controljudge(){
  now[0]=digitalRead(UPpin);
  now[1]=digitalRead(DOWNpin);
  now[2]=digitalRead(RIGHTpin);
  now[3]=digitalRead(LEFTpin);
  for(int i=0;i<4;i++)
  {
    if(now[i]!=was[i]&&now[i]==0) S[i]=1;
    else S[i]=0;
    was[i]=now[i];
  }
}

//설정된 핀번호 풀업저항으로 선언
void pinset() {
  pinMode(UPpin,INPUT_PULLUP);
  pinMode(DOWNpin,INPUT_PULLUP);
  pinMode(RIGHTpin,INPUT_PULLUP);
  pinMode(LEFTpin,INPUT_PULLUP);
}

void buttonRead(){
  controljudge();
  if(subm != 2)
    {
      if(S[2]) subm++;
      else if(S[3]) subm = 0;
      
      if(S[0]&&menu>1) menu--;
      else if(S[1]&&menu<2) menu++;
    }
  else
    {
      switch(menu)
    {
      case 1: // POSITION CONTROL
        motorControl();
        break;

      case 2: // STEPMODE SET & RESET POSITION
        MSmodeControl();
        break;
        
    }
  }
}
