
char start_byte;
char num;
char angle;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>=3){       // if data is available to read
    Serial.print("Serial Buffer Size: ");
    Serial.println(Serial.available());
    start_byte=Serial.read();
    if(start_byte == '0'){
      num = Serial.read();         // read it and store it in 'val'
      angle = Serial.read();
      Serial.print("num is ");
      Serial.println(num);
      Serial.print("angle is ");
      Serial.println(angle);
      Serial.print("Serial Buffer Size: ");
      Serial.println(Serial.available());
      if(Serial.available()>0){
        start_byte=Serial.read();
        Serial.print("Start byte is ");
        Serial.println(start_byte);
      }
    }
  }
}
