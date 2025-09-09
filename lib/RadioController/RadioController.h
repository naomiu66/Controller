#ifndef RADIO_CONTROLLER_H
#define RADIO_CONTROLLER_H

#include <Arduino.h>
#include <nRF24L01.h>
#include <RF24.h>

//возможно лучше ограничить передачу, чтобы было менее 10 байт, но вроде сейчас смотрится неплохо
struct Payload {
    uint16_t j1_x;
    uint16_t j1_y;
    uint16_t j2_x;
    uint16_t j2_y;
    uint8_t j1_btn;
    uint8_t j2_btn;
    uint8_t btn1;
    uint8_t btn2;
    uint8_t btn3;
    uint8_t btn4;
};

class RadioController {

public:
    RadioController() : radio(CE_PIN, CSN_PIN) {}

    void init();
    void sendPayload(Payload payload);

private:
    static constexpr uint16_t CE_PIN = 16;
    static constexpr uint16_t CSN_PIN = 17;
    static constexpr uint16_t PAYLOAD_SIZE = 32;
    static constexpr uint16_t CHANNEL = 0x60;
    static const byte address[6][6];
    RF24 radio;
};

#endif