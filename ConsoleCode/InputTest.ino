//All functions specific to Input Test go here

void playInputTest(){
  bool playing = true;
  
  initInputTest();
  
  while(playing){
    //Anything in here happens every frame
    readInputs();
    updateInputTest();
  }
}

//Draws initial screen
void initInputTest(){
  //Clears anything on the screen
  myGLCD.clrScr();

  //Sets text color to white
  myGLCD.setColor(255, 255, 255); //WHITE
  
  //Title
  myGLCD.setBackColor(0, 0, 255); //BLUE
  myGLCD.setFont(BigFont);
  myGLCD.print("AES Input Test", CENTER, 1);
  myGLCD.setBackColor(0, 0, 0); //BLACK

  //Joystick section
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Joystick:", 50, 50);
  myGLCD.setFont(SmallFont);
  myGLCD.print("X =", 50, 80);
  myGLCD.print("Y =", 50, 100);
  myGLCD.drawRect(40, 40, 130, 120);

  //Button Section
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Buttons:", 200, 50);
  myGLCD.setFont(SmallFont);
  myGLCD.print("A =", 200, 80);
  myGLCD.print("B =", 200, 100);
  myGLCD.print("HOME =", 200, 120);
  myGLCD.print("START =", 200, 140);
  myGLCD.drawRect(190, 40, 270, 157);

  //Touch screen section
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Touch Screen:", 50, 160);
  myGLCD.setColor(255, 0, 0); //RED
  myGLCD.fillCircle(97, 230, 5);
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.print("Last Touch", 60, 185);
  myGLCD.drawRect(40, 150, 160, 239);

  //Audio Section
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Audio:", 200, 180);
  myGLCD.setColor(180, 180, 180); //SILVER/GRAY
  myGLCD.fillRect(200, 200, 260, 230);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.drawRect(200, 200, 260, 230);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.setFont(SmallFont);
  myGLCD.setBackColor(180, 180, 180); //SILVER/GRAY
  myGLCD.print("PRESS", 210, 210);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.drawRect(190, 170, 270, 238);
  myGLCD.setColor(255, 0, 255); //PURPLE
  myGLCD.drawRect(250, 176, 263, 195);
}

void updateInputTest(){
  //This ensures that anything below what is being printed will be erased - Must be same a background color - This doesn't work for values that lose and gain digits or characters.
  myGLCD.setBackColor(0, 0, 0); //BLACK
  myGLCD.setFont(SmallFont);

  //JOYSTICK:
  //Clears old values
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(80, 80, 110, 110);
  //Prints new values
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.print(String(joyValX), 80, 80);
  myGLCD.print(String(joyValY), 80, 100);

  //BUTTONS:
  //Button inputs will always be 1 digit so no additional clearing method is needed.
  myGLCD.print(String(buttonState_A), 230, 80);
  myGLCD.print(String(buttonState_B), 230, 100);
  myGLCD.print(String(buttonState_HOME), 255, 120);
  myGLCD.print(String(buttonState_START), 260, 140);

  //TOUCH SCREEN:
  if(screenPressed){
    myGLCD.setColor(0, 255, 0); //GREEN
    myGLCD.fillCircle(97, 230, 5);
    //Erase previous value
    myGLCD.setColor(0, 0, 0); //BLACK
    myGLCD.fillRect(60, 205, 140, 215);
  } else {
    myGLCD.setColor(255, 0, 0); //RED
    myGLCD.fillCircle(97, 230, 5);
  }
  myGLCD.setFont(SmallFont);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.print("(" + String(pressX) + ", " + String(pressY) + ")", 60, 205);

  //AUDIO:
  if(screenPressed){
    if((pressX >= 200) && (pressX <= 260) && (pressY >= 200) && (pressY <= 260)){
      myGLCD.setColor(255, 255, 0); //YELLOW
      myGLCD.drawRect(200, 200, 260, 230);
      player.play(1); //Test_Audio
    }
  } else {
    myGLCD.setColor(255, 255, 255); //WHITE
    myGLCD.drawRect(200, 200, 260, 230);
  }
  //Updates volume level bar
  for(int i = 0; i < 15; i++){
    if(i < vol /  2){
      myGLCD.setColor(255, 182, 193); //PINK
      myGLCD.drawLine(252, 193 - i, 261, 193 - i);
    } else {
      myGLCD.setColor(0, 0, 0); //BLACK
      myGLCD.drawLine(252, 193 - i, 261, 193 - i);
    }
  }
}
