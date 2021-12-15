#define EN 10
#define IN1 9
#define IN2 8

int motor_speed = 0;
int pedal = A0;
const int buttonPin = 2;
const int buttonPin2 = 3; // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int BuzzerPin = 11;
void setup()
{
  pinMode(IN1, OUTPUT); // motor pin 1
  pinMode(IN2, OUTPUT); // motor pin 2
  pinMode(EN, OUTPUT); // motor PWM pin
  pinMode(pedal,INPUT); // potentiometer pin
   pinMode(buttonPin, INPUT);
  Serial.begin(9600); 
}

void loop()
{
  buttonState = digitalRead(buttonPin);
    buttonState2 = digitalRead(buttonPin2);

  int pedalValue = analogRead(pedal);
  delay(1000);
  if (buttonState==1)
{
  analogWrite(BuzzerPin, 255); 
delay(500);
analogWrite(BuzzerPin, 155);
delay(500);
analogWrite(BuzzerPin, 255);
delay(500);
analogWrite(BuzzerPin, 155);
delay(500);
}

else
{
analogWrite(BuzzerPin, 0);
delay(500);
}
  
  motor_speed = map(pedalValue, 0, 1024, 0, 255);
 
  Serial.print("RPM: ");
  Serial.println(motor_speed);
  Serial.print("buttonState: ");
  Serial.println(buttonState);
  Serial.print("buttonState2: ");
  Serial.println(buttonState2);
  if(buttonState2==1)
  {
  if(motor_speed >= 0 && motor_speed <= 255)
       {
       digitalWrite(IN1, HIGH);
       digitalWrite(IN2, LOW);
       analogWrite(EN,motor_speed);
       }
}
else
{
         analogWrite(EN,0);

}
}
