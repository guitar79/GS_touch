//https://github.com/olikraus/u8glib/wiki/fontsize
//https://github.com/olikraus/u8glib/wiki/userreference#setprintpos

#include <U8glib.h>
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 
//U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST);

void U8G_start()
  {
    u8g.setFont(u8g_font_5x8);
    u8g.setColorIndex(1);
    u8g.setFontPosTop();

    //draw();
  }

void draw()
  {
    Serial.println(subm);
    u8g.firstPage();   
    do {
      u8g.setFont(u8g_font_5x8);
      //u8g.setFontPosTop(); u8g.drawStr(0,0,"A");
      u8g.setFontPosBottom();
      
      u8g.drawStr(-1,26,"TEMP : "); 
        u8g.setPrintPos(34,26);
        u8g.print(Temperature);
        u8g.drawStr(55,26,"\xb0");
        u8g.drawStr(60,26,"C");
        
      u8g.drawStr(70,26,"HUM : "); 
        u8g.setPrintPos(100,26);
        u8g.print(Humidity);
        u8g.drawStr(120,26,"%");

        if(subm!=2 || menu!=1) {
      u8g.drawStr(0,35,"POSITION : "); 
        u8g.setPrintPos(55,35); 
        u8g.print(stepper.currentPosition());
        }
        switch(subm)
        {
          case 0:
          u8g.setFont(u8g_font_unifont); u8g.setFontPosTop();
            u8g.drawStr(40,0,"STATUS"); 
            u8g.drawStr(8,36,"MSMODE : ");
              u8g.setPrintPos(80,36);
              u8g.print(stepmode);
              
              if(PCMODE) u8g.drawStr(8,50,"PCMODE : ON");
              else u8g.drawStr(8,50,"PCMODE : OFF");
          break;

          case 1:
          u8g.setFont(u8g_font_unifont); u8g.setFontPosTop();
            u8g.drawStr(48,0,"MENU");   
            u8g.drawStr(8,36,"MOTOR CONTROL");
            u8g.drawStr(8,50,"MOTOR SETTING");
            
            u8g.drawStr(0,22+14*menu, ">");
          break;
              
          case 2:
            {
              switch(menu)
              {
                case 1:
                u8g.setFont(u8g_font_unifont); u8g.setFontPosTop();
                  u8g.drawStr(0,0,"POSITION CONTROL");
                  u8g.drawStr(8,36,"POS : ");
                    u8g.setPrintPos(56,36);
                    u8g.print(stepper.currentPosition());
                  u8g.drawStr(8,50,"POWER : ");
                    u8g.setPrintPos(72,50);
                    u8g.print(power);
                u8g.setFont(u8g_font_5x8);
                  u8g.drawStr(0,35,"Micorstepping mode : ");
                    u8g.setPrintPos(105,35);
                    u8g.print(stepmode);
                break;

                case 2:
                u8g.setFont(u8g_font_unifont); u8g.setFontPosTop();
                  u8g.drawStr(4,0,"STEPMODE CHANGE");
                u8g.setFont(u8g_font_5x8);
                  u8g.drawStr(10,44,"STEPMODE : ");
                    u8g.setPrintPos(65,44);
                    u8g.print(stepmode);
                  u8g.drawStr(10,54,"POSITION TO : ");
                    u8g.setPrintPos(80,54);
                    u8g.print(_resetPosition);
                  u8g.drawStr(10,64,"APPLY SETTINGS");
                  u8g.drawStr(0,44+rm*10,">");
                break;

              }
            }

          break;
        }
        
    } while( u8g.nextPage() ); 
}
