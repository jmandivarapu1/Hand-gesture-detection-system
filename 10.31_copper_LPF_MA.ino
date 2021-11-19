#include <CapacitiveSensor.h>
#include <math.h>
#define num 20

CapacitiveSensor pin_2_3 = CapacitiveSensor(3,2); //recv2_red, send3_resist 
CapacitiveSensor pin_5_6 = CapacitiveSensor(6,5); 
CapacitiveSensor pin_8_9 = CapacitiveSensor(9,8); 
CapacitiveSensor pin_11_12 = CapacitiveSensor(12,11); 


double sequence = 0;

float sensitivity = 0.1;

int F_sensor_A;
int F_sensor_B;
int F_sensor_C;
int F_sensor_D;

float s1[num];
float s2[num];
float s3[num];
float s4[num];

void setup() {
  Serial.begin(19200);
  F_sensor_A = pin_2_3.capacitiveSensor(30);
  F_sensor_B = pin_5_6.capacitiveSensor(30);
  F_sensor_C = pin_8_9.capacitiveSensor(30);
  F_sensor_D = pin_11_12.capacitiveSensor(30);
}

void loop() {
  sequence++;
  for (int i=0; i<num-1; i++){
      s1[i] = s1[i+1];
      s2[i] = s2[i+1];
      s3[i] = s3[i+1];
      s4[i] = s4[i+1];
    }
    
  s1[num-1] = pin_2_3.capacitiveSensor(30);
  s2[num-1] = pin_5_6.capacitiveSensor(30);
  s3[num-1] = pin_8_9.capacitiveSensor(30);
  s4[num-1] = pin_11_12.capacitiveSensor(30);  
  
  F_sensor_A = F_sensor_A * (1-sensitivity) + s1[num-1] * sensitivity;
  F_sensor_B = F_sensor_B * (1-sensitivity) + s2[num-1] * sensitivity;
  F_sensor_C = F_sensor_C * (1-sensitivity) + s3[num-1] * sensitivity;
  F_sensor_D = F_sensor_D * (1-sensitivity) + s4[num-1] * sensitivity;
  
  for (int i=0;i<num;i++){
    F_sensor_A += s1[i];
    F_sensor_B += s2[i];
    F_sensor_C += s3[i];
    F_sensor_D += s4[i];
    }
  
  F_sensor_A /= num;
  F_sensor_B /= num;
  F_sensor_C /= num;
  F_sensor_D /= num;

 
  if (sequence > num) {
    Serial.print(F_sensor_A+10000);
    Serial.print("\t");
    Serial.print(F_sensor_B+10000);
    Serial.print("\t");
    Serial.print(F_sensor_C+10000);
    Serial.print("\t");
    Serial.println(F_sensor_D+10000);
    //Serial.print("\t");
    //Serial.println(sequence+5000000); //5000000 => takes 40*60*60*24 = around one and a half day 
   }
}
