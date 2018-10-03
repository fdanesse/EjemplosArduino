double celsius = 0.0;
int kelvin = 0;

void setup () {
  Serial.begin(9600);
}

double convertToCelsius(int data){
  double t = log(10000.0*((1024.0/data-1)));
  t = 1/(0.001129148+(0.000234125+(0.0000000876741*t*t))*t);
  t = t-273.15;
  return t;
  }
  
void loop () {
  int kelvin = analogRead(A0);  // A0 (letra a + numero 0), es la salida analógica donde conecté el sensor, el número es el índice del puerto AO.
  double cel = convertToCelsius(kelvin);
  if (celsius != cel){
    celsius = cel;
    Serial.print("celsius: "); Serial.print(celsius); Serial.print(" kelvin: "); Serial.print(kelvin); Serial.println();
    }
  delay(1000);
}
