/*
        Arduino Brushless Motor Control
     by Dejan, https://howtomechatronics.com
*/

#include <Servo.h>
#include <Wire.h>
#include "KalmanMPU6050.h"


Servo ESC;     // create servo object to control the ESC

int potValue;  // value from the analog pin
int flag = 0;
int output = 0;
String inString = "";
int value=0;
int toInteger() {
  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
//      Serial.print("Value:");
//      Serial.println(inString.toInt());
//      Serial.print("String: ");
//      Serial.println(inString);
      // clear the string for new input:
      value=inString.toInt();
      inString = "";
    }    
    }
    return value;
  }

  void setup() {
    // Attach the ESC on pin 9
    Serial.begin(9600);
    IMU::init();
    IMU::read();
    ESC.attach(9, 1000, 2000); // (pin, min pulse width, max pulse width in microseconds)

  }
  int initialAngle = IMU::getRoll();
  int finalAngle = 0;

  void loop() {
  toInteger();
    if (flag == 0 ) {
      finalAngle = IMU::getRoll() + 8;
      flag = 1;
    }
    //delay(5000);
    //  potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
    //  potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
    //  Serial.print("Pot Value:");
    //  Serial.print(potValue);
    //  ESC.write(potValue);

    IMU::read();
    Serial.print("  Roll:");
    Serial.println(IMU::getRoll());

    if (IMU::getRoll() == initialAngle || IMU::getRoll() <= finalAngle - 5) {
      ESC.write(output);
      output += 2;

    }
    else if (IMU::getRoll() >= finalAngle - 5) {
      ESC.write(output);
      output++;
    }
    else if (IMU::getRoll() >= finalAngle + 5) {

      while (1) {
        ESC.write(output--);
      }
    }
    else if (IMU::getRoll() == finalAngle || IMU::getRoll() >= finalAngle + 2) {
      while (1) {
        ESC.write(output);
      }
    }
//    Serial.print(toInteger());
      if (toInteger() == 1 ) {
        ESC.write(0);
        Serial.println("stopped");
        delay(500);
        exit(0);
      }
    

    delay(300);
  }
