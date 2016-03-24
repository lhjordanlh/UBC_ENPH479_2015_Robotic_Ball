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
const int x_ref= 305;
const int y_ref= 305;
const int z_ref= 61;
int angle_command =0;
int angle =0;
int pos = 90;
int ref_pos=0;
double e = 0.0;
double e_last = 0.0;
double ep = 0.0;
double ei = 0.0;
double ed = 0.0;
int u = 0;

float kp = 5.0;
double ki = 0.18;
double kd = 6.0;

Servo ESC;  // create servo object to control the ESC 
Servo servo; // The servo is used for turning

byte start_byte;
int vel;
int val;

int ref_angle;
                
void setup() {
  Serial.begin(9600);
  servo.attach(6);
  servo.write(pos);
  ESC.attach(7);
  ESC.write(20);
}

void loop() {
  // The following code read the command from bluetooth chip
  while(Serial.available()>=3){       // if data is available to read
    start_byte=Serial.read();
    if(start_byte == 255){
      val = Serial.read();      
      angle_command = Serial.read();
      //Serial.write(val);
    }
  }  
  //////////////////////////////////////////////////////////////////////

  // Read the accelerometer value
    y_acc = analogRead(y_pin);
    //z_acc = analogRead(z_pin);
    x_acc = analogRead(x_pin);
  //take the average to get a more stable reading
  for (int i=0; i<5; i++){
    y_acc += analogRead(y_pin);
    x_acc += analogRead(x_pin);
  }
   x_acc /= 6;
   y_acc /= 6;
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
        if(val>1){val--;}
        ESC.write(vel);
        //balance(angle_command);
    }else{
      // all is good
      vel= (2*val)+38;
      ESC.write(vel);
      Serial.write(vel);
      //balance(angle_command);
      //////
            ///////
      /*ref_angle=angle_command;
      
      if(angle_command>100 || angle_command<0){
        ref_angle=0;
        ref_pos= 0;
      }else{
        ref_pos= ref_angle-50;
        ref_angle= ref_angle-50;
        ref_angle= ref_angle/10;
      }
      
      ref_pos= ref_pos+90;
      
      angle= (z_acc-z_ref);
      e = ref_angle- angle;
      ed = e_last-e;
      ei += e;
      u= e*kp- ei*ki + ed*kd;
      pos = ref_pos + u; //(was -)
      if(pos > 160){pos=160;}
      else if(pos<20){pos=20;}
      servo.write(pos);*/
                ///////
      ////////
    }
  }else{
    //if none of the above, stop the motor and angle back to neutral
    ESC.write(40);
    //servo.write(90);
  }
}

//Function that takes the angle command from the UI and compute what is needed for the angle turning.
void balance(int ref_angle){
    if(ref_angle>100 || ref_angle<0){
      ref_angle=0;
      ref_pos= 0;
    }else{
      ref_pos= ref_angle-50;
      ref_angle= ref_angle-50;
      ref_angle= ref_angle/10;
    }
    ref_pos= ref_pos+90;
    
    angle= (z_acc-z_ref);
    e = ref_angle- angle;
    ed = e_last-e;
    ei += e;
    u= e*kp- ei*ki + ed*kd;
    pos = ref_pos + u; //(was -)
    if(pos > 160){pos=160;}
    else if(pos<20){pos=20;}
    servo.write(pos);
}
