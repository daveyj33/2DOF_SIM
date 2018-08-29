#include <Servo.h>
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// put your setup code here, to run once:
// variable to store the servo position
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
  myservo1.attach(18);  // attaches the servo on pin 9 to the servo object
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
    //Serial.print("r1=");
    //Serial.println(r1);
    phi1 = acos(((a4 * a4) - (a2 * a2) - (r1 * r1)) / (-2 * a2 * r1));
    phi2 = atan2(yt, xt);
    phi3 = acos(((r1 * r1) - (a2 * a2) - (a4 * a4)) / (-2 * a2 * a4));
    /*T1 is Theta 1 in radians
      Serial.print("phi1=");
      Serial.println(phi1);
      Serial.print("phi2=");
      Serial.println(phi2);
      Serial.print("phi3=");
      Serial.println(phi3);
    */
    T1 = phi2 - phi1;
    //T2 is (180 degrees - angle phi3)
    T2 = 3.14 - phi3;
    //Vector coordinates of the linkage
    //Theta in Degrees
    T1 = T1 * (180 / 3.14);
    T2 = T2 * (180 / 3.14);
    //Plot end effector
    Serial.print(T1);
    Serial.print("     ");
    Serial.println(T2);
    theta1 = 180 - T1;
    theta2 = 90 - T2;

    myservo1.write(theta1);
    myservo2.write(theta2);
  }

  else {
    Serial.println("Program Ended");
    delay(2000);
  }
}
