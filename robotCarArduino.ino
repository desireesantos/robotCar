#include<IRremote.h>

int rightWheelPort1 = 8;
int rightWheelPort2 = 7;
int rightVelocity = 9;

int leftWheelPort1 = 13;
int leftWheelPort2 = 12;
int leftVelocity = 5;
int dados = 0;

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results; 

void setup() {                
  pinMode(rightWheelPort1, OUTPUT);
  pinMode(rightWheelPort2, OUTPUT); 
  pinMode(rightVelocity, OUTPUT); 
  
  pinMode(leftWheelPort1, OUTPUT); 
  pinMode(leftWheelPort2, OUTPUT); 
  pinMode(leftVelocity, OUTPUT); 
  fastWalk();
  
  Serial.begin(9600);
  irrecv.enableIRIn();
}


void loop() {
if (irrecv.decode(&results)){
    dados= (int)results.value,HEX;
    Serial.println(dados);
    if ((dados == 1327)||(dados == 3375))
        {   Serial.println("Left");
                    left();
              }
     else if ((dados == 1335)||(dados == 3383))
	       {	Serial.println("Front");
                       front();
              }
     else if ((dados == 1295)||(dados == 3343))
	      {	Serial.println("Back");
                      back();
              }
     else if ((dados == 1323)||(dados == 3371))
	      {	Serial.println("Right");
                      right();
              }
      else if ((dados == 1308)||(dados == 3356))
	      {	Serial.println("Stop");
                    stopCar();
      }
       
    irrecv.resume();
}  
}

void back(){
 digitalWrite(leftWheelPort1,HIGH); 
 digitalWrite(leftWheelPort2,LOW); 
 digitalWrite(rightWheelPort1,LOW); 
 digitalWrite(rightWheelPort2,HIGH);
 delay(500);
}

void front(){
  digitalWrite(leftWheelPort1,LOW); 
  digitalWrite(leftWheelPort2,HIGH); 
  digitalWrite(rightWheelPort1,HIGH); 
  digitalWrite(rightWheelPort2,LOW);
  delay(500);
}

void  left(){
 digitalWrite(leftWheelPort1,LOW); 
 digitalWrite(leftWheelPort2,HIGH);
 digitalWrite(rightWheelPort1,LOW);
 digitalWrite(rightWheelPort2,LOW);
 delay(500);
}

void  right(){
 digitalWrite(leftWheelPort1,LOW); 
 digitalWrite(leftWheelPort2,LOW);
 digitalWrite(rightWheelPort1,HIGH);
 digitalWrite(rightWheelPort2,LOW);
 delay(500);
}

void stopCar(){
 digitalWrite(leftWheelPort1,LOW);
 digitalWrite(leftWheelPort2,LOW);
 digitalWrite(rightWheelPort1,LOW); 
 digitalWrite(rightWheelPort2,LOW);
 delay(500);
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

