#include "MIDIUSB.h"

#define NUM_STRETCH_SENSORS 2
#define DEBUG false

int reading_max[NUM_STRETCH_SENSORS+1] = { 435, 1023 };
int reading_min[NUM_STRETCH_SENSORS+1] = { 212, 0 };
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
    reading = analogRead(i);
    reading = map(reading, reading_min[i], reading_max[i], 0, 127);
    if(DEBUG) Serial.println(reading);
    else  controlChange(0, 1+i, reading);
  }
}
