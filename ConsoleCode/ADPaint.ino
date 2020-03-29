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
    myGLCD.fillRect(i * (myGLCD.getDisplayXSize() / 10) - 1, myGLCD.getDisplayYSize() - 21, (i + 1) * (myGLCD.getDisplayXSize() / 10) - 1, myGLCD.getDisplayYSize() - 1);
  }

  //Draw divider above colors
  myGLCD.setColor(255, 255, 255); //WHITE
  myGLCD.drawLine(0, myGLCD.getDisplayYSize() - 31, myGLCD.getDisplayXSize() - 1, myGLCD.getDisplayYSize() - 31);

  //Draw inital arrow
  myGLCD.drawLine(0, myGLCD.getDisplayYSize() - 30, (myGLCD.getDisplayXSize() / 10 / 2), myGLCD.getDisplayYSize() - 22);
  myGLCD.drawLine((myGLCD.getDisplayXSize() / 10) - 1, myGLCD.getDisplayYSize() - 30, (myGLCD.getDisplayXSize() / 10 / 2), myGLCD.getDisplayYSize() - 22);
  
  //Set starting color
  currentColor = colors[0];
  myGLCD.setColor(currentColor.r, currentColor.g, currentColor.b);
}

void updateADPaint(){
  if(screenPressed){
    if(pressY > myGLCD.getDisplayYSize() - 22){ //If a color at the bottom is pressed
      //Clear indicator arrow
      myGLCD.setColor(0, 0, 0); //BLACK
      myGLCD.fillRect(0, myGLCD.getDisplayYSize() - 30, myGLCD.getDisplayXSize() - 1, myGLCD.getDisplayYSize() - 22);
      //Draw new indicator arrow. Got this first try btw :)
      myGLCD.setColor(255, 255, 255); //WHITE
      myGLCD.drawLine((myGLCD.getDisplayXSize() / 10) * (pressX * 10 / myGLCD.getDisplayXSize()), myGLCD.getDisplayYSize() - 30, (myGLCD.getDisplayXSize() / 10) * (pressX * 10 / myGLCD.getDisplayXSize()) + (myGLCD.getDisplayXSize() / 10 / 2), myGLCD.getDisplayYSize() - 22);
      myGLCD.drawLine((myGLCD.getDisplayXSize() / 10) * (pressX * 10 / myGLCD.getDisplayXSize()) + (myGLCD.getDisplayXSize() / 10) - 1, myGLCD.getDisplayYSize() - 30, (myGLCD.getDisplayXSize() / 10) * (pressX * 10 / myGLCD.getDisplayXSize()) + (myGLCD.getDisplayXSize() / 10 / 2), myGLCD.getDisplayYSize() - 22);
      //Set new color
      currentColor = colors[pressX * 10 / myGLCD.getDisplayXSize()]; //Makes number between 0 and 9 based on press
      myGLCD.setColor(currentColor.r, currentColor.g, currentColor.b);
    }
    else if(pressY < myGLCD.getDisplayYSize() - 31 - ADPaint_brushSize)
    myGLCD.fillCircle(pressX, pressY, ADPaint_brushSize);
  }
}
