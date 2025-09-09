#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <Arduino.h>
#include <RadioController.h>

class InputManager {

public:
    InputManager(RadioController &_radio) : radio(_radio) {}

    void init();
    void update();

private:
    static constexpr int JOY1_X_PIN = 32;
    static constexpr int JOY1_Y_PIN = 33;
    static constexpr int JOY1_BTN_PIN = 12;

    static constexpr int JOY2_X_PIN = 34;
    static constexpr int JOY2_Y_PIN = 35;
    static constexpr int JOY2_BTN_PIN = 13;

    static constexpr int BTN1_PIN = 27;
    static constexpr int BTN2_PIN = 14;
    static constexpr int BTN3_PIN = 4;
    static constexpr int BTN4_PIN = 0;
    
    static constexpr int DEADZONE = 200;
    static constexpr int CENTER = 2000;

    RadioController &radio;

    bool checkChanges(Payload payload);
};

#endif