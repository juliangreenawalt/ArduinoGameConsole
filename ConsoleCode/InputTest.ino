//All functions specific to Input Test go here

void playInputTest(){
  bool playing = true;
  
  initInputTest();
  
  while(playing){
    //Anything in here happens every frame
    readInputs();
    Serial.println("Playing Input Test");
    delay(1000);
  }
}

void initInputTest(){
  
  Serial.println("-------------------------");
  Serial.println("Welcome to the input test");
  Serial.println("-------------------------");

  //Draws initial screen vvv

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
  myGLCD.setFont(SmallFont);
  myGLCD.print("Joystick:", 10, 50);
}
