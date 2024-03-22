/* 
[MECH199-01] Freshman Reaserch Participation 
Materials: 1 x Arduino Uno(MCU board), 2 x Myoware V1.0(sEMG sensor)
Summary: Send two sEMG sensor signal(amplifierd-ractified) to PC (use pyserial module to recieve it)
*this code can be use for "virtual gripper demo"

March. 21st. 2024. 
Ju Wan Han in MARCH Lab. (march.postech.ac.kr) 
Department of Mechanical Engineering, POSTECH
E-mail: han0601@postech.ac.kr
*/

//========== PIN MAP ==========
#define PIN_SIG1      A0        // sEMG sensor signal pin 1
#define PIN_SIG2      A1        // sEMG sensor signal pin 2
//========== PIN MAP ==========

void setup() {
  Serial.begin(115200);           // start serial communication
}

void loop() {
  int sEMG_val1 = analogRead(PIN_SIG1);       // read sEMG value from sEMG sensor
  int sEMG_val2 = analogRead(PIN_SIG2);       // read sEMG value from sEMG sensor

  String sEMG_val1_str = String(sEMG_val1);   // convert sEMG sensor value to string datatype 
  String sEMG_val2_str = String(sEMG_val2);   // convert sEMG sensor value to string datatype 

  Serial.print("<");            // send header charactor of encoding
  Serial.print(sEMG_val1_str);  // send first sEMG sensor value
  Serial.print(",");            // send separator charactor
  Serial.print(sEMG_val2_str);  // send second sEMG sensor value
  Serial.println(">");          // send footer charactor of encoding

  delay(1);                     // delay 1 ms for stablility
}
