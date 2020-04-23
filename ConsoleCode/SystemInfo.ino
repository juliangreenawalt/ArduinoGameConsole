//All functions specific to Flappy Board go here

void openSystemInfo(){
  bool playing = true;
  
  initSystemInfo();
  
  while(playing){
    readInputs();
  }
}

void initSystemInfo(){
  
  Serial.println("-------------------------");
  Serial.println("Welcome to System Info");
  Serial.println("-------------------------");
  
  myGLCD.clrScr();
}
