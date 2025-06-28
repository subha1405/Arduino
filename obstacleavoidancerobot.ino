

#include <AFMotor.h>

// Initialize 4 motors
AF_DCMotor motorLeft1(1);  // M1
AF_DCMotor motorRight1(2); // M2
AF_DCMotor motorLeft2(3);  // M3
AF_DCMotor motorRight2(4); // M4
// LiquidCrystal_I2C lcd(0x27,16,2);
// Ultrasonic Sensor
#define TRIG_PIN A0
#define ECHO_PIN A1


// Distance measurement
long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout
  long distance = duration * 0.034 / 2;
  return distance;
}

// Movement Functions
void moveForward() {
  motorLeft1.setSpeed(250);
  motorLeft2.setSpeed(250);
  motorRight1.setSpeed(250);
  motorRight2.setSpeed(250);

  motorLeft1.run(FORWARD);
  motorLeft2.run(FORWARD);
  motorRight1.run(FORWARD);
  motorRight2.run(FORWARD);
}

void moveBackward() {
  motorLeft1.setSpeed(150);
  motorLeft2.setSpeed(150);
  motorRight1.setSpeed(150);
  motorRight2.setSpeed(150);

  motorLeft1.run(BACKWARD);
  motorLeft2.run(BACKWARD);
  motorRight1.run(BACKWARD);
  motorRight2.run(BACKWARD);
}

void turnLeft() {
  motorLeft1.setSpeed(100);
  motorLeft2.setSpeed(100);
  motorRight1.setSpeed(100);
  motorRight2.setSpeed(100);

  motorLeft1.run(BACKWARD);
  motorLeft2.run(BACKWARD);
  motorRight1.run(FORWARD);
  motorRight2.run(FORWARD);
}

void turnRight() {
  motorLeft1.setSpeed(100);
  motorLeft2.setSpeed(100);
  motorRight1.setSpeed(100);
  motorRight2.setSpeed(100);

  motorLeft1.run(FORWARD);
  motorLeft2.run(FORWARD);
  motorRight1.run(BACKWARD);
  motorRight2.run(BACKWARD);
}

void stopMotors() {
  motorLeft1.run(RELEASE);
  motorLeft2.run(RELEASE);
  motorRight1.run(RELEASE);
  motorRight2.run(RELEASE);
}

void setup() {
  Serial.begin(9600);
  // lcd.begin(16,2);
  // lcd.init();
  // lcd.backlight();
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  moveForward();
}
void loop() {
  long frontDist = readDistanceCM();
  // lcd.setCursor(0,0);
  // lcd.print("Front: ");
  // lcd.setCursor(0,1);
  // lcd.print(frontDist);

  if (frontDist > 20) {
    moveForward();
  } else {
    stopMotors();
    delay(300);
    moveBackward();
    delay(400);
    stopMotors();
    turnRight();
    delay(600);
    stopMotors();
    delay(300);
  }
}
