#include <AFMotor.h>  // Adafruit Motor Shield library
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>
// LiquidCrystal_I2C lcd(0x27, 16, 2);
// Create motor objects for M1 to M4
AF_DCMotor motor1(1);  // Motor 1
AF_DCMotor motor2(2);  // Motor 2
AF_DCMotor motor3(3);  // Motor 3
AF_DCMotor motor4(4);  // Motor 4
void setup() {
//   Serial.begin(9600);
//  lcd.begin(16, 2);
//   lcd.backlight();
//   lcd.setCursor(0, 0);
//   lcd.print("Hey you wanna");
//   lcd.setCursor(0,1);
//   lcd.print("drop me");
  // Set motor speed (0 to 255)
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void loop() {
  // Run all motors forward
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(2000);  // Run for 2 seconds

  // Stop all motors
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  delay(1000);  // Wait 1 second

  // Run all motors backward
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(2000);  // Run for 2 seconds

  // Stop again
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

  delay(2000);
  motor1.run(RELEASE);//TURN  RIGHT
  motor2.run(RELEASE);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(2000);
  motor1.run(FORWARD);//TURN LEFT
  motor2.run(FORWARD);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  delay(2000); 
}
