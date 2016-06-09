#define NUM_STRETCH_SENSORS 2

int reading_max[NUM_STRETCH_SENSORS+1];
int reading_min[NUM_STRETCH_SENSORS+1];
int reading[NUM_STRETCH_SENSORS+1];

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
    if(reading[i]<=reading_min[i])  reading_min[i] = reading[i];
  }
  
  Serial.print("Sensors min: { ");
  for(int i=0; i<NUM_STRETCH_SENSORS;i++){
    Serial.print(reading_min[i]);
    if(i!=(NUM_STRETCH_SENSORS-1))  Serial.print(", ");
  }
  Serial.println(" };");
  Serial.print("Sensors max: { ");
  for(int i=0; i<NUM_STRETCH_SENSORS;i++){
    Serial.print(reading_max[i]);
    if(i!=(NUM_STRETCH_SENSORS-1))  Serial.print(", ");
  }
  Serial.println(" };");

}
