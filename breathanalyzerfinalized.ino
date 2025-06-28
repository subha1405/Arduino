#include <LiquidCrystal_I2C.h>
#define sensorDigital 2
#define sensorAnalog A1
#define LED 3
LiquidCrystal_I2C lcd(0x27,  16, 2);
float mgl=0,value=0;
void setup()
{
  Wire.begin();
  pinMode(sensorDigital,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(300);
  lcd.init();
  lcd.backlight();
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("Alcohol Detector ");
  delay(2000);
  lcd.clear();
}
void loop()
{
  int analog=0;
  for(int i=0;i<10;i++)
  {
   analog+=analogRead(sensorAnalog);
  }
  value=(analog/10)*(5.0/1024);
  mgl=0.67*value;
  lcd.setCursor(0,0);
  lcd.print("Alcohol value: ");
  lcd.setCursor(0,1);
  lcd.print(mgl);
  if(mgl>1.44)
  {
    digitalWrite(8,HIGH);
    digitalWrite(13,HIGH);
    digitalWrite(9,LOW);
  }
else
{
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(13,LOW);
}
}
