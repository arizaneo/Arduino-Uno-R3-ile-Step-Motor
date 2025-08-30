#include <Stepper.h>

// Motorun bir turundaki adım sayısı (28BYJ-48 için yaklaşık 2048)
const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); 
// IN1=8, IN2=9, IN3=10, IN4=11 (sıra önemli!)

const int buttonPin = 2;  
int lastButtonState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  myStepper.setSpeed(10); // RPM (düşük hız ayarladık, daha stabil olur)
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    Serial.println("Butona basildi, motor 45 derece donuyor...");
    // 45 derece için adım sayısı: 2048 * 45 / 360 = 256 adım
    myStepper.step(256);  
  }

  lastButtonState = buttonState;
}
