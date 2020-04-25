//All functions specific to Flappy Board go here

int FN_playerX;
int FN_playerY;

void playFlappyNerd(){
  bool playing = true;
  
  initFlappyNerd();
  
  while(playing){
    readInputs();
  }
}

void initFlappyNerd(){ 
  myGLCD.clrScr();

  myGLCD.fillScr(69, 179, 244); //SKY BLUE
  drawFlappyNerd(50, 80);
  myGLCD.setColor(101, 67, 33); //DARK BROWN
  myGLCD.fillRect(0, 239, 319, 220);
  myGLCD.setColor(0, 100, 0); //DARK GREEN
  myGLCD.fillRect(0, 220, 319, 210);
}

void drawFlappyNerd(int x, int y){
  myGLCD.setColor(210, 180, 140); //TAN
  myGLCD.fillRect(x, y, x + 30, y + 30);
  myGLCD.setColor(101, 67, 33); //DARK BROWN
  myGLCD.fillRect(x, y, x + 30, y + 6);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillCircle(x + 8, y + 13, 6);
  myGLCD.fillCircle(x + 22, y + 13, 6);
  myGLCD.drawLine(x + 14, y + 13, x + 18, y + 13);
  myGLCD.drawLine(x, y + 10, x + 4, y + 12);
  myGLCD.drawLine(x + 30, y + 10, x + 28, y + 12);
  myGLCD.drawLine(x + 8, y + 22, x + 22, y + 22);
  myGLCD.fillRect(x + 11, y + 22, x + 20, y + 27);
  myGLCD.setColor(192, 192, 192); //SILVER
  myGLCD.fillCircle(x + 8, y + 13, 5);
  myGLCD.fillCircle(x + 22, y + 13, 5);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillRect(x + 12, y + 23, x + 14, y + 26);
  myGLCD.fillRect(x + 16, y + 23, x + 19, y + 26);
}

void drawPillar(int x, int y){
  //Draw the pillar obstacle
}
