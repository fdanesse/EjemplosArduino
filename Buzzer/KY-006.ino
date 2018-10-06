
// https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/
// https://arduinomodules.info/ky-006-passive-buzzer-module/

int BUZ = 8;

void setup() {
  pinMode(BUZ, OUTPUT);
}

void ejemplo1(){
  tone(BUZ, 100, 500); // tone(pin, frequency, duration)
  delay(1000);
  }

void ejemplo2(){
  tone(BUZ, 100); // tone(pin, frequency)
  delay(1000);
  noTone(BUZ);
  delay(1000);
  }

void ejemplo3(){
  // Ejemplo oficial del módulo
  for (int x=0; x<80; x++){
    digitalWrite(BUZ, HIGH);
    delay(1);
    digitalWrite(BUZ, LOW);
    delay(1);
    }
  delay(50);
  for (int x=0; x<100; x++){
    digitalWrite(BUZ, HIGH);
    delay(2);
    digitalWrite(BUZ, LOW);
    delay(2);
    }
  delay(100);
  }

void loop() {
  // ejemplo1();
  // ejemplo2();
  ejemplo3();
}
