
#include <Servo.h>
#define TRIGPIN 9
#define ECHOPIN 10
#define SERVOPIN 6
Servo myservo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(TRIGPIN,OUTPUT);
pinMode(ECHOPIN,INPUT);
myservo.attach(SERVOPIN);
}
long getdistance()
{
  digitalWrite(TRIGPIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN,HIGH);
  delayMicroseconds(5);
   digitalWrite(TRIGPIN,LOW);
   long duration=pulseIn(ECHOPIN,HIGH);
   long distance=duration*0.034/2;
   return distance;
}
void loop() {
long distance=getdistance();
Serial.print("Distance");
Serial.print(distance);
Serial.print("cm");
if (distance<10)
{
  myservo.write(0);
} 
else if(distance<20)
{
  myservo.write(90);
}   // put your main code here, to run repeatedly:
else
{
  myservo.write(180);
} 
delay(500);
}
