
int PUL = 2;
int LED = 13;
long T0 = 0 ;
volatile int STATUS = LOW;

int IN1 = 8;
int IN2 = 9;
int IN3 = 10;
int IN4 = 11;
int DEMORA = 20;
int PASOS[4][4] = {
  {1,1,0,0},
  {0,1,1,0},
  {0,0,1,1},
  {1,0,0,1}
  };
  
void setup(){
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, STATUS);
  Serial.begin(9600);
  Serial.println("INIT");
  attachInterrupt(0, pulseControl, CHANGE);  // https://www.prometec.net/interrupciones/
}

void run(){
  // 4 pasos == 1 ciclo
  // 8 ciclos == 1 giro completo
  // 4 * 8 * 64 = 2048 pasos (porque tiene una reducción de 1/64)
  for (int x=0; x < 512; x++){ // 512 * 4 = 2048
    for (int i=0; i < 4; i++){
      digitalWrite(IN1, PASOS[i][0]);
      digitalWrite(IN2, PASOS[i][1]);
      digitalWrite(IN3, PASOS[i][2]);
      digitalWrite(IN4, PASOS[i][3]);
      delay(DEMORA);
      if (!STATUS){break;}
    }
    if (!STATUS){break;}
  }
}

void off(){
  if (digitalRead(IN1) == HIGH || digitalRead(IN2) == HIGH || digitalRead(IN3) == HIGH || digitalRead(IN4) == HIGH){
    digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
    Serial.println("OFF");
  }
  if (digitalRead(LED)){digitalWrite(LED, LOW);}
}

void loop(){
  if (STATUS == HIGH){
    if (!digitalRead(LED)){digitalWrite(LED, HIGH); Serial.println("ON");}
    run();
  } else {off(); delay(200);}
}

void pulseControl(){
  if (millis() > T0 + 250){T0 = millis();}
  else {STATUS = !STATUS;}
}
