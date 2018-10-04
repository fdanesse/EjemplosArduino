
/*
 Conexiones del sensor:
 La salida digital al pin 2
 La salida analógica a A0
*/
void setup () {
  pinMode(2, INPUT); //pin Digital 2 (recurden que por defecto todos son input, asi que es redundante esto)
  pinMode(LED_BUILTIN, OUTPUT); // El led por defecto en la placa
  Serial.begin(9600);
}

void loop () {
  Serial.print(analogRead(A0)); Serial.println();
  digitalWrite(13, digitalRead(2)); //Escribir en D13 lo que se lee en D2
  delay(1000);
}
