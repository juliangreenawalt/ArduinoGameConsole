//This is where the code for the functionality of the console goes
#include <UTFT.h> 
#include <URTouch.h>
#include <EEPROM.h>

//Sets up display
UTFT myGLCD(ILI9341_16, 38, 39, 40, 41);

const int knobPin = A0;
int knobVal = -1;


void setup() {
  //Starts serial monitor
  Serial.begin(9600);

  //Sets up pins
  pinMode(knobPin, INPUT);
}

void loop() {
  //Reads inputs
  readInputs();
  
}

void readInputs(){
  //Read knob
  knobVal = analogRead(A0);
  Serial.print("Knob Value: ");
  Serial.println(knobVal);

  //Read Joystick
  
}
