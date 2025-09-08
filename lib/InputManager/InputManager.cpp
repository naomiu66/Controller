#include <InputManager.h>

void InputManager::init() {
    pinMode(JOY1_BTN_PIN, INPUT_PULLUP);
    pinMode(JOY2_BTN_PIN, INPUT_PULLUP);
}

void InputManager::update() {
    Payload data;
    data.j1_btn = (digitalRead(JOY1_BTN_PIN)) ? 1 : 0;
    data.j2_btn = (digitalRead(JOY2_BTN_PIN)) ? 1 : 0;
    data.j1_x = analogRead(JOY1_X_PIN);
    data.j1_y = analogRead(JOY1_Y_PIN);
    data.j2_x = analogRead(JOY2_X_PIN);
    data.j2_y = analogRead(JOY2_Y_PIN);
    bool canSendPayload = checkChanges(data);

    if(canSendPayload) radio.sendPayload(data);
    else return;
}

bool InputManager::checkChanges(Payload payload)
{
    if(payload.j1_btn == 0 || payload.j2_btn == 0) return true;
    
    if(payload.j1_x > CENTER + DEADZONE || payload.j1_x < CENTER - DEADZONE
    || payload.j1_y > CENTER + DEADZONE || payload.j1_y < CENTER - DEADZONE
    || payload.j2_x > CENTER + DEADZONE || payload.j2_x < CENTER - DEADZONE
    || payload.j2_y > CENTER + DEADZONE || payload.j2_y < CENTER - DEADZONE) return true;

    return false;
}
