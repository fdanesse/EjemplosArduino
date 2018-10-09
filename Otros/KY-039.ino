/*
int rawValue;

bool heartbeatDetected(int IRSensorPin, int _delay){
  
  static int maxValue = 0;
  static bool isPeak = false;
  bool result = false;
     
  rawValue = analogRead(IRSensorPin);
  rawValue *= (1000/_delay);  // voltage photo transistor
 
  if (rawValue * 4L < maxValue) {maxValue = rawValue * 0.8;}  // Detect new peak
  
  if (rawValue > maxValue - (1000/_delay)) {  // The peak will be detected here.
    if (rawValue > maxValue) {maxValue = rawValue;}
    if (isPeak == false) {result = true;}
    isPeak = true;
  } else if (rawValue < maxValue - (3000/_delay)) {
    isPeak = false;
    maxValue-=(1000/_delay);
 }
  return result;
}
 
int ledPin = 13;
int analogPin = A0;
 
void setup(){
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);
  Serial.println("Heartbeat detection example code");
}

 
const int delayMsec = 60; // 100msec per sample

void loop(){
  static int beatMsec = 0;
  int heartRateBPM = 0;
  
  //Serial.println(rawValue);
  
  if (heartbeatDetected(analogPin, delayMsec)) {
    heartRateBPM = 60000 / beatMsec;
    digitalWrite(ledPin,1);
    Serial.print(rawValue);
    Serial.print(", ");
    Serial.println(heartRateBPM);
    beatMsec = 0;
  } else {
    digitalWrite(ledPin,0);
  }
  
  delay(delayMsec);
  beatMsec += delayMsec;
}
*/
/*
// Pulse Monitor Test Script
int ledPin = 13;
int sensorPin = A0;
double alpha = 0.75;
int period = 200;
double change = 0.0;
double pulso = 0;

void setup (){
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}

void loop (){
  digitalWrite(13, HIGH);
  static double oldValue = 0;
  static double oldChange = 0;
  int rawValue = analogRead (sensorPin);
  double value = alpha * oldValue + (1 - alpha) * rawValue;
  double val = (((value*value)-100000)-942000)/10;
  if (pulso != val){
    pulso = val;
    Serial.println ((((value*value)-100000)-942000)/10);
    }
  oldValue = value;
  delay (period);
}
*/


// https://www.hackster.io/Johan_Ha/from-ky-039-to-heart-rate-0abfca
#define samp_siz 4
#define rise_threshold 4

// Pulse Monitor Test Script
int sensorPin = A0;

void setup() {
    Serial.begin(9600);
}

void loop (){
    float reads[samp_siz], sum;
    long int now, ptr;
    float last, reader, start;
    float first, second, third, before, print_value;
    bool rising;
    int rise_count;
    int n;
    long int last_beat;

    for (int i = 0; i < samp_siz; i++)
      reads[i] = 0;
    sum = 0;
    ptr = 0;

    while(1){
      // calculate an average of the sensor
      // during a 20 ms period (this will eliminate
      // the 50 Hz noise caused by electric light
      n = 0;
      start = millis();
      reader = 0.;
      do{
        reader += analogRead (sensorPin);
        n++;
        now = millis();
      }
      while (now < start + 20);  
      reader /= n;  // we got an average
      
      // Add the newest measurement to an array
      // and subtract the oldest measurement from the array
      // to maintain a sum of last measurements
      sum -= reads[ptr];
      sum += reader;
      reads[ptr] = reader;
      last = sum / samp_siz;
      // now last holds the average of the values in the array

      // check for a rising curve (= a heart beat)
      if (last > before){
        rise_count++;
        if (!rising && rise_count > rise_threshold){
          // Ok, we have detected a rising curve, which implies a heartbeat.
          // Record the time since last beat, keep track of the two previous
          // times (first, second, third) to get a weighed average.
          // The rising flag prevents us from detecting the same rise more than once.
          rising = true;
          first = millis() - last_beat;
          last_beat = millis();

          // Calculate the weighed average of heartbeat rate
          // according to the three last beats
          print_value = 60000. / (0.4 * first + 0.3 * second + 0.3 * third);
          
          Serial.print(print_value);
          Serial.print('\n');
          
          third = second;
          second = first;   
        }
      }
      else{
        // Ok, the curve is falling
        rising = false;
        rise_count = 0;
      }
      before = last;

      ptr++;
      ptr %= samp_siz;
    }
}
