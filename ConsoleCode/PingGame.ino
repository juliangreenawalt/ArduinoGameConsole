//All functions specific to Ping go here

void playPing(){
  bool playing = true;
  
  initPing();
  
  while(playing){
    //Anything in here happens every frame
  }
}

void initPing(){
  
  Serial.println("----------------");
  Serial.println("Welcome to Ping");
  Serial.println("----------------");
  
  myGLCD.clrScr();
}
