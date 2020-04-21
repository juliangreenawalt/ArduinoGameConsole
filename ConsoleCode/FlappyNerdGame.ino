//All functions specific to Flappy Board go here

void playFlappyNerd(){
  bool playing = true;
  
  initFlappyNerd();
  
  while(playing){
    readInputs();
  }
}

void initFlappyNerd(){
  
  Serial.println("-------------------------");
  Serial.println("Welcome to Flappy Nerd");
  Serial.println("-------------------------");
  
  myGLCD.clrScr();
}
