#include <RadioController.h>

const byte RadioController::address[6][6] = {
    "1Node", "2Node", "3Node", "4Node", "5Node", "6Node"
};

void RadioController::init() {
    if(!radio.begin()){
        Serial.println("radio init failed");
        while(1) delay(1000);
    }

    radio.setAutoAck(0);
    radio.setRetries(0, 15);
    radio.enableAckPayload();
    radio.setPayloadSize(PAYLOAD_SIZE);
    radio.openWritingPipe(address[0]);
    radio.setChannel(CHANNEL);
    radio.setPALevel(RF24_PA_MAX);
    radio.setDataRate(RF24_250KBPS);
    radio.powerUp(); 
    radio.stopListening(); 
}

void RadioController::sendPayload(Payload payload) {
    radio.write(&payload, sizeof(payload));
}
