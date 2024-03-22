/* 
[MECH199-01] Freshman Reaserch Participation 
Materials: Arduino Uno(MCU board), Myoware V1.0(sEMG sensor)
Summary: Send sEMG sensor signal(amplifierd-ractified) to PC (use pyserial module to recieve it)
*this code can be use for testing communication between arduino and pyserial module of PC

March. 21st. 2024. 
Ju Wan Han in MARCH Lab. (march.postech.ac.kr) 
Department of Mechanical Engineering, POSTECH
E-mail: han0601@postech.ac.kr
*/

//========== PIN MAP ==========
#define PIN_SIG      A0        // sEMG sensor signal pin
//========== PIN MAP ==========

void setup() {
  Serial.begin(115200);           // start serial communication
}

void loop() {
  int sEMG_SIG = analogRead(PIN_SIG);   // read sEMG value from sEMG sensor

  Serial.println(sEMG_SIG);   // send sEMG signal value through serial communication without any encoding

  delay(1);                   // delay 1 ms for stablility
}
