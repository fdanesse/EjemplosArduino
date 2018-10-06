/*
 Conexiones del sensor:
 La salida digital al pin 2
 La salida analógica a A0
*/

int Di = 2;

void setup () {
  pinMode(Di, INPUT); // pin Digital 2 (recuerden que por defecto todos son input, asi que es redundante esto)
  pinMode(LED_BUILTIN, OUTPUT); // El led por defecto en la placa
}

void loop () {
  if (digitalRead(Di) == 1){
    digitalWrite(LED_BUILTIN, HIGH);
    }else{
    digitalWrite(LED_BUILTIN, LOW);
    }
  delay(10);
}
