#define NUM_STRETCH_SENSORS 2

int reading_max[NUM_STRETCH_SENSORS];
int reading_min[NUM_STRETCH_SENSORS];
int reading[NUM_STRETCH_SENSORS];

void setup() {
  Serial.begin(115200);
  for(int i=0; i<NUM_STRETCH_SENSORS; i++){
    reading_max[i] = 0;
    reading_min[i] = 1023;
  }
}
void loop() {

  for(int i=0; i<NUM_STRETCH_SENSORS;i++){
    reading[i] = analogRead(i);
    if(reading[i]>=reading_max[i])  reading_max[i] = reading[i];
    if(reading[i]<=reading_min[i])  reading_mmin[i] = reading[i];

    Serial.print("Sensors min: { ");
    Serial.print(reading_min[i]);
    Serial.print(", ");
    Serial.println(" };");

    Serial.print("Sensors max: { ");
    Serial.print(reading_min[i]);
    Serial.print(", ");
    Serial.println(" };");
  }




}
