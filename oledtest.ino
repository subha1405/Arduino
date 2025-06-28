#include <Adafruit_GFX.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>

void setup() {
  // put your setup code here, to run once:
display.begin(SSD1306_SWITCHCAPVCC,0x3C);
}

void loop() {
  // put your main code here, to run repeatedly:
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(SSD1306_BLUE);
display.setCursor(0,0);
display.print("Hello world");
}
