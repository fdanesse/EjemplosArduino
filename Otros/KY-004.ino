int led = 13;
int buttonpin = 3;
int val;

void setup(){
  pinMode(led,OUTPUT);
  pinMode(buttonpin,INPUT);
}

void loop(){
  val = digitalRead(buttonpin);
  if(val==HIGH){
    digitalWrite(led,HIGH);
    Serial.println("OK");
  }else{
    digitalWrite(led,LOW);
  }
}
