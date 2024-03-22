/* 
[MECH199-01] Freshman Reaserch Participation 
Materials: Arduino Uno(MCU board), Myoware V1.0(sEMG sensor), HS-53(servo motor)
Summary: Use sEMG sensor signal(amplifierd-ractified) to control single servo motor

March. 21st. 2024. 
Ju Wan Han in MARCH Lab. (march.postech.ac.kr) 
Department of Mechanical Engineering, POSTECH
E-mail: han0601@postech.ac.kr
*/

//========== LIBRARY ==========
#include<Servo.h> // include servo library to control a servo motor
Servo myservo;    // create servo object to control a servo motor
//========== LIBRARY ==========

//========== USER PARAMETER ==========
#define MAX_SIG 1023            // when Vs = 5V (the power line of sensor;myoware)
//#define MAX_SIG   1023*(3.3/5.0)  // when Vs = 3.3V (the power line of sensor;myoware)
#define THRESHOLD MAX_SIG/4       // threshold to move servo motor
#define POS_EXT   20              // servo motor position to extention
#define POS_FLEX  90              // servo motor position to flextion
//========== USER PARAMETER ==========

//========== PIN MAP ==========
#define PIN_SIG      A0        // sEMG sensor signal pin
#define PIN_SERVO1   A1         // servo motor control commend pin
//========== PIN MAP ==========

void setup() {
  Serial.begin(4800);           // start serial communication
  myservo.attach(PIN_SERVO1);   // assign servo motor commend pin
}

void loop() {
  int sEMG_SIG = analogRead(PIN_SIG);               // read sEMG value from sEMG sensor

  // control stretagy: thresholding
  if (THRESHOLD < sEMG_SIG){                        // if sEMG sensor value over the threshold
    myservo.write(POS_EXT);                             // move servo motor to extention
  }
  else{                                             // if sEMG sensor value over the threshold
    myservo.write(POS_FLEX);                             // move servo motor to flexion
  }
  delay(1);                 // delay 1 ms for stablility

  // print for arduino serial plotter
  Serial.print(0);        // print the lowest value
  Serial.print(",");      // print separator of valuse
  Serial.print(MAX_SIG);  // print the highest value
  Serial.print(",");      // print separator of valuse
  Serial.println(sEMG_SIG); // print the sensor input value

  delay(1);                 // delay 1 ms for stablility
}