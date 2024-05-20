#include <Servo.h>

Servo myservo;
const int buttonPin = 4;
const int buttonPin2 = 2;
const int LED = 13;
const int LED2 = 12;
const int LED3 = 11;
const int LED4 = 10;
const int LED5 = 9;

int LEDState = LOW;
int buttonState = LOW;
int buttonState2 = LOW;
int lastButtonState2 = LOW;
int servoState = LOW;
int lastServoButtonState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  myservo.attach(8);
  randomSeed(analogRead(0)); // Initialize random seed
}

void move_servo(int pos) {
  myservo.write(pos);
  delay(1000);
}

void execute_sequence(int sequence) {
  switch (sequence) {
    case 1:
      move_servo(0);
      move_servo(90);
      move_servo(180);
      move_servo(90);
      break;
    case 2:
      move_servo(0);
      move_servo(45);
      move_servo(90);
      move_servo(180);
      break;
    case 3:
      move_servo(0);
      move_servo(90);
      move_servo(180);
      move_servo(45);
      break;
    case 4:
      move_servo(0);
      move_servo(45);
      move_servo(45);
      move_servo(90);
      break;
    case 5:
      move_servo(0);
      move_servo(180);
      move_servo(90);
      move_servo(45);
      break;
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);
  buttonState2 = digitalRead(buttonPin2);

  // Toggle servo state when buttonPin is pressed
  if (buttonState == HIGH && lastServoButtonState == LOW) {
    servoState = !servoState;
  }
  lastServoButtonState = buttonState;

  // Move servo if it is in the on state
  if (servoState == HIGH) {
    int sequence = random(1, 6); // Randomly select a sequence from 1 to 5
    execute_sequence(sequence);
  }

  // Toggle LED state when buttonPin2 is pressed
  if (buttonState2 == HIGH && lastButtonState2 == LOW) {
    LEDState = !LEDState;
  }
  lastButtonState2 = buttonState2;

  if (LEDState == HIGH) {
    digitalWrite(LED, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }

  delay(50); // Add a small delay to debounce the buttons
}

  delay(50); // Add a small delay to debounce the buttons
}
