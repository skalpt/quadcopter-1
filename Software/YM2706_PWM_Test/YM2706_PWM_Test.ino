#include <OneWire.h>

const int PIN_ONEWIRE = 6;
const int PIN_MOTOR = 11;
const int PIN_LED = 9;

OneWire ds(PIN_ONEWIRE);

void setup()
{
  Serial.begin(115200);
  
  pinMode(PIN_MOTOR, OUTPUT);
  pinMode(PIN_LED, OUTPUT);

  for (int i=0;i<20;i++) {
    analogWrite(PIN_LED, 255);
    delay(100);
    analogWrite(PIN_LED, 0);
    delay(100);
  }
  
  delay(1000);
}

void loop()
{
  Serial.println("PWM set to 100%.");
  Serial.println();
  analogWrite(PIN_LED, 255);
  analogWrite(PIN_MOTOR, 255);
  delay(3000);
  
  Serial.println("PWM set to 50%.");
  Serial.println();
  analogWrite(PIN_LED, 128);
  analogWrite(PIN_MOTOR, 128);
  delay(3000);
  
  Serial.println("PWM set to 0%.");
  Serial.println();
  analogWrite(PIN_LED, 0);
  analogWrite(PIN_MOTOR, 0);
  delay(3000);
}
