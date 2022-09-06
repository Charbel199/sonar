#define echoPin 2
#define trigPin 3
#define servoPin 9
#define nullptr NULL
#include <Servo.h>
#include <ros.h>
#include <std_msgs/Int8.h>
// defines variables
long duration;
int distance; 
int servo_position = 0;    // variable to store the servo position
int servo_step = 30;
Servo myservo;  // create servo object to control a servo


ros::NodeHandle nh;
void message(const std_msgs::Int8& toggle_msg){
  //Serial.print("Receuved nessage: ");
  //Serial.println(toggle_msg.data);
}
ros::Subscriber<std_msgs::Int8> sub("sonar", message);



void setup() {
  Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin); 
  nh.initNode();
  nh.subscribe(sub);

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

  //Serial.print("Distance: ");
  //Serial.print(distance);
  //Serial.println(" cm");
  return distance;
}

void loop() {
  nh.spinOnce();
//  for (servo_position = 0; servo_position <= 180; servo_position += servo_step) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(servo_position);              // tell servo to go to position in variable 'pos'
//    measure_distance();
//    delay(15*servo_step);                       // waits 15ms for the servo to reach the position
//  }
//  for (servo_position = 180; servo_position >= 0; servo_position -= servo_step) { // goes from 180 degrees to 0 degrees
//    myservo.write(servo_position);              // tell servo to go to position in variable 'pos'
//    measure_distance();
//    delay(15*servo_step);                       // waits 15ms for the servo to reach the position
//  }
  delay(500);
}





