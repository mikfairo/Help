#include <Servo.h>
Servo myservo; 
const int buttonPin = 4; 
const int buttonPin2 = 2;
const int LED =  13; 
const int LED2 = 12;
const int LED3 = 11;    
const int LED4 = 10;
const int LED5 = 9;

int LEDState = LOW;       
int buttonState = LOW;  
int buttonState2 = LOW;           
int lastButtonState = LOW;   
int pos = 0;

// setup runs once at startup
void setup() {
  pinMode(buttonPin, INPUT); 
  pinMode(buttonPin2,INPUT);
  pinMode(LED, OUTPUT);  
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  pinMode (LED4, OUTPUT);
  pinMode (LED5,OUTPUT);
  myservo.attach(8);
}

void move_servo(int pos)
{
  myservo.write(pos);
  delay(1000);
}
void loop() {

  for (pos = 0; pos <= 180; pos += 90) { // goes from 0 degrees to 180 degrees
    // in steps of 90 degree         
    move_servo(0);
    move_servo(90);
    move_servo(180);
    move_servo(90);            // waits 1s for the servo to reach the position
  }
  buttonState = digitalRead(buttonPin); 
  buttonState2 = digitalRead(buttonPin2);
  delay (4000);

  if (buttonState == HIGH && lastButtonState == LOW) {
    LEDState = !LEDState; 
  } else {
  }
  lastButtonState = buttonState; 
  if (LEDState == 1) { 
    digitalWrite (LED, HIGH); 
    digitalWrite (LED2, HIGH);
    digitalWrite (LED3, HIGH);
    digitalWrite (LED4, HIGH);
    digitalWrite (LED5, HIGH);  

  } else {
    digitalWrite (LED, LOW); 
    digitalWrite (LED2,LOW);
    digitalWrite (LED3,LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);

  }
}