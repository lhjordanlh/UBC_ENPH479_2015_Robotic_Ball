#include <Servo.h>

Servo ESC;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards 
char num;
float val;
int vel;
                
void setup() {
  Serial.begin(9600);
  ESC.attach(9);
}

void loop() {
  if( Serial.available() )       // if data is available to read
  {;}
    num = Serial.read();         // read it and store it in 'val'
  
   vel=num-'0';
   val=vel;
   
  if(val<=10 && val>=0){
     vel= (val/9)*120;
     Serial.println(val);
     Serial.println(vel);
     delay(1000);  
     ESC.write(vel);
  }
}
