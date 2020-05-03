#include <Arduino.h>
#include "optocoupler.hpp"

Optocoupler plStop1(13);

void setup() {
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Optocoupler on pin ");
  Serial.print(plStop1.pinNumber());
  Serial.print(" state -> ");
  Serial.println(plStop1.state());

  delay(500);
}