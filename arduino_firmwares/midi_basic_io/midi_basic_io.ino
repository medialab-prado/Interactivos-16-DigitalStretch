#define STRETCHSENSE A0
#include "MIDIUSB.h"

void setup() {
Serial.begin(115200);
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {
midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
MidiUSB.sendMIDI(event);
}

void loop() {
int reading;

reading = analogRead(STRETCHSENSE);
reading = map(reading, 0, 1023, 0, 127);
Serial.println(reading);

// for (int i = 0; i &lt; 100; i++) {

controlChange(0, 65, reading);
// }
}
