
const int flexpin=A0;
const int ledpin=9; 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ledpin,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
int sensorvalue=analogRead(flexpin);
int ledBrightness=map(sensorvalue,300,900,255,0);
ledBrightness=constrain(ledBrightness,0,255);
analogWrite(ledpin,ledBrightness);
Serial.print("Flex Sensor Value");
Serial.print(sensorvalue);
Serial.print("Led Brightness");
Serial.print(ledBrightness);
delay(1000);
}
