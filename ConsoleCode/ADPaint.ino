//All functions specific to ADPaint go here

typedef struct{
  int r;
  int g;
  int b;
} rgbColor;

//Sets initial colors - Change this to change available colors.
rgbColor colors[10] = {
    {255, 0, 0}, //RED
    {0, 255, 0}, //GREEN
    {0, 0, 255}, //BLUE
    {255, 165, 0}, //ORANGE
    {255, 255, 0}, //YELLOW
    {128, 0, 128}, //PURPLE
    {165, 42, 42}, //BROWN
    {255, 192, 203}, //PINK
    {255, 255, 255}, //WHITE
    {0, 0, 0} //BLACK
  };

rgbColor currentColor;

int ADPaint_brushSize;

void launchADPaint(){
  bool playing = true;

  //Reset variables
  ADPaint_brushSize = 4;
  
  initADPaint();
  
  while(playing){
    readInputs();
    updateADPaint();
  }
}

void initADPaint(){
  myGLCD.clrScr();

  //Draw color options at bottom
  for(int i = 0; i < 10; i++){
    myGLCD.setColor(colors[i].r, colors[i].g, colors[i].b);
    myGLCD.fillRect(i * 32 - 1, myGLCD.getDisplayYSize() - 21, (i + 1) * 32 -1, myGLCD.getDisplayYSize() - 1);
  }
}

void updateADPaint(){
  while(screenPressed){
    readInputs();
    currentColor = colors[5];
    myGLCD.setColor(currentColor.r, currentColor.g, currentColor.b);
    myGLCD.fillCircle(pressX, pressY, ADPaint_brushSize);
  }
}
