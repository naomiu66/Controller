#include <InputManager.h>

void InputManager::init() {
    pinMode(JOY1_BTN_PIN, INPUT_PULLUP);
    pinMode(JOY2_BTN_PIN, INPUT_PULLUP);
    pinMode(BTN1_PIN, INPUT_PULLUP);
    pinMode(BTN2_PIN, INPUT_PULLUP);
}

void InputManager::update() {
    Payload data;
    // при нажатии на кнопку будет 1, если отжата то 0
    data.j1_btn = (digitalRead(JOY1_BTN_PIN)) ? 0 : 1;
    data.j2_btn = (digitalRead(JOY2_BTN_PIN)) ? 0 : 1;
    data.j1_x = analogRead(JOY1_X_PIN);
    data.j1_y = analogRead(JOY1_Y_PIN);
    data.j2_x = analogRead(JOY2_X_PIN);
    data.j2_y = analogRead(JOY2_Y_PIN);
    data.btn1 = (digitalRead(BTN1_PIN)) ? 1 : 0;
    data.btn2 = (digitalRead(BTN2_PIN)) ? 1 : 0;
    data.btn3 = (digitalRead(BTN3_PIN)) ? 1 : 0;
    data.btn4 = (digitalRead(BTN4_PIN)) ? 1 : 0;
    bool canSendPayload = checkChanges(data);

    if(canSendPayload) {
        radio.sendPayload(data);
        Serial.println("payload send: ");
        Serial.print("btn1: "); Serial.println(data.btn1);
        Serial.print("btn2: "); Serial.println(data.btn2);
        Serial.print("btn3: "); Serial.println(data.btn3);
        Serial.print("btn4: "); Serial.println(data.btn4);
        Serial.print("jbtn1: "); Serial.println(data.j1_btn);
        Serial.print("jbtn2: "); Serial.println(data.j2_btn);
    }
    else return;
}

bool InputManager::checkChanges(Payload payload)
{
    if(payload.j1_btn == 1 
    || payload.j2_btn == 1 
    || payload.btn1 == 1 
    || payload.btn2 == 1
    || payload.btn3 == 1 
    || payload.btn4 == 1) return true;
    
    if(payload.j1_x > CENTER + DEADZONE || payload.j1_x < CENTER - DEADZONE
    || payload.j1_y > CENTER + DEADZONE || payload.j1_y < CENTER - DEADZONE
    || payload.j2_x > CENTER + DEADZONE || payload.j2_x < CENTER - DEADZONE
    || payload.j2_y > CENTER + DEADZONE || payload.j2_y < CENTER - DEADZONE) return true;

    return false;
}
