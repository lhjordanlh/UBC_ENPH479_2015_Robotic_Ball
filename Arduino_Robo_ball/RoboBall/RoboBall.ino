/*
 Name: Robotic Ball Control Firmware
 Arthor: Jordan (Yodan) Karyanto
 Date (Last Modified): 2015 Dec 27th
 Description: This is the firmware code that runs the robotic ball
 Institute & Course: University of British Columbia Engineering Physic ENPH 479 project
*/
#include <Servo.h>
//Declare all variables
#define x_pin A0    // select the input pin for the x_pin
#define y_pin A1
#define z_pin A2
int ledPin = 13;      // select the pin for the LED
int x_acc = 0;    // select the input pin for the potentiometer
int y_acc= 0;
int z_acc= 0;

Servo ESC;  // create servo object to control the ESC 
Servo servo; // The servo is used for turning

char num;
float val;
int vel;
                
void setup() {
  Serial.begin(9600);
  servo.attach(6);
  ESC.attach(7);
}

void loop() {
  // The following code read the command from bluetooth chip
  if( Serial.available() )       // if data is available to read
  {;}
  num = Serial.read();         // read it and store it in 'val'
    
  vel=num-'0'; // turns the char into integer
  val=vel; // turns the integer into float
  
  // Read the accelerometer value
    y_acc = analogRead(y_pin);
    z_acc = analogRead(z_pin);
    x_acc = analogRead(x_pin);
  //take the average to get a more stable reading
  for (int i=0; i<10; i++){
    y_acc += analogRead(y_pin);
    x_acc += analogRead(x_pin);
  }
    x_acc /= 11;
    y_acc /= 11;
      
  if(y_acc>400){
    vel= 40;
    ESC.write(vel);
  }else if(val<=10 && val>=0){
     vel= (val/9)*120;
     //Serial.println(val);
     //Serial.println(vel);
     //delay(1000);  
     ESC.write(vel);
     Serial.println(y_acc);
     Serial.println(vel);
  }
}
