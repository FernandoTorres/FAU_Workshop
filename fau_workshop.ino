// Workshop FAU 23.04.2013

#include <Servo.h> 

Servo firstServo;  // create servo object to control a servo 
Servo secondServo; // a maximum of eight servo objects can be created 

//------------------------------------------------------------------------------------------------------
// Edit this block -------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

int centerPos = 90;   // servo movement center point 
int amplitude = 30;   // degrees each servo is going to move from the initial position

int delayStep = 30;   // time given to the servo to update its position (NOT SPEED!)

boolean directMov = true;   // true | false : Direct Movement (both servos moving in the same direction or not)

//------------------------------------------------------------------------------------------------------
// Block End -------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

int firstInit, secondInit, count;

void setup() // THIS PART IS ONLY RUN ONCE
{ 
  firstServo.attach(9);    // attaches the servo on pin 9 to the servo object 
  secondServo.attach(11);  // attaches the servo on pin 11 to the servo object

  // Set initial positions
  if (directMov) {
    firstInit = centerPos - amplitude;
    secondInit = centerPos - amplitude;
    
    firstServo.write(firstInit);
    secondServo.write(secondInit);
  }
  else {
    firstInit = centerPos - amplitude;
    secondInit = centerPos + amplitude;
  }
} 

void loop() // THIS PART REPEATS ON TIME
{
  firstServo.write(firstInit);
  secondServo.write(secondInit);
  
  // Direct Movement
  if (directMov){    
    for (count = 0; count <= 2 * amplitude; count += 1){
      firstServo.write(firstInit + count);
      secondServo.write(secondInit + count);
      delay(delayStep);
    }
    delay(delayStep);
    for (count = 0; count <= 2 * amplitude; count += 1){
      firstServo.write(firstInit + 2 * amplitude - count);
      secondServo.write(secondInit + 2 * amplitude - count);
      delay(delayStep);
    }
    delay(delayStep);
  }
  // Inverse movement
  else {
    for (count = 0; count <= 2*amplitude; count += 1) {
      firstServo.write(firstInit + count);
      secondServo.write(secondInit - count);
      delay(delayStep);
    }
    delay(delayStep);
    for (count = 0; count <= 2*amplitude; count += 1){
      firstServo.write(firstInit + 2*amplitude - count);
      secondServo.write(secondInit - 2*amplitude + count);
      delay(delayStep);
    }
    delay(delayStep);
  }
}
 



