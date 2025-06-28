int gassensorpin=A0;
int sensorvalue=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorvalue=analogRead(gassensorpin);
Serial.print("Sensor Value");
Serial.print(sensorvalue);
if(sensorvalue>400)
{
  Serial.print("Gas threshold Exceeded");
}
delay(1000);
}
