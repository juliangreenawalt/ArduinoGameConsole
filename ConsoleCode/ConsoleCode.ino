//This is where the code for the functionality of the console goes
#include <UTFT.h> 
#include <URTouch.h>
#include <EEPROM.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

//Sets up display
UTFT myGLCD(ILI9341_16,38,39,40,41); 

//Set up touch screen
URTouch myTouch(6, 5, 4, 3, 2);

//Set up audio 
static const uint8_t PIN_MP3_RX = 13;
static const uint8_t PIN_MP3_TX = 12;
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);
DFRobotDFPlayerMini player;

//Defining Fonts
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
extern uint8_t arial_normal[];
extern uint8_t arial_bold[];
extern uint8_t TRONFont[];
extern uint8_t Retro8x16[];
extern uint8_t battery_24x48[];

//Touch Screen
int pressX, pressY = 0;
bool screenPressed = false;

//Joystick Variables
const int joyPinX = A0;
const int joyPinY = A1;
int joyValX = -1;
int joyValY = -1;

//Button Variables
const int button_A = 8;
const int button_B = 9;
const int button_HOME = 10;
const int button_MENU = 11;
int buttonState_A = 0;
int buttonState_B = 0;
int buttonState_HOME = 0;
int buttonState_MENU = 0;

//Volume Knob Variables
const int knobPin = A2;
int knobVal = 0;
int oldKnobVal = 0;
int vol = 0;

void setup() {
  //Starts serial monitor
  Serial.begin(9600);

  //Initializes Display
  myGLCD.InitLCD();

  //Initializes audio player
  softwareSerial.begin(9600);
  if(player.begin(softwareSerial)){
    Serial.println("Audio Setup Successful");
  } else {
    Serial.println("Audio Setup Failed");
  }

  //TEMPORARY - Sets volume to max
  player.volume(30);
  
  //Initializes touch screen
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  //Sets up pins
  pinMode(joyPinX, INPUT);
  pinMode(joyPinY, INPUT);
  pinMode(button_A, INPUT);
  pinMode(button_B, INPUT);
  pinMode(button_HOME, INPUT);
  pinMode(button_MENU, INPUT);

  //TEMPORARY - launches Input Test
  playInputTest();
}

void loop() {
  //Reads inputs
  readInputs();
}

void readInputs(){
  //Read Joystick
  joyValX = analogRead(joyPinX);
  joyValY = analogRead(joyPinY);
  //Converts to a number between -10 and 10
  //joyValX = joyValX / (joyValX / 20) * -1 + 10;
  //joyValY = joyValY - 10;
  
  //Read Buttons
  buttonState_A = digitalRead(button_A);
  buttonState_B = digitalRead(button_B);
  buttonState_HOME = digitalRead(button_HOME);
  buttonState_MENU = digitalRead(button_MENU);

  //Read Touch
  if(myTouch.dataAvailable()){
    myTouch.read();
    pressX = myTouch.getX();
    pressY = myTouch.getY();
    screenPressed = true;
  } else {
    screenPressed = false;
  }

  //Read Volume Knob
  knobVal = analogRead(knobPin);
  vol = knobVal / 33; //Number between 0 and 30
  if(vol != oldKnobVal / 33){ //This prevents unnecesary static with some speakers. Only sets volume when it changes.
    player.volume(vol);
  }
  oldKnobVal = knobVal;
}
