int DHpin = 8;  //Entrada y salida
byte dat[5];    //Es un array de bytes de 5 elementos

byte read_data(){ //Esta función devuelve un byte
  //Serial.println("Reading...");
  byte i = 0;
  byte result = 0;
  for (i = 0; i < 8; i++){ //Lee los 8 bites del byte
    while(digitalRead(DHpin) == LOW);
    delayMicroseconds(30);
    if(digitalRead(DHpin) == HIGH)
      result |= (1 << (8 - i));
    while(digitalRead(DHpin) == HIGH);  //Espera al siguiente bit
    }
    return result;
  }

void start_test(){
  //Serial.println("Testing...");
  
  digitalWrite(DHpin, LOW); //Envía start
  delay(30);  //Este sensor necesita mas de 18ms de segundos para detectar la señal inicial
  digitalWrite(DHpin, HIGH);
  delayMicroseconds(40);  //Esperando la respuesta del sensor
  pinMode(DHpin, INPUT);
  
  //FIXME: Nunca sale de este while
  while(digitalRead(DHpin) == HIGH)
  delayMicroseconds(80);
  
  if (digitalRead(DHpin) == LOW)
    delayMicroseconds(80);

  for(int i = 0; i < 5; i++)
    dat[i] = read_data(); //Leer los datos enviados del sensor
  
  pinMode(DHpin, OUTPUT);
  digitalWrite(DHpin, HIGH);
  }

void setup() {
  Serial.begin(9600);
  pinMode(DHpin, OUTPUT);
  Serial.println("ON");
}

void loop() {
  start_test();
  Serial.print("Humedad: ");
  Serial.print(dat[0], DEC);  //Parte entera para humedad
  Serial.print(".");
  Serial.print(dat[1], DEC);  //Parte decimal para humedad
  Serial.print("%");

  Serial.print("Temperatura: ");
  Serial.print(dat[2], DEC);  //Parte entera para temperatura
  Serial.print(".");
  Serial.print(dat[3], DEC);  //Parte decimal para temperatura
  Serial.print("C");

  // dat[4] es para verificar que los datos ledos son correctos
  byte checksum = dat[0] + dat[1] +dat[2] +dat[3];
  if (dat[4] != checksum)
    Serial.println("-- Checksum error!");
  else
    Serial.println("--OK");

  delay(1000);
}
