//All functions specific to Ping go here

void playPing(){
  bool playing = true;
  
  initPing();
  
  while(playing){
    readInputs();
  }
}

void initPing(){
  
  Serial.println("----------------");
  Serial.println("Welcome to Ping");
  Serial.println("----------------");
  
  myGLCD.clrScr();
}
