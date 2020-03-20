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
  myGLCD.setBackColor(255, 0, 0); //RED
  myGLCD.setFont(BigFont);
  myGLCD.print("AES Input Test", CENTER, 1);
  myGLCD.setBackColor(0, 0, 0); //BLACK

  //Joystick section
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Joystick:", 20, 50);
  myGLCD.setFont(SmallFont);
  myGLCD.print("X =", 20, 80);
  myGLCD.print("Y =", 20, 100);

  //Button Section
  myGLCD.setFont(Retro8x16);
  myGLCD.print("Buttons:", 200, 50);
  myGLCD.setFont(SmallFont);
  myGLCD.print("A =", 200, 80);
  myGLCD.print("B =", 200, 100);
  myGLCD.print("HOME =", 200, 120);
  myGLCD.print("MENU =", 200, 140);
}

void updateInputTest(){
  //This ensures that anything below what is being printed will be erased - Must be same a background color - This doesn't work for things with variable lengths
  myGLCD.setBackColor(0, 0, 0); //BLACK
  myGLCD.setFont(SmallFont);

  //JOYSTICK:
  //Clears old values
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillRect(50, 80, 80, 110);
  //Prints Values
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.print(String(joyValX), 50, 80);
  myGLCD.print(String(joyValY), 50, 100);

  //BUTTONS:
  //Button inputs will always be 1 digit so no additional clearing method is needed.
  myGLCD.print(String(buttonState_A), 230, 80);
  myGLCD.print(String(buttonState_B), 230, 100);
  myGLCD.print(String(buttonState_HOME), 255, 120);
  myGLCD.print(String(buttonState_MENU), 255, 140);
}
