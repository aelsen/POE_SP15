#include <Servo.h>

Servo myservo;

int sensorPin = A0; 
int sensorValue = 0;
int distanceEst = 0;
int pos = 0;



void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position


    //measure angle 
    sensorValue = analogRead(sensorPin);
    distanceEst = estimateDistance(sensorValue);
    Serial.print("angle: "); 
    Serial.print(pos); 
    Serial.print(", raw input: "); 
    Serial.print(sensorValue); 
    Serial.print(", distance: "); 
    Serial.println(distanceEst);
  } 
}

/**
  Distance = -313.428369 * ln(x) + 1189.047935
**/
double estimateDistance(int pos){
	double estimate = -1;
	estimate = -313.428 * log(pos) + 1189.048;
	return estimate;
}
