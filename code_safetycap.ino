const int speakerPin = 8;
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 13;

//variables
long duration;
int distance;
int safetyDistance;

void setup () {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode (speakerPin, OUTPUT);
  Serial.begin(9600);
}
void loop () {
 
  digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 30){
  digitalWrite(speakerPin, LOW);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(speakerPin, HIGH);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
}
