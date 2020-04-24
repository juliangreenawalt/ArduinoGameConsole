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
  myGLCD.fillRect(x, y, x + 50, y + 50);
  myGLCD.setColor(101, 67, 33); //DARK BROWN
  myGLCD.fillRect(x, y, x + 50, y + 10);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.fillCircle(x + 14, y + 22, 10);
  myGLCD.fillCircle(x + 36, y + 22, 10);
  myGLCD.drawLine(x + 14, y + 22, x + 36, y + 22);
  myGLCD.drawLine(x, y + 18, x + 4, y + 20);
  myGLCD.drawLine(x + 50, y + 18, x + 46, y + 20);
  myGLCD.drawLine(x + 14, y + 38, x + 36, y + 38);
  myGLCD.fillRect(x + 19, y + 38, x + 31, y + 45);
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.fillCircle(x + 14, y + 22, 8);
  myGLCD.fillCircle(x + 36, y + 22, 8);
  myGLCD.fillRect(x + 20, y + 39, x + 24, y + 44);
  myGLCD.fillRect(x + 26, y + 39, x + 30, y + 44);
  myGLCD.setColor(0, 0, 0); //BLACK
  myGLCD.setBackColor(255, 255, 255); //WHITE
  myGLCD.setFont(SmallFont);
  myGLCD.print("F", x + 12, y + 17);
  myGLCD.print("N", x + 34, y + 17);
}

void drawPillar(int x, int y){
  //Draw the pillar obstacle
}
