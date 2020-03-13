/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: Paul Breton
 * Date: 3-March-2020
 */

#include <OneButton.h> // .h = header file; OneButton can be between <> (orange) or "" (green)
                       // go to Sketch, Include library, manage libraries, type in file, select and install
                       // #include <.h> allows access to the object orientated library
                       // when we did Tools-Board Teensy 3.2 it pulled in all the code library for the Teensy
                       
// Setup OneButton on pin 23
OneButton button1(23, false); // OneButton is the object, button1 is the name ,pin 23 is the address 
// Create variables buttonState and flash

 int buttonState = LOW;
 int flash = LOW;
 int greenLed = 5;


void setup() {

// Setup Serial Monitor
   pinMode(greenLed, OUTPUT);
   Serial.begin(9600);
   while (!Serial);
// Link oneButton library to functions click1, doubleclick1, longPressStart1
   button1.attachClick(click1); // attachclick calls up a function in the OneButton library
   button1.attachDoubleClick(doubleclick1); 
  /* button1.attachLongPressStart(longPressStart1);
   button1.attachLongPressStop(longPressStop1);*/
   button1.setClickTicks(250);               //tick knows the difference in clicks
   button1.setPressTicks(2500);

   if(Serial) Serial.println("Starting OneButton...");

} 

void loop() {
  // keep watching the push buttons:
  button1.tick();
} // loop


// ----- button 1 callback functions
/*
// This function will be called when the button1 was pressed 1 time.
void click1() {                     //click1 togles a button state variable
//change and print buttonState
  Serial.println("Button 1 click.");
  buttonState = !buttonState;       // this is the actual command, button is press or not pressed
  Serial.print("buttonState = ");   // this tells it what to do; print to the monitor
  Serial.println(buttonState);      // this tells it what to print
  
  if (buttonState == LOW){
  digitalWrite(greenLed, LOW);}
  else 
{
  digitalWrite(greenLed, HIGH);
  }
} // click1 */


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
// change state of flash and print
  Serial.println("Button 1 doubleclick.");
  flash = !flash;             //command to flash or not flash
  Serial.print("flash = ");
  Serial.println(flash);
  buttonState = !buttonState;
  if(buttonState == LOW){
    digitalWrite(greenLed, HIGH);
   else
    digitalWrite(greenLed, HIGH);
    delay(1000);
    digitalWrite(greenLed, LOW);
    delay(1000);}
  
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
/*void longPressStart1() {
  Serial.println("Button 1 longPress start");
// print longPress
} // longPressStart1


// This function will be called upon often, while the button is pressed for a long time.
void longPress1(){
  Serial.println("Button 1 longPress");
  }


// This function will be called once, when the button is released after being pressed for a long time.
void longPressStop1() {
  Serial.println("Button 1 longPress stop");
} //longPressStop1*/
