#define echoPin 2
#define trigPin 3
#define servoPin 9
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


// defines variables
long duration;
int distance; 
int servo_position = 0;    // variable to store the servo position
int servo_step = 30;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin); 
  Serial.begin(9600);
}
int measure_distance(){
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);   // Measure duration of HIGH signal in microseconds

  distance = duration * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

void loop() {

   for (servo_position = 0; servo_position <= 180; servo_position += servo_step) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(servo_position);              // tell servo to go to position in variable 'pos'
    measure_distance();
    delay(15*servo_step);                       // waits 15ms for the servo to reach the position
  }
  for (servo_position = 180; servo_position >= 0; servo_position -= servo_step) { // goes from 180 degrees to 0 degrees
    myservo.write(servo_position);              // tell servo to go to position in variable 'pos'
    measure_distance();
    delay(15*servo_step);                       // waits 15ms for the servo to reach the position
  }
  
}




