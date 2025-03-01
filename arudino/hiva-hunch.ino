#include <Servo.h>

Servo myservo;  // create Servo object to control a servo
bool clamped = false;    // variable to store the servo position

int LED_RED = 12;
int LED_GREEN = 11;
int LED_BLUE = 10;

int BUZZER = 3;

const int trigPin = 5;
const int echoPin = 6;

float duration, distanceCM, distanceIN, distanceIN_PREV;

void setup() {

  // myservo.attach(9);  // attaches the servo on pin

  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, HIGH);

  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, HIGH);
  
  pinMode(BUZZER, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  // myservo.write(90);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distanceCM = (duration * 0.0343) / 2;
  distanceIN = distanceCM / 2.54;
  
  Serial.print("Distance In: ");
  Serial.println(distanceIN);

  if (distanceIN >= 5.0 && distanceIN <= 8.0)  {
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
  delay(500);
}
