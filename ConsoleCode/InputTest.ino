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
  
  Serial.println("-------------------------");
  Serial.println("Welcome to the input test");
  Serial.println("-------------------------");

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
  myGLCD.print("MENU =", 200, 140);
  myGLCD.drawRect(190, 40, 270, 165);

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
  myGLCD.print(String(buttonState_MENU), 255, 140);

  //TOUCH SCREEN
  if(myTouch.dataAvailable()){
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
}
