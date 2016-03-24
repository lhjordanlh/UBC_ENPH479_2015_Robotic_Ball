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

int x_acc = 0;
int y_acc= 0;
int z_acc= 0;
const int x_ref= 300;
const int y_ref= 300;
const int z_ref= 33;
int angle = 0;
int ref_angle = 0;
double e = 0.0;
double e_last = 0.0;
double ep = 0.0;
double ei = 0.0;
double ed = 0.0;
int u = 0;

float kp = 3;
double ki = 0.1;
double kd = 0.01;

Servo ESC;  // create servo object to control the ESC 
Servo servo; // The servo is used for turning

byte start_byte;
int vel;
int val;
                
void setup() {
  Serial.begin(9600);
  servo.attach(6);
  ESC.attach(7);
  ESC.write(40);
}

void loop() {
  // The following code read the command from bluetooth chip
  while(Serial.available()>=3){       // if data is available to read
    start_byte=Serial.read();
    if(start_byte == 255){
      val = Serial.read();      
      angle = Serial.read();
      //Serial.write(val);
    }
  }  
  //////////////////////////////////////////////////////////////////////

  // Read the accelerometer value
    y_acc = analogRead(y_pin);
    //z_acc = analogRead(z_pin);
    x_acc = analogRead(x_pin);
  //take the average to get a more stable reading
  for (int i=0; i<10; i++){
    y_acc += analogRead(y_pin);
    x_acc += analogRead(x_pin);
  }
   x_acc /= 11;
   y_acc /= 11;
  ///////////////////////////////////////////////////////////////////
      
  //Check if motor going too fast
  if(y_acc>380){
    //if go too fast, stop the motor and angle back to neutral
      ESC.write(40);
      servo.write(90);
  }else if(val<=40 && val>=1){
    //only execute when the val is reasonable
    //if go too fast, stop the motor and angle back to neutral
    if(y_acc >355 && val>35){
      //if command is making the acceleration too fast
        if(vel>40){vel--;}
        ESC.write(vel);
        balance(angle);
    }else{
      // all is good
      vel= (2*val)+38;
      ESC.write(vel);
      Serial.write(vel);
      balance(angle);
    }
  }else{
    //if none of the above, stop the motor and angle back to neutral
    ESC.write(40);
    servo.write(90);
  }
}

//Function that takes the angle command from the UI and compute what is needed for the angle turning.
void balance(int angle){
  if (angle<=50 && angle>0){
    angle= -angle;
  }else if(angle>100 || angle<0){
    angle=0;
  }
  angle=90+angle;
  servo.write(angle);
}
