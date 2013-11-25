int rightWheelPort1 = 8;
int rightWheelPort2 = 7;
int rightVelocity = 9;

int leftWheelPort1 = 13;
int leftWheelPort2 = 12;
int leftVelocity = 5;
 

void setup() {                
  pinMode(rightWheelPort1, OUTPUT);
  pinMode(rightWheelPort2, OUTPUT); 
  pinMode(rightVelocity, OUTPUT); 
  
  pinMode(leftWheelPort1, OUTPUT); 
  pinMode(leftWheelPort2, OUTPUT); 
  pinMode(leftVelocity, OUTPUT); 
  fastWalk();
}


void loop() {
 back(); 
 front();
 left();
 right();
 stoppedMotor();
}


void front(){
 digitalWrite(leftWheelPort1,LOW); 
 digitalWrite(leftWheelPort2,HIGH); 
 digitalWrite(rightWheelPort1,LOW); 
 digitalWrite(rightWheelPort2,HIGH);
 delay(3000);
}

void back(){
  digitalWrite(leftWheelPort1,HIGH); 
  digitalWrite(leftWheelPort2,LOW); 
  digitalWrite(rightWheelPort1,HIGH); 
  digitalWrite(rightWheelPort2,LOW);
  delay(1000);
  stoppedMotor();
}

void  left(){
 digitalWrite(leftWheelPort1,HIGH); 
 digitalWrite(leftWheelPort2,LOW);
 digitalWrite(rightWheelPort1,LOW);
 digitalWrite(rightWheelPort2,LOW);
 delay(3000);
 stoppedMotor();
}

void  right(){
 digitalWrite(leftWheelPort1,LOW); 
 digitalWrite(leftWheelPort2,LOW);
 digitalWrite(rightWheelPort1,HIGH);
 digitalWrite(rightWheelPort2,LOW);
 delay(3000);
}

void stoppedMotor(){
 digitalWrite(leftWheelPort1,LOW);
 digitalWrite(leftWheelPort2,LOW);
 digitalWrite(rightWheelPort1,LOW); 
 digitalWrite(rightWheelPort2,LOW);
 delay(1000);
}

void fastWalk(){ 
  analogWrite(leftVelocity,255);
  analogWrite(rightVelocity,255);
  delay(1000);
}

void slowWalk(){ 
  analogWrite(leftVelocity,200);
  analogWrite(rightVelocity,200);
  delay(1000);
}

