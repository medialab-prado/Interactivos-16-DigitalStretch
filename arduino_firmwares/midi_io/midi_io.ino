#include "MIDIUSB.h"

#define NUM_STRETCH_SENSORS 3
#define DEBUG 1

void setup() {
  Serial.begin(115200);
}

void controlChange(byte channel, byte control, byte value) {
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}

void loop() {

  for(int i=0; i<NUM_STRETCH_SENSORS;i++){
    int reading;
    reading = analogRead(STRETCHSENSE);
    reading = map(reading, 0, 1023, 0, 127);
    if(DEBUG) Serial.println(reading);
    else  controlChange(0, i, reading);
  }
}
