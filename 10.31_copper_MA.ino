#include <CapacitiveSensor.h>

#define num 20

CapacitiveSensor pin_2_3 = CapacitiveSensor(3,2); //recv2_red, send3_resist 
CapacitiveSensor pin_5_6 = CapacitiveSensor(6,5); 
CapacitiveSensor pin_8_9 = CapacitiveSensor(9,8); 
CapacitiveSensor pin_11_12 = CapacitiveSensor(12,11); 

double sequence = 0;
int sensor_A;
int sensor_B;
int sensor_C;
int sensor_D;

int sensor_A_MA = 0;
int sensor_B_MA = 0;
int sensor_C_MA = 0;
int sensor_D_MA = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sequence++;
  sensor_A = pin_2_3.capacitiveSensor(30);
  sensor_B = pin_5_6.capacitiveSensor(30);
  sensor_C = pin_8_9.capacitiveSensor(30);
  sensor_D = pin_11_12.capacitiveSensor(30);
  
  sensor_A_MA = sensor_A_MA + sensor_A; 
  sensor_B_MA = sensor_B_MA + sensor_B; 
  sensor_C_MA = sensor_C_MA + sensor_C; 
  sensor_D_MA = sensor_D_MA + sensor_D;

  if (sequence % num == 0){
    sensor_A_MA = sensor_A_MA / 20;
    sensor_B_MA = sensor_B_MA / 20;
    sensor_C_MA = sensor_C_MA / 20;
    sensor_D_MA = sensor_D_MA / 20;
   }
    
  
  Serial.print(sensor_A+10000);
  Serial.print("\t");
  Serial.print(sensor_B+10000);
  Serial.print("\t");
  Serial.print(sensor_C+10000);
  Serial.print("\t");
  Serial.print(sensor_D+10000);
  Serial.print("\t");
  Serial.println(sequence+5000000); //5000000 => takes 40*60*60*24 = around one and a half day
}
