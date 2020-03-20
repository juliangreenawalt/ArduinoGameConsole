//All functions specific to Flappy Board go here

void playFlappyBoard(){
  bool playing = true;
  
  initFlappyBoard();
  
  while(playing){
    //Anything in here happens every frame
  }
}

void initFlappyBoard(){
  
  Serial.println("-------------------------");
  Serial.println("Welcome to Flappy Board");
  Serial.println("-------------------------");
  
  myGLCD.clrScr();
}
