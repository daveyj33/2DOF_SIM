#include <Servo.h>
// Create servo object to control a servo
Servo myservo1; 
Servo myservo2;
// Variables
float a2 = 1;
float a4 = 1;
float X;
float Y;
float xt;
float yt;
float t;
float phi1, phi2, phi3, r1, T1, T2, theta1, theta2;


void setup() {
  Serial.begin(9600);
  myservo1.attach(18);  // Attach Servos
  myservo2.attach(17);
  }

void loop() {

  t = (t + .01);
  if (t <= 1) {
    Serial.println("What is the value of X?");
  while (Serial.available() == 0) {}
  X = Serial.parseFloat();
    Serial.println("What is the value of Y?");
  while (Serial.available() == 0) {}
  Y = Serial.parseFloat();
  delay(500);
    //Serial.print("t=");
    //Serial.println(t);
    xt = X * t;
    yt = Y * t;
    r1 = sqrt(xt * xt + yt * yt);
    phi1 = acos(((a4 * a4) - (a2 * a2) - (r1 * r1)) / (-2 * a2 * r1));
    phi2 = atan2(yt, xt);
    phi3 = acos(((r1 * r1) - (a2 * a2) - (a4 * a4)) / (-2 * a2 * a4));
    //Theta 1 in radians
    T1 = phi2 - phi1;
    //Theta2 is (180 degrees - angle phi3)
    T2 = 3.14 - phi3;
    //Theta in Degrees
    T1 = T1 * (180 / 3.14);
    T2 = T2 * (180 / 3.14);
    //Print calculated angles
    Serial.print("T1=");
    Serial.print(T1);
    Serial.print("\t");
    Serial.print("T2=");
    Serial.print(T2);
    // Angles adjusted within servo span
    theta1 = 180 - T1;
    theta2 = 90 - T2;
   //Send command to servo to 
    myservo1.write(theta1);
    myservo2.write(theta2);
  }

  else {
    Serial.println("Program Ended");
    delay(2000);
  }
}
