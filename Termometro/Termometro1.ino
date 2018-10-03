double celsius = 0.0;
double kelvin = 0.0;
double fahrenheit = 0.0;

void setup () {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

double convertToFahrenheit(double cel){
  double t = cel * 1.8 + 32.0;
  return t;
  }
  
double convertToCelsius(double data){
  double t = log(10000.0*((1024.0/data-1)));
  kelvin = 1/(0.001129148+(0.000234125+(0.0000000876741*t*t))*t);
  double cel = kelvin-273.15;
  return cel;
  }
  
void loop () {
  double data = analogRead(A0);  // A0 (letra a + numero 0), es la salida analógica donde conecté el sensor, el número es el índice del puerto AO.
  double cel = convertToCelsius(data);
  fahrenheit = convertToFahrenheit(cel);
  if (celsius != cel){
    celsius = cel;
    Serial.print("celsius: "); Serial.print(celsius); Serial.print(" kelvin: "); Serial.print(kelvin); Serial.print(" fahrenheit: "); Serial.print(fahrenheit); Serial.println();
    }
  delay(500);
}
