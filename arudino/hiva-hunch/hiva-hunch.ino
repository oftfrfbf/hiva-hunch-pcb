// rk2025

#include <Servo.h>
#include <NewPing.h> // https://youtu.be/pqlU3LnO79M?si=sfCyYIluLruaKDrs

const int ServoPin = 6;
const int TriggerPin = 5;
const int EchoPin = 6;

NewPing sonar (TriggerPin, EchoPin, 30);
Servo servo;  // create Servo object to control a servo

bool clamped = false;    // variable to store the servo position

int LED_RED = 12;
int LED_GREEN = 11;
int LED_BLUE = 10;

int BUZZER = 3;

float duration, distanceCM, distanceIN, distanceIN_PREV;

void setup() {
  Serial.begin(9600);
  servo.attach(ServoPin);  // attaches the servo on pin

  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, HIGH);

  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, HIGH);
  
  pinMode(BUZZER, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
}

void loop() {
  int cm = sonar.ping_cm();
  Serial.println(cm);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  if (cm >= 5.0 && cm <= 10.0)  {
    // clamp down
    if (!clamped) {
      // clamp and set var
      clamped = true;
      // Turn on Green LED
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, LOW);
    
      // Play Sound
      digitalWrite(BUZZER, HIGH);
      delay(100);
      digitalWrite(BUZZER, LOW);

      // myservo.write(90);
      // delay(500);
    }
  } else {
    // open clamp up
    if (clamped) {
      clamped = false;

      // Turn on Red LED
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED, HIGH);

      // myservo.write(0);
    }
  }
  delay(50);
}