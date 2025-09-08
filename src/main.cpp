#include <Arduino.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RadioController.h>
#include <InputManager.h>

RadioController radioController;
InputManager inputManager(radioController);

void setup() {
  Serial.begin(115200);

  radioController.init();
  inputManager.init();
}

void loop() {
  inputManager.update();
}