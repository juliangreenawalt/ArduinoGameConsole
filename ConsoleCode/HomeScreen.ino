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
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(26, 90, 76, 140);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillRect(37, 125, 65, 130);
  myGLCD.drawLine(30, 103, 51, 124);
  myGLCD.drawLine(51, 124, 65, 112);
  myGLCD.fillCircle(65, 112, 5);
  myGLCD.setFont(TRONFont);
  myGLCD.setBackColor(0, 0, 0); //BLACK
  myGLCD.print("Ping", 35, 92);
  //ADPaint
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(135, 90, 185, 140);
  myGLCD.setColor(255, 0, 0); //RED
  myGLCD.fillRect(135, 125, 151, 140);
  myGLCD.setColor(0, 255, 0); //GREEN
  myGLCD.fillRect(152, 125, 168, 140);
  myGLCD.setColor(0, 0, 255); //BLUE
  myGLCD.fillRect(169, 125, 185, 140);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.setFont(SmallFont);
  myGLCD.print("Paint", 142, 100);
  //Input Test
  myGLCD.setColor(255, 105, 180); //HOT PINK
  myGLCD.fillRect(244, 90, 294, 140);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(247, 93, 291, 137);
  myGLCD.setColor(255, 105, 180); //HOT PINK
  myGLCD.print("Input", 250, 100);
  myGLCD.print("Test", 254, 115);
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

  //On press of button A, corresponding app is launched
  if(buttonState_A == 1){
    if(HS_colSelect == 0){
      playPing();
    }
    if(HS_colSelect == 1){
      playPing();
    }
    if(HS_colSelect == 2){
      playInputTest();
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

void launch(int id){
  //Might do this a different way...
}
