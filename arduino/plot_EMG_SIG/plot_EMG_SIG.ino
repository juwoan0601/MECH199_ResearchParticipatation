/* 
[MECH199-01] Freshman Reaserch Participation 
Materials: Arduino Uno(MCU board), Myoware V1.0(sEMG sensor)
Summary: Plot sEMG sensor processed signal(amplifierd-ractified) using serial plotter

March. 21st. 2024. 
Ju Wan Han in MARCH Lab. (march.postech.ac.kr) 
Department of Mechanical Engineering, POSTECH
E-mail: han0601@postech.ac.kr
*/

//========== PIN MAP ==========
#define PIN_SIG      A0        // sEMG sensor processed signal pin
//========== PIN MAP ==========

void setup() {
  Serial.begin(4800);           // start serial communication
}

void loop() {
  int sEMG_RAW = analogRead(PIN_SIG);   // read sEMG value from sEMG sensor

  // print for arduino serial plotter
  Serial.print(-1023);      // print the lowest value
  Serial.print(",");        // print separator of valuse
  Serial.print(1023);       // print the highest value
  Serial.print(",");        // print separator of valuse
  Serial.println(sEMG_SIG); // print the sensor processed input value

  delay(1);                 // delay 1 ms for stablility
}
