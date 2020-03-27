//All functions specific to ADPaint go here

void launchADPaint(){
  bool playing = true;
  
  initADPaint();
  
  while(playing){
    readInputs();
    updateADPaint();
  }
}

void initADPaint(){
  myGLCD.clrScr();
}

void updateADPaint(){
  if(screenPressed){
    //some stuff will probably happen
  }
}
