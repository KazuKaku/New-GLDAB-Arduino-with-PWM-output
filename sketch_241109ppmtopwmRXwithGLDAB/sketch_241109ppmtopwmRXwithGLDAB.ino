// 241109 GLDAB and PPMRX to PWM by Arduino with 4.7Kowm
//copyright Kazuhiko Kakuta Start 09-11-2024
#include <Servo.h>
#include <EEPROM.h>
#include "src/PPMReader/PPMReader.h"// <PPMReader.h>
//#include <InterruptHandler.h>// 2022/01/27 Delete for more good move
// PPMtoPWM
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
volatile int ch3value = 950;//Ch3
volatile int ch1value = 1500;//Ch1
volatile int ch2value = 1500;//Ch2
volatile int ch4value = 1500;//Ch4
volatile int ch5value = 1500;//Ch5
volatile int ch6value = 1500;//Ch6 
volatile int ch7value = 1500;//Ch7 
volatile int ch8value = 1500;//Ch8

Servo servo_1, servo_2, servo_3, servo_4, servo_5, servo_6, servo_7, servo_8; // create servo object to control a servo

//GLDAB by Arduino
volatile int PreGMS = 1300;// PreGlideMotorSpeed =900 + pgms*3  
volatile int pgms = 0;// pgms = (PreGlideMotorSpeed -900) / 3
             // int a = 0; EEPROM.write(a, pgms); pgms = EEPROM.read(a);
volatile int motorstop = 900;
int val = 0;
int a = 0;
volatile int flag = 0; // do wright of pgms in EEPROM
volatile int flag2 = 0; // do PreGM
volatile int flag3 = 0; // after setting PreGM do not only first PreGM 
const int LED1 =13;// LED on Arduino board 
const int Hole =11; // Hole Senser Detect pin set on 11pin D11

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
 
 
pinMode(LED1, OUTPUT);// Blink LED
pinMode(Hole, INPUT);//pin11 Hole senser detect pin set input
pgms = EEPROM.read(a);
PreGMS =900 + pgms*3;  
delay(2000);//Avoid abnormal positions at startup-wait 2 second until RX starts231004
}

void loop() { 
//Serial.print("flag-");  
//Serial.println(flag);
ch3value = ppm.rawChannelValue(3);//Ch3
if (( ch3value > 1950) && (flag == 0)){ 

digitalWrite(LED1, HIGH);  //RedLED ON
servo_3.writeMicroseconds(motorstop); //Motor stop pre ESC setting
//Need ESC calibration before connect new GLDAB

delay(3000); //if LED on, then set throttle stick down max low within 2second   
digitalWrite(LED1, LOW); //  LED Off   

ch3value = ppm.rawChannelValue(3);//Ch3               
if ( ch3value < 1040){  
delay(2000);//Wait 2sec 
digitalWrite(LED1, HIGH);//  while LED ON set stick at PreGlideMotorSpeed 

for (int s = 0 ; s < 1500 ; s++ ){
ch3value = ppm.rawChannelValue(3);//Ch3
servo_3.writeMicroseconds( ch3value ); 
PreGMS = ch3value; //after 4sec set motor speed now to PreGlideMotorSpeed
pgms = (PreGMS - 900) / 3; 
EEPROM.write(a, pgms);// memory pgmr in EEPROM  

//Serial.print("setPreGMS-");
//Serial.println(PreGMS);    
//Serial.print("s-");
//Serial.println(s);
}
digitalWrite(LED1, LOW);    // turn the LED off and motor stop
delay(1000);
for(int k = 0 ; k < 4  ; k++){  
servo_3.writeMicroseconds(motorstop);//Stop motor
//Serial.print("k-");
//Serial.println(k);
digitalWrite(LED1, HIGH);//End of setting of PreGlideMotorSpeed
delay(500);
digitalWrite(LED1, LOW); 
delay(500);
}    

flag = 1 ;
}
}else
{
flag = 1;


ch1value = ppm.rawChannelValue(1);//Ch1
ch2value = ppm.rawChannelValue(2);//Ch2
ch3value = ppm.rawChannelValue(3);//Ch3
ch4value = ppm.rawChannelValue(4);//Ch4
ch5value = ppm.rawChannelValue(5);//Ch5
ch6value = ppm.rawChannelValue(6);//Ch6
ch7value = ppm.rawChannelValue(7);//Ch7
ch8value = ppm.rawChannelValue(8);//Ch8

// motor move by now throttle
 servo_1.writeMicroseconds( ch1value );
 servo_2.writeMicroseconds( ch2value );
 servo_3.writeMicroseconds( ch3value );
 servo_4.writeMicroseconds( ch4value );
 servo_5.writeMicroseconds( ch5value );
 servo_6.writeMicroseconds( ch6value );
 servo_7.writeMicroseconds( ch7value );
 servo_8.writeMicroseconds( ch8value );

Serial.print("-");
Serial.println(ch3value);//Set Throttle Min <920 Max >1980 by serial monitor
if ( flag3 == 0){goto label;}
if (( ch3value < 950 ) && (flag2 == 0 )){ 
digitalWrite(LED1, HIGH);
pgms = EEPROM.read(a);
PreGMS =900 + pgms*3;    
for(int i = 0 ; i < 10000 ; i++) {  //i=10000 is about PreGlideTime 0.35second

//ch3value = ppm.rawChannelValue(3);//Ch3
ch1value = ppm.rawChannelValue(1);//Ch1
ch2value = ppm.rawChannelValue(2);//Ch2
ch4value = ppm.rawChannelValue(4);//Ch4
ch5value = ppm.rawChannelValue(5);//Ch5
ch6value = ppm.rawChannelValue(6);//Ch6
ch7value = ppm.rawChannelValue(7);//Ch7
ch8value = ppm.rawChannelValue(8);//Ch8

 servo_3.writeMicroseconds(PreGMS);//The motor runs at PreGMS speed for about 1 second
 servo_1.writeMicroseconds( ch1value );
 servo_2.writeMicroseconds( ch2value );
 servo_4.writeMicroseconds( ch4value );
 servo_5.writeMicroseconds( ch5value );
 servo_6.writeMicroseconds( ch6value );
 servo_7.writeMicroseconds( ch7value );
 servo_8.writeMicroseconds( ch8value );

//Serial.print("PreGMS--");
//Serial.println(PreGMS);
//Serial.print("i-");
//Serial.println(i);
val = digitalRead(Hole); //read pin6D6 magnet holesenser 

//Serial.print("val-");// Not delete “Serial.print("val-")” and “Serial.println(val);”
//Serial.println(val);// By repeating with these two lines 140 times, 
                //this system has a magnet detection time of about 1 second.
                // When a magnet is detected, Val=0 and the motor stops.


if ( val == 0){ i = 10000;}// When a magnet is detected, Val=0 and the motor stops
   // i value is Same number line 148 "i < 10000"
ch3value = ppm.rawChannelValue(3);//Ch3
if ( ch3value > 951 ) { i = 10000;}  // i value is Same number line 148 "i < 10000"


}
digitalWrite(LED1, LOW); 
label:
flag2=1;
flag3=1;

}
ch3value = ppm.rawChannelValue(3);//Ch3
if ( ch3value > 951 ){flag2 = 0;}
}
}//loop


