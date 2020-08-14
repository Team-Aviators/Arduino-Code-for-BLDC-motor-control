/*
        Arduino Brushless Motor Control
     by Dejan, https://howtomechatronics.com
*/

#include <Servo.h>
//#include <MPU6050.h>
#include <Wire.h>

//MPU6050 mpu;
Servo ESC;     // create servo object to control the ESC

int potValue;  // value from the analog pin 
                                //unsigned long timer = 0;
                                //float timeStep = 0.01;
                                //
                                //float pitch = 0;
                                //float roll = 0;
                                //float yaw = 0;

void setup() {
  // Attach the ESC on pin 9
  Serial.begin(9600);
  ESC.attach(9,1000,2000); // (pin, min pulse width, max pulse width in microseconds) 
                                //  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
                                //  {
                                //    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
                                //    delay(500);
                                //    }
                                //
                                //    mpu.calibrateGyro();
                                //    mpu.setThreshold(3);
  delay(2000);

}

void loop() {
  //delay(5000);
  potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  Serial.print("Pot Value:");
  Serial.println(potValue);
  ESC.write(potValue);
                                                      
                                                      //  timer = millis();
                                                      //
                                                      //  Vector norm = mpu.readNormalizeGyro();
                                                      //
                                                      //  pitch = pitch + norm.YAxis * timeStep;
                                                      //  roll = roll + norm.XAxis * timeStep;
                                                      //  yaw = yaw + norm.ZAxis * timeStep;
                                                      //
                                                      //
                                                      //  Serial.print(" Pitch = ");
                                                      //  Serial.print(pitch);
                                                      //
                                                      //  Serial.print(" roll = ");
                                                      //  Serial.print(roll); 
                                                      //
                                                      //  Serial.print(" yaw = ");
                                                      //  Serial.print(yaw);
                                                      //  
                                                      
                                                        
                                                      //  for(int i=0;i<255;i++)
                                                      // { ESC.write(i);    // Send the signal to the ESC
                                                      //  Serial.println(i);
                                                      //  delay(1000);
                                                      //  }
                                                      //    for(int i=255;i>0;i--){
                                                      //  ESC.write(i);
                                                      //   Serial.println(i);
                                                      //  delay(100); } 
                                                      //  exit(0);
}
