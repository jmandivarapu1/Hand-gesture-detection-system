#include <CapacitiveSensor.h>

CapacitiveSensor pin_2_3 = CapacitiveSensor(3,2); //recv2_red, send3_resist 
CapacitiveSensor pin_5_6 = CapacitiveSensor(6,5); 
CapacitiveSensor pin_8_9 = CapacitiveSensor(9,8); 
CapacitiveSensor pin_11_12 = CapacitiveSensor(12,11); 
double sequence = 0;
int sensor_A;
int sensor_B;
int sensor_C;
int sensor_D;
float sensitivity = 0.1;
int F_sensor_A;
int F_sensor_B;
int F_sensor_C;
int F_sensor_D;

void setup() {
  Serial.begin(19200);
  sensor_A = pin_2_3.capacitiveSensor(30);
  sensor_B = pin_5_6.capacitiveSensor(30);
  sensor_C = pin_8_9.capacitiveSensor(30);
  sensor_D = pin_11_12.capacitiveSensor(30);

  F_sensor_A = sensor_A;
  F_sensor_B = sensor_B;
  F_sensor_C = sensor_C;
  F_sensor_D = sensor_D;
  
}

void loop() {
  sequence++;
  sensor_A = pin_2_3.capacitiveSensor(30);
  sensor_B = pin_5_6.capacitiveSensor(30);
  sensor_C = pin_8_9.capacitiveSensor(30);
  sensor_D = pin_11_12.capacitiveSensor(30);

  F_sensor_A = F_sensor_A * (1-sensitivity)+sensor_A*sensitivity;
  F_sensor_B = F_sensor_B * (1-sensitivity)+sensor_B*sensitivity;
  F_sensor_C = F_sensor_C * (1-sensitivity)+sensor_C*sensitivity;
  F_sensor_D = F_sensor_D * (1-sensitivity)+sensor_D*sensitivity;

  Serial.print(F_sensor_A+10000);
  Serial.print("\t");
  Serial.print(F_sensor_B+10000);
  Serial.print("\t");
  Serial.print(F_sensor_C+10000);
  Serial.print("\t");
  Serial.print(F_sensor_D+10000);
  Serial.print("\t");
  Serial.println(sequence+5000000); //5000000 => takes 40*60*60*24 = around one and a half day
}
