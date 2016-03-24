#include <Servo.h> 
#define x_pin A0    // select the input pin for the x_pin
#define y_pin A1
#define z_pin A2
int x_acc = 0;    // select the input pin for the potentiometer
int y_acc= 0;
int z_acc= 0;
float x_ref= 300;
float y_ref= 300;
float z_ref= 33;
int angle= 0; 
int angle_l=0;
int angle_d=0;

Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards 
                
int pos = 1;    // variable to store the servo position 
char command;
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  command= '0';

  if(Serial.available()>0){
    command= Serial.read();
  }
  if(command=='j'){
    if(pos<179){pos++;}
    Serial.println(pos);
  }
  else if(command=='k'){
    if(pos>1){pos--;}
    Serial.println(pos);
  }
  myservo.write(pos);
/*
  angle= ((x_ref-x_acc)/144.0)*180.0;
  angle_d =abs(angle-angle_l);
  // Modify the acceleration to angle
  if( angle_d>1){
    myservo.write(angle);              // tell servo to go to position in variable 'pos' 
    angle_l=angle;
  }
  */
} 

