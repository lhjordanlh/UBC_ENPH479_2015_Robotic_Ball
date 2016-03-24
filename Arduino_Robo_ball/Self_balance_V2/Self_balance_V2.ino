#include <Servo.h> 
#define x_pin A0    // select the input pin for the x_pin
#define y_pin A1
#define z_pin A2
int x_acc = 0;    // select the input pin for the potentiometer
int y_acc= 0;
int z_acc= 0;
const int x_ref= 300;
const int y_ref= 300;
const int z_ref= 61;
int ref_angle =50;
int angle =0;
int pos = 90;
int ref_pos=0;
int command_angle= 50;
double e = 0.0;
double e_last = 0.0;
double ep = 0.0;
double ei = 0.0;
double ed = 0.0;
int u = 0;

float kp = 5.0;
double ki = 0.18;
double kd = 6.0;

Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards 
                
char command;
 
void setup() 
{ 
  Serial.begin(9600);
  myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);
} 
void loop() 
{ 
  e_last= e;
  // read the values from the sensors:
  y_acc = analogRead(y_pin);
  z_acc = analogRead(z_pin);
  x_acc = analogRead(x_pin);
  for (int i=0; i<5; i++){
    y_acc += analogRead(y_pin);
    x_acc += analogRead(x_pin);
    z_acc = analogRead(z_pin);
  }
  x_acc /= 6;
  y_acc /= 6;
  z_acc /= 6;
  //////////////////////////////////////
  
  if(Serial.available()>0){
    command= Serial.read();
  }
  
  ref_angle=command_angle;
  if(command=='j'){
     ref_angle=command_angle;
    if(command_angle>100 || command_angle<0){
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
    myservo.write(pos);
  }
  else{
    if(command=='q'){kp+=0.1;}
    else if(command== 'w'){kp-=0.1;}
    else if(command== 'a'){ki+=0.01;}
    else if(command== 's'){ki-=0.01;}
    else if(command== 'z'){kd+=0.01;}
    else if(command== 'x'){kd-=0.01;}
    else if(command== 'o'){command_angle+=1;command='j';}
    else if(command== 'p'){command_angle-=1; command='j';}
    if(command=='q' || command=='w' || command=='a' || command=='s'|| command=='z' || command=='x'|| command=='o' || command=='p'){
      Serial.print("ref_angle= "); Serial.println(ref_angle);
      Serial.print("ref_pos= "); Serial.println(ref_pos);
      Serial.print("command_angle= "); Serial.println(command_angle);
      //Serial.print("x_acc= "); Serial.println(x_acc);
      //e=0.0;
      //e_last=0.0;
      //ei=0;
      myservo.write(0);
     // command='k';
    }
  }   

/*  
  //Control Algorithm
  angle= (z_acc-z_ref)*9;
  e= ref_angle- angle;
  ed = e_last-e;
  ei+= e;
  u= e*kp+ ei*ki + ed*kd;
  //u= e*kp;
  pos = ref_pos - u;
  if(pos > 160){pos=160;}
  else if(pos<20){pos=20;}
  myservo.write(pos);
  //////////////////////////////////////
  */
/*
if(Serial.available()>0){
    Serial.print("y: ");
    Serial.println(y_acc);
    Serial.print("x: ");
    Serial.println(x_acc);
    Serial.print("z: ");
    Serial.println(z_acc);
    z_acc=Serial.read();
  }
    angle= ((x_ref-x_acc)/144.0)*180.0;
  angle_d =abs(angle-angle_l);
  // Modify the acceleration to angle
  if( angle_d>1){
    myservo.write(angle);              
    angle_l=angle;
  }
*/
}
