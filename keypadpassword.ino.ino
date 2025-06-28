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

// Define the correct password
char correctPassword[] = "1234";
char enteredPassword[5];
int passwordIndex=0;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  Serial.println("Enter password:");
  pinMode(13,OUTPUT);
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    if (key == '5') {
      // Asterisk key signifies end of password entry
      enteredPassword[passwordIndex] = '\0'; // Null terminate the string
      // Compare entered password with correct password
      if (strcmp(enteredPassword, correctPassword) == 0) {
        Serial.println("Password correct!");
        digitalWrite(13,HIGH);
        // Do something (e.g., unlock a door, turn on a device, etc.)
      } else {
        Serial.println("Incorrect password. Try again.");
        digitalWrite(13,LOW);
      }
      //Reset for next password entry
      passwordIndex = 0;
      memset(enteredPassword, 0, sizeof(enteredPassword));
      Serial.println("Enter password:");
    } else {
      // Add the pressed key to enteredPassword
      if (passwordIndex < sizeof(enteredPassword) - 1) {
        enteredPassword[passwordIndex++] = key;
        Serial.print(key); // Print asterisks or dots for each key press
      }
    }
  }

  delay(100); // Add a small delay to debounce the keypad and prevent multiple readings for the same keypress
}
