#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

Servo myServo; // Create a servo object
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD's I2C address and dimensions

void setup() {
  Serial.begin(9600);
  myServo.attach(8); // Attaches the servo on pin 8

  // Initialize the LCD
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on the back light

  // Configure digital input pins
  for (int pin = 34; pin <= 37; pin++) {
    pinMode(pin, INPUT);
  }
  for (int pin = 50; pin <= 53; pin++) {
    pinMode(pin, INPUT);
  }

  // Configure LED output pins
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  int highInputCount = 0; // Counter for high inputs

  // Read and count high states
  for (int pin = 34; pin <= 37; pin++) {
    if (digitalRead(pin) == HIGH) {
      Serial.print(pin);
      Serial.print( digitalRead(pin));
      highInputCount++;
    }
  }
  for (int pin = 50; pin <= 53; pin++) {
    if (digitalRead(pin) == HIGH) {
      Serial.print(pin);
      Serial.print( digitalRead(pin));
      highInputCount++;
    }
  }

  // Display the count of high inputs on the LCD
  lcd.setCursor(0, 0); // Set cursor at the beginning of the first line
  lcd.print("Empty Spots:");
  lcd.print(highInputCount);

  // Control logic for LEDs and servo based on input
  if (digitalRead(37) == HIGH || digitalRead(36) == HIGH) {
    digitalWrite(9, HIGH);
    digitalWrite(12, HIGH);
    myServo.write(90);
  } else if (digitalRead(50) == HIGH || digitalRead(51) == HIGH) {
    digitalWrite(9, HIGH);
    digitalWrite(11, HIGH);
    myServo.write(90);
  } else if (digitalRead(34) == HIGH || digitalRead(35) == HIGH) {
    digitalWrite(10, HIGH);
    myServo.write(90);
  } else if (digitalRead(53) == HIGH || digitalRead(52) == HIGH) {
    digitalWrite(13, HIGH);
    myServo.write(90);
  } else {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    myServo.write(0);
  }

  delay(1000); // Wait for a second before the next reading
      digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
}
