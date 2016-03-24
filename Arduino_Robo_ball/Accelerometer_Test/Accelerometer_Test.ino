int x_pin = A0;    // select the input pin for the potentiometer
int y_pin= A1;
int z_pin= A2;
int ledPin = 13;      // select the pin for the LED
int x_acc = 0;    // select the input pin for the potentiometer
int y_acc= 0;
int z_acc= 0;
  //float x_ref= 427;
float x_ref= 354;
float y_ref= 355;
float z_ref= 294;
float angle= 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensors:
  y_acc = analogRead(y_pin);
  z_acc = analogRead(z_pin);
  x_acc = analogRead(x_pin);
  for (int i=0; i<10; i++){
    x_acc += analogRead(x_pin);
  }
  x_acc /= 11;
    //angle= ((x_ref-x_acc)/144.0)*180.0;
  angle= ((x_ref-x_acc)/71.0)*90.0;
  // Modify the acceleration to angle
  // output the value to serial port:
  Serial.print("Angle: ");
  Serial.println(angle);
  Serial.print("Y_acceleration: ");
  Serial.println(y_acc);
  Serial.print("Z_acceleration: ");
  Serial.println(z_acc);
  Serial.println();
  delay(500);
}
