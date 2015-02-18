#include <Servo.h>

Servo servo_x,servo_y;

int sensorPin = A0; 
int sensorValue = 0;
int distanceEst = 0;
int posX = 0;
int posY = 0;
int servoDelay = 25;


void setup() {
  Serial.begin(9600);
  servo_x.attach(9);
  servo_y.attach(10);
}

void loop() {
  Serial.print("begining");
  for(posX = 65; posX <= 115; posX += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo_x.write(posX);    // tell servo to go to position in variable 'pos'
    delay(servoDelay);                       // waits 15ms for the servo to reach the position 
  }
  for(posX = 115; posX>=65; posX -=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo_x.write(posX);    // tell servo to go to position in variable 'pos' 
    delay(servoDelay);                       // waits 15ms for the servo to reach the position
    for(posY = 0; posY <= 80; posY += 1) // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      servo_y.write(posY);
      sensorValue = analogRead(A0);
      distanceEst = estimateDistance(sensorValue);
      Serial.print(posX);
      Serial.print(",");
      Serial.print(posY);
      Serial.print(",");
      Serial.println(distanceEst);      // tell servo to go to position in variable 'pos' 
      delay(servoDelay);                       // waits 15ms for the servo to reach the position 
    }
    servo_y.write(0);
    delay(servoDelay);
  }
  Serial.print("done");
  delay(1000); 
}

/**
  Distance = -16.122034*log(x) + 109.105113
**/
double estimateDistance(int val){
  double estimate = -1;
  estimate = -16.122034*log(val) + 109.105113;
  if((estimate > 50) || (estimate == 0)) estimate = -1;
  return estimate;
}
