#define trigPin 13
#define echoPin 12
#define led 2 //red LED
int sensorPin2 = A1;
#include<Servo.h>
Servo Myservo;
int pos;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
pinMode(sensorPin2, INPUT);
  pinMode(led, OUTPUT);
  Myservo.attach(6);
}

void loop() {
  int sensorValue2 = analogRead(sensorPin2);
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  for(pos=0;pos<=90;pos++){
Myservo.write(pos);
delay(15);
}
  
  for(pos=90;pos>=0;pos--){
Myservo.write(pos);
delay(15);
}
  
        Serial.println( sensorValue2 );
                Serial.println( distance );

  if( sensorValue2 <=500 )
  {
  if (distance < 100) 
  {  //you are free to change this
  //distance is less than 100 so red LED turns on
  digitalWrite(led,HIGH);
 

  }
  else
  {
    digitalWrite(led,LOW);
  }
  }
 
 else
 {
    digitalWrite(led,LOW);
   }  } 
  
