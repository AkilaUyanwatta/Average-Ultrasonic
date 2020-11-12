const int pingPin = 6; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 7; // Echo Pin of Ultrasonic Sensor

int dist[6]={0,0,0,0,0,0}; //distance array
long distance=0; //sum of dist array
long result; //average distance
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT); 
}

void loop() {
   long cm,duration, inches;   
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);
   
   for(int i = 6-1; i > 0; i--){
    dist[i] = dist[i-1];
    }
    dist[0]=cm;
    distance+=cm;
    distance-=dist[5];
    result=distance/6;
    Serial.println(result);

}

long microsecondsToCentimeters(long microseconds) { //converts time to cm
   return microseconds / 29 / 2;
}
