// #include "pitches.h"
int LED_RED = 12;
int LED_GREEN = 11;
int LED_BLUE = 10;

int BUZZER = 3;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_RED, OUTPUT);
  digitalWrite(LED_RED, HIGH);

  pinMode(LED_GREEN, OUTPUT);
  digitalWrite(LED_GREEN, HIGH);

  pinMode(LED_BLUE, OUTPUT);
  digitalWrite(LED_BLUE, HIGH);
  
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  digitalWrite(LED_RED, LOW);
  delay(1000); // wait for a second
  digitalWrite(LED_RED, HIGH);

  digitalWrite(LED_GREEN, LOW);
  delay(1000);
  digitalWrite(LED_GREEN, HIGH);

  digitalWrite(LED_BLUE, LOW);
  delay(1000);
  digitalWrite(LED_BLUE, HIGH);

  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);

}
