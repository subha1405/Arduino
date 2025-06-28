const int thermistorpin=A0;
const float BETA=3950.0;
const float R0=10000.0;
const float T0=298.15;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensorvalue=analogRead(thermistorpin);
float voltage=sensorvalue* (5.0/1023);
float resistance =(5.0-voltage)*R0/voltage;
float tk=1.0/(1.0/T0+log(resistance/R0)/BETA);
float tc=tk-273.15;
Serial.print("Temperature");
Serial.print(tc);
Serial.print("^C");
delay(1000);
}
