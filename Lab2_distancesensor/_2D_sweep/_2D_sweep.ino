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
  for(posX = 0; posX <= 180; posX += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    servo_x.write(posX);              // tell servo to go to position in variable 'pos' 
    delay(servoDelay);                       // waits 15ms for the servo to reach the position 
  }
  for(posX = 180; posX>=0; posX -=1)     // goes from 180 degrees to 0 degrees 
  {                                
    servo_x.write(posX);              // tell servo to go to position in variable 'pos' 
    delay(servoDelay);                       // waits 15ms for the servo to reach the position
    for(posY = 45; posY <= 135; posY += 1) // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      servo_y.write(posY);              // tell servo to go to position in variable 'pos' 
      delay(servoDelay);                       // waits 15ms for the servo to reach the position 
    } 
    for(posY = 90; posY <= 45; posY -= 1) // goes from 0 degrees to 180 degrees 
    {                                  // in steps of 1 degree 
      servo_y.write(posY);              // tell servo to go to position in variable 'pos' 
      delay(servoDelay);                       // waits 15ms for the servo to reach the position 
      //measure angle 
      sensorValue = analogRead(sensorPin);
      distanceEst = estimateDistance(sensorValue);
      Serial.print("posX: "); 
      Serial.print(posX);
      Serial.print("posY: "); 
      Serial.print(posY);  
      Serial.print(", raw input: "); 
      Serial.print(sensorValue); 
      Serial.print(", distance: "); 
      Serial.println(distanceEst);
    }
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
