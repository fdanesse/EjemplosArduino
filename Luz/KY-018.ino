
#define An A2

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(An);
  Serial.println(val, DEC);
  delay(100);
}
