//241107 ppm to pwm code 8ch-2
#include <Servo.h>
#include "src/PPMReader/PPMReader.h"// <PPMReader.h>
//#include <InterruptHandler.h>// 2022/01/27 Delete for more good move

int interruptPin = 2;
int channelAmount = 8;
PPMReader ppm(interruptPin, channelAmount);

int servo_1_pin = 3;
int servo_2_pin = 4;
int servo_3_pin = 5;
int servo_4_pin = 6;
int servo_5_pin = 7;
int servo_6_pin = 8;
int servo_7_pin = 9;
int servo_8_pin = 10;
volatile int ch3value = 1000;//Ch3
volatile int ch1value = 1500;//Ch1
volatile int ch2value = 1500;//Ch2
volatile int ch4value = 1500;//Ch4
volatile int ch5value = 1500;//Ch5
volatile int ch6value = 1500;//Ch6 
volatile int ch7value = 1500;//Ch7 
volatile int ch8value = 1500;//Ch8

Servo servo_1, servo_2, servo_3, servo_4, servo_5, servo_6, servo_7, servo_8; // create servo object to control a servo

void setup() {
  Serial.begin(9600);

pinMode(servo_1_pin, OUTPUT);
pinMode(servo_3_pin, OUTPUT);
pinMode(servo_4_pin, OUTPUT);
pinMode(servo_5_pin, OUTPUT);
pinMode(servo_6_pin, OUTPUT);
pinMode(servo_7_pin, OUTPUT);
pinMode(servo_8_pin, OUTPUT);

servo_1.attach(servo_1_pin);//output pin No
servo_2.attach(servo_2_pin);//output pin No
servo_3.attach(servo_3_pin);//output pin No
servo_4.attach(servo_4_pin);//output pin No
servo_5.attach(servo_5_pin);//output pin No
servo_6.attach(servo_6_pin);//output pin No
servo_7.attach(servo_7_pin);//output pin No
servo_8.attach(servo_8_pin);//output pin No

delay(2000);//Avoid abnormal positions at startup-wait 2 second until RX starts220306

}

void loop() {

  ch3value = ppm.rawChannelValue(3);//Ch3
  ch1value = ppm.rawChannelValue(1);//Ch1
  ch2value = ppm.rawChannelValue(2);//Ch2
  ch4value = ppm.rawChannelValue(4);//Ch4
  ch5value = ppm.rawChannelValue(5);//Ch5
ch6value = ppm.rawChannelValue(6);//Ch6
ch7value = ppm.rawChannelValue(7);//Ch7
ch8value = ppm.rawChannelValue(8);//Ch8

   servo_1.writeMicroseconds( ch1value );
 servo_2.writeMicroseconds( ch2value );
 servo_3.writeMicroseconds( ch3value );
 servo_4.writeMicroseconds( ch4value );
 servo_5.writeMicroseconds( ch5value );
 servo_6.writeMicroseconds( ch6value );
 servo_7.writeMicroseconds( ch7value );
 servo_8.writeMicroseconds( ch8value );

    //Serial.print("ch3value ");Serial.print(ch3value);
    //Serial.print(",\t"); 
    //Serial.print("ch1value ");Serial.print(ch1value);
    //Serial.print(",\t");
    //Serial.print("ch2value ");Serial.print(ch2value);
//Serial.print(",\t");
    //Serial.print("ch4value ");Serial.print(ch4value);
//Serial.print(",\t");
    //Serial.print("ch5value ");Serial.print(ch5value);
    //Serial.println(",\t");
    //Serial.print("ch6value ");Serial.print(ch6value);
    //Serial.println(",\t");
    //Serial.print("ch7value ");Serial.print(ch7value);
    //Serial.println(",\t");
    //Serial.print("ch8value ");Serial.print(ch8value);
    //Serial.println(",\t");
}

