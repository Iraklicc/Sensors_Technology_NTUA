const int analogPin = A0;
const int deigmata = 100;  // posa deigmata tha paroume
void setup() {
  Serial.begin(9600);
}

void loop() {
  int minValue = 1023;
  int maxValue = 0;

  // Deigmatolhpsia
  for (int i = 0; i < deigmata; i++) {
    int sample = analogRead(analogPin);
    if (sample < minValue) minValue = sample;
    if (sample > maxValue) maxValue = sample;
  }

  // Ypologismos Vpp
  int diafora = maxValue - minValue;
  float vpp = diafora * (5000.0 / 1023.0);  // to mV

  Serial.print("Vpp: ");
  Serial.print(vpp, 2);
  Serial.println(" mV");

  delay(1000);
}
