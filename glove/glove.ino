//component pin
#define echoPin 7 //pin for echo pin (ultrasonic sensor)
#define trigPin 8 //pin for triger pin (ultrasonic sensor)
#define sound 5 //pin for speaker
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
int val; //Sound frequency
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
pinMode(sound, OUTPUT); // buzzer pin output
Serial.begin(9600); // Serial Communication is starting with 9600 of baudrate speed
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //clear trig pin(along with previous line)
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); //turn on trig pin for 10 microseconds to send out sound wave (along with previous lines)
  duration = pulseIn(echoPin, HIGH); // get raw datal
  distance = duration * 0.034 / 2; //display distance(an)
  if(distance < 100){ // if to close
  val = 20000 - map(distance, 0, 100, 2000, 4000); //set frequency
  tone(sound, val); //output
  }
  delay(500); //delay for 500 milliseconds
}
