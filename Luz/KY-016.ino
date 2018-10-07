


void setup() {
  Serial.begin(9600);
  for (int x=9; x<12; x++){pinMode(x, OUTPUT);}
}

void loop() {
  for (int val=255; val>0; val--){
    analogWrite(11, val);
    analogWrite(10, 255-val);
    analogWrite(9, 128-val);

    Serial.println(val, DEC);
    delay(5);
    }

  for (int val=0; val<255; val++){
    analogWrite(11, val);
    analogWrite(10, 255-val);
    analogWrite(9, 128-val);
  
    Serial.println(val, DEC);
    delay(5);
    }
}
