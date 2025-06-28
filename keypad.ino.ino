
#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // Connect to the column pinouts of the keypad

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  // Check for a keypress
  char key = keypad.getKey();

  if (key != NO_KEY) {
    // Print the pressed key to the serial monitor
    Serial.println(key);
  }

  delay(100); // Add a small delay to avoid multiple readings for the same keypress
}
