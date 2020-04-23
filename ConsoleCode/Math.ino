//All functions specific to Math go here

void launchMath(){
  bool playing = true;
  
  initMath();
  
  while(playing){
    readInputs();
  }
}

void initMath(){
  
  Serial.println("-------------------------");
  Serial.println("Welcome to Math");
  Serial.println("-------------------------");
  
  myGLCD.clrScr();
}
