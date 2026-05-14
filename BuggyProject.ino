#include <Servo.h>
Servo myServo;

int enb = 3; //right motor
int in4 = 5; 
int in3 = 4;
int in2 = 8;
int in1 = 7;
int ena = 9; //left motor
int control = 10;
int echoPin = 11;
int trigPin = 6;
  
void setup() {
  //configuring digital and analog pins
  pinMode(enb, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(ena, OUTPUT);
  pinMode(control, OUTPUT);
  
  Serial.begin(9600); // initialises serial communication at baud rate 9600 bits/s
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  myServo.attach(control);
}

void moveForwards(){
  analogWrite(ena, 199); //controls speed of motors, 0-255
  analogWrite(enb, 205);

  //left motor
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //right motor
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW);
}

void moveBackwards(){
  analogWrite(ena, 255);
  analogWrite(enb, 255);

  //left motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //right motor
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
}

void turnright(){
  analogWrite(ena, 0);
  analogWrite(enb, 255);

  //left motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  //right motor
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW);
}

void turnleft(){
  analogWrite(ena, 255);
  analogWrite(enb, 255);

  //left motor
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //right motor
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
}

void halt(){
  analogWrite(ena, 0);
  analogWrite(enb, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void testmovement(){
  moveForwards();
  delay(5000); //two seconds
  moveBackwards();
  delay(5000); 
  turnleft();
  delay(5000);
  turnright();
  delay(5000);
  halt();
  delay(5000);
}

void measureDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) * 0.0343;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void move_servo(){
  myServo.write(0);
  delay(1000);

  myServo.write(90);
  delay(1000);

  myServo.write(180);
  delay(1000);
}

void loop() {
  moveForwards();
}
