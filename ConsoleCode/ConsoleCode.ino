//This is where the code for the functionality of the console goes
#include <UTFT.h> 
#include <URTouch.h>
#include <EEPROM.h>

//Sets up display
UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);

//Defining Fonts
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];

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

void setup() {
  //Starts serial monitor
  Serial.begin(9600);

  //Initializes Display
  myGLCD.InitLCD();

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
  //Divider to make serial monitor easier to read
  Serial.println("------------------------------------------");
  
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

  //Print inputs to serial monitor
  Serial.print("Joystick X: ");
  Serial.println(joyValX);
  Serial.print("Joystick Y: ");
  Serial.println(joyValY);

  Serial.print("A Button: ");
  Serial.println(buttonState_A);
  Serial.print("B Button: ");
  Serial.println(buttonState_B);
  Serial.print("HOME Button: ");
  Serial.println(buttonState_HOME);
  Serial.print("MENU Button: ");
  Serial.println(buttonState_MENU);
}
