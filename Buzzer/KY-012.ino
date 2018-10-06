
// https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
// https://arduinomodules.info/ky-012-active-buzzer-module/
// Solo produce un tono cuando recibe HIGH. Usar KY-006 para tonos diversos

int BUZ = 8;

void setup() {
  pinMode(BUZ, OUTPUT);
}

void loop() {
  digitalWrite(BUZ, HIGH);
  delay(500);
  digitalWrite(BUZ, LOW);
  delay(500);
}
