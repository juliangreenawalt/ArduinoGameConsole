//All functions specific to Home Screen go here
//HS stands for Home Screen in case you were wondering

int HS_rowSelect = 0;
int HS_colSelect = 0;

void launchHomeScreen(){
  bool playing = true;
  
  initHomeScreen();
  
  while(playing){
    readInputs();
    updateHomeScreen();
  }
}

void initHomeScreen(){
  
  Serial.println("-------------------------");
  Serial.println("Welcome home");
  Serial.println("-------------------------");
  
  myGLCD.clrScr();
  myGLCD.fillScr(178, 216, 216); //LIGHT CYAN
  
  //Title
  myGLCD.setColor(0, 128, 128); //TEAL
  myGLCD.setBackColor(0, 128, 128); //TEAL
  myGLCD.fillRect(0, 0, 319, 25);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Arduino Entertainment System", CENTER, 5);

  //Headers
  myGLCD.setFont(Retro8x16);
  myGLCD.setColor(0, 120, 120); //DARK TEAL
  myGLCD.setBackColor(0, 120, 120); //DARK TEAL
  myGLCD.fillRect(0, 25, 106, 65);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.print("Games", 30, 40);
  myGLCD.setColor(0, 102, 102); //DARKER TEAL
  myGLCD.setBackColor(0, 102, 102); //DARKER TEAL
  myGLCD.fillRect(106, 25, 213, 65);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.print("Software", 127, 40);
  myGLCD.setColor(0, 76, 76); //DARKEST TEAL
  myGLCD.setBackColor(0, 76, 76); //DARKEST TEAL
  myGLCD.fillRect(213, 25, 319, 65);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.print("Tools", 250, 40);

  //Dividers
  myGLCD.setColor(255, 215, 0); //GOLD
  myGLCD.fillRect(0, 25, 319, 29);
  myGLCD.fillRect(104, 25, 108, 240);
  myGLCD.fillRect(211, 25, 215, 240);

  changeSelection();

  //TEMPORARY - Icons 50 X 50

  //Ping
  drawPingIcon(26, 90);
  //ADPaint
  drawADPaintIcon(135, 90);
  //Input Test
  drawInputTestIcon(244, 90);
  //Flappy Nerd
  drawFlappyNerdIcon(26, 160);
  //Math
  drawMathIcon(135, 160);
  //System Info
  drawSystemInfoIcon(244, 160);
}

void updateHomeScreen(){
  if(joyValX == 10 && HS_colSelect < 2){
    HS_colSelect += 1;
    changeSelection();
    delay(250);
  }
  if(joyValX == -10 && HS_colSelect > 0){
    HS_colSelect -= 1;
    changeSelection();
    delay(250);
  }
  if(joyValY == -10 && HS_rowSelect < 1){
    HS_rowSelect += 1;
    changeSelection();
    delay(250);
  }
  if(joyValY == 10 && HS_rowSelect > 0){
    HS_rowSelect -= 1;
    changeSelection();
    delay(250);
  }

  //On press of button A, corresponding app is launched - ONLY WORKS FOR FIRST ROW CURRENTLY
  if(buttonState_A == 1){
    if(HS_rowSelect == 0){
      if(HS_colSelect == 0){
        playPing();
      }
      if(HS_colSelect == 1){
        launchADPaint();
      }
      if(HS_colSelect == 2){
        openInputTest();
      }
    }
    if(HS_rowSelect == 1){
      if(HS_colSelect == 0){
        playFlappyNerd();
      }
      if(HS_colSelect == 1){
        launchMath();
      }
      if(HS_colSelect == 2){
        openSystemInfo();
      }
    }
  }
}

void changeSelection(){
  //Clear previous selection
  myGLCD.setColor(178, 216, 216); //LIGHT CYAN
  myGLCD.drawRect(25, 89, 77, 141);
  myGLCD.drawRect(24, 88, 78, 142);
  myGLCD.drawRect(23, 87, 79, 143);
  myGLCD.drawLine(14, 110, 19, 115);
  myGLCD.drawLine(14, 120, 19, 115);
  myGLCD.drawLine(13, 110, 19, 115);
  myGLCD.drawLine(13, 120, 19, 115);
  myGLCD.drawLine(12, 110, 19, 115);
  myGLCD.drawLine(12, 120, 19, 115);
  myGLCD.drawRect(134, 89, 186, 141);
  myGLCD.drawRect(133, 88, 187, 142);
  myGLCD.drawRect(132, 87, 188, 143);
  myGLCD.drawLine(123, 110, 128, 115);
  myGLCD.drawLine(123, 120, 128, 115);
  myGLCD.drawLine(122, 110, 128, 115);
  myGLCD.drawLine(122, 120, 128, 115);
  myGLCD.drawLine(121, 110, 128, 115);
  myGLCD.drawLine(121, 120, 128, 115);
  myGLCD.drawRect(243, 89, 295, 141);
  myGLCD.drawRect(242, 88, 296, 142);
  myGLCD.drawRect(241, 87, 297, 143);
  myGLCD.drawLine(232, 110, 237, 115);
  myGLCD.drawLine(232, 120, 237, 115);
  myGLCD.drawLine(231, 110, 237, 115);
  myGLCD.drawLine(231, 120, 237, 115);
  myGLCD.drawLine(230, 110, 237, 115);
  myGLCD.drawLine(230, 120, 237, 115);
  myGLCD.drawRect(25, 159, 77, 211);
  myGLCD.drawRect(24, 158, 78, 212);
  myGLCD.drawRect(23, 157, 79, 213);
  myGLCD.drawLine(14, 180, 19, 185);
  myGLCD.drawLine(14, 190, 19, 185);
  myGLCD.drawLine(13, 180, 19, 185);
  myGLCD.drawLine(13, 190, 19, 185);
  myGLCD.drawLine(12, 180, 19, 185);
  myGLCD.drawLine(12, 190, 19, 185);
  myGLCD.drawRect(134, 159, 186, 211);
  myGLCD.drawRect(133, 158, 187, 212);
  myGLCD.drawRect(132, 157, 188, 213);
  myGLCD.drawLine(123, 180, 128, 185);
  myGLCD.drawLine(123, 190, 128, 185);
  myGLCD.drawLine(122, 180, 128, 185);
  myGLCD.drawLine(122, 190, 128, 185);
  myGLCD.drawLine(121, 180, 128, 185);
  myGLCD.drawLine(121, 190, 128, 185);
  myGLCD.drawRect(243, 159, 295, 211);
  myGLCD.drawRect(242, 158, 296, 212);
  myGLCD.drawRect(241, 157, 297, 213);
  myGLCD.drawLine(232, 180, 237, 185);
  myGLCD.drawLine(232, 190, 237, 185);
  myGLCD.drawLine(231, 180, 237, 185);
  myGLCD.drawLine(231, 190, 237, 185);
  myGLCD.drawLine(230, 180, 237, 185);
  myGLCD.drawLine(230, 190, 237, 185);
  
  if(HS_rowSelect == 0){
    if(HS_colSelect == 0){
      //Ping is selected
      myGLCD.setColor(212, 175, 55); //METALLIC GOLD
      myGLCD.drawRect(25, 89, 77, 141);
      myGLCD.drawRect(24, 88, 78, 142);
      myGLCD.drawRect(23, 87, 79, 143);
      myGLCD.drawLine(14, 110, 19, 115);
      myGLCD.drawLine(14, 120, 19, 115);
      myGLCD.drawLine(13, 110, 19, 115);
      myGLCD.drawLine(13, 120, 19, 115);
      myGLCD.drawLine(12, 110, 19, 115);
      myGLCD.drawLine(12, 120, 19, 115);
    }
    if(HS_colSelect == 1){
      //Paint is selected
      myGLCD.setColor(212, 175, 55); //METALLIC GOLD
      myGLCD.drawRect(134, 89, 186, 141);
      myGLCD.drawRect(133, 88, 187, 142);
      myGLCD.drawRect(132, 87, 188, 143);
      myGLCD.drawLine(123, 110, 128, 115);
      myGLCD.drawLine(123, 120, 128, 115);
      myGLCD.drawLine(122, 110, 128, 115);
      myGLCD.drawLine(122, 120, 128, 115);
      myGLCD.drawLine(121, 110, 128, 115);
      myGLCD.drawLine(121, 120, 128, 115);
    }
    if(HS_colSelect == 2){
      //Input Test is selected
      myGLCD.setColor(212, 175, 55); //METALLIC GOLD
      myGLCD.drawRect(243, 89, 295, 141);
      myGLCD.drawRect(242, 88, 296, 142);
      myGLCD.drawRect(241, 87, 297, 143);
      myGLCD.drawLine(232, 110, 237, 115);
      myGLCD.drawLine(232, 120, 237, 115);
      myGLCD.drawLine(231, 110, 237, 115);
      myGLCD.drawLine(231, 120, 237, 115);
      myGLCD.drawLine(230, 110, 237, 115);
      myGLCD.drawLine(230, 120, 237, 115);
    }
  }
  if(HS_rowSelect == 1){
    if(HS_colSelect == 0){
      //Flappy Nerd is selected
      myGLCD.setColor(212, 175, 55); //METALLIC GOLD
      myGLCD.drawRect(25, 159, 77, 211);
      myGLCD.drawRect(24, 158, 78, 212);
      myGLCD.drawRect(23, 157, 79, 213);
      myGLCD.drawLine(14, 180, 19, 185);
      myGLCD.drawLine(14, 190, 19, 185);
      myGLCD.drawLine(13, 180, 19, 185);
      myGLCD.drawLine(13, 190, 19, 185);
      myGLCD.drawLine(12, 180, 19, 185);
      myGLCD.drawLine(12, 190, 19, 185);
    }
    if(HS_colSelect == 1){
      //Math is selected
      myGLCD.setColor(212, 175, 55); //METALLIC GOLD
      myGLCD.drawRect(134, 159, 186, 211);
      myGLCD.drawRect(133, 158, 187, 212);
      myGLCD.drawRect(132, 157, 188, 213);
      myGLCD.drawLine(123, 180, 128, 185);
      myGLCD.drawLine(123, 190, 128, 185);
      myGLCD.drawLine(122, 180, 128, 185);
      myGLCD.drawLine(122, 190, 128, 185);
      myGLCD.drawLine(121, 180, 128, 185);
      myGLCD.drawLine(121, 190, 128, 185);
    }
    if(HS_colSelect == 2){
      //System Info is selected
      myGLCD.setColor(212, 175, 55); //METALLIC GOLD
      myGLCD.drawRect(243, 159, 295, 211);
      myGLCD.drawRect(242, 158, 296, 212);
      myGLCD.drawRect(241, 157, 297, 213);
      myGLCD.drawLine(232, 180, 237, 185);
      myGLCD.drawLine(232, 190, 237, 185);
      myGLCD.drawLine(231, 180, 237, 185);
      myGLCD.drawLine(231, 190, 237, 185);
      myGLCD.drawLine(230, 180, 237, 185);
      myGLCD.drawLine(230, 190, 237, 185);
    }
  }
}

void drawPingIcon(int x, int y){
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(x, y, x + 50, y + 50);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillRect(x + 11, y + 35, x + 39, y + 40);
  myGLCD.drawLine(x + 4, y + 13, x + 25, y + 34);
  myGLCD.drawLine(x + 25, y + 34, x + 39, y + 22);
  myGLCD.fillCircle(x + 39, y + 22, 5);
  myGLCD.setFont(TRONFont);
  myGLCD.setBackColor(0, 0, 0); //BLACK
  myGLCD.print("Ping", x + 9, y + 2);
}

void drawADPaintIcon(int x, int y){
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(x, y, x + 50, y + 50);
  myGLCD.setColor(255, 0, 0); //RED
  myGLCD.fillRect(x, y + 35, x + 16, y + 50);
  myGLCD.setColor(0, 255, 0); //GREEN
  myGLCD.fillRect(x + 17, y + 35, x + 33, y + 50);
  myGLCD.setColor(0, 0, 255); //BLUE
  myGLCD.fillRect(x + 34, y + 35, x + 50, y + 50);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.setFont(SmallFont);
  myGLCD.print("Paint", x + 7, y + 10);
}

void drawInputTestIcon(int x, int y){
  myGLCD.setColor(255, 105, 180); //HOT PINK
  myGLCD.fillRect(x, y, x + 50, y + 50);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(x + 3, y + 3, x + 47, y + 47);
  myGLCD.setColor(255, 105, 180); //HOT PINK
  myGLCD.setFont(SmallFont);
  myGLCD.print("Input", x + 6, y + 10);
  myGLCD.print("Test", x + 10, y + 25);
}

void drawFlappyNerdIcon(int x, int y){
  myGLCD.setColor(210, 180, 140); //TAN
  myGLCD.fillRect(x, y, x + 50, y + 50);
  myGLCD.setColor(101, 67, 33); //DARK BROWN
  myGLCD.fillRect(x, y, x + 50, y + 10);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillCircle(x + 14, y + 22, 10);
  myGLCD.fillCircle(x + 36, y + 22, 10);
  myGLCD.drawLine(x + 14, y + 22, x + 36, y + 22);
  myGLCD.drawLine(x, y + 18, x + 4, y + 20);
  myGLCD.drawLine(x + 50, y + 18, x + 46, y + 20);
  myGLCD.drawLine(x + 14, y + 38, x + 36, y + 38);
  myGLCD.fillRect(x + 19, y + 38, x + 31, y + 45);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillCircle(x + 14, y + 22, 8);
  myGLCD.fillCircle(x + 36, y + 22, 8);
  myGLCD.fillRect(x + 20, y + 39, x + 24, y + 44);
  myGLCD.fillRect(x + 26, y + 39, x + 30, y + 44);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.setBackColor(255, 255, 255); //WHITE
  myGLCD.setFont(SmallFont);
  myGLCD.print("F", x + 12, y + 17);
  myGLCD.print("N", x + 34, y + 17);
}

void drawMathIcon(int x, int y){
  myGLCD.setColor(255, 0, 0); //RED
  myGLCD.fillRect(x, y, x + 50, y + 50);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(x + 3, y + 3, x + 47, y + 47);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillRect(x + 8, y + 13, x + 22, y + 15);
  myGLCD.fillRect(x + 14, y + 8, x + 16, y + 21);
  myGLCD.fillRect(x + 28, y + 13, x + 41, y + 15);
  myGLCD.setBackColor(0, 0, 0); //BLACK
  myGLCD.setFont(SmallFont);
  myGLCD.print("Math", x + 11, y + 30);
}

void drawSystemInfoIcon(int x, int y){
  myGLCD.setColor(0, 255, 0); //GREEN
  myGLCD.fillRect(x, y, x + 50, y + 50);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(x + 3, y + 3, x + 47, y + 47);
  myGLCD.setColor(0, 255, 0); //GREEN
  myGLCD.setBackColor(0, 0, 0); //BLACK
  myGLCD.setFont(SmallFont);
  myGLCD.print("Sys.", x + 11, y + 10);
  myGLCD.print("Info", x + 10, y + 25);
}

void launch(int id){
  //Might do this a different way...
}
