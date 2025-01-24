## New GLDAB by Arduino with convert PPM to PWM signal output

![230711-2 Pterasaur3small](/image/230711-2%20Pterasaur3small%20.jpg)

I've added code that converts PPM signals to PWM signals to the New GLDAB by Arduino.

New GLDAB by Arduino modified to receive ppm signal from RX and output PWM signal.

This allows you to use a small 1g receiver without using a large RX.

This makes it possible to create a lightweight Ornithopter using a small ppm output receiver.

PWM output is 8ch.

### How New GLDAB by Arduino with convert PPM to PWM signal output works

![250117 NewGLDAB Action ](/image/250117%20NewGLDAB%20Action%20.jpg)

Set the Throttle (3ch) to under 950 msec and over 1950 msec.

When using a new ESC, please set the ESC's operating range with New GLDAB removed before doing the following.

#### Setting of Pre Glide Motor Speed:
1. Disconnect ESC and battery
2. Throttle stick to max high position
3. Connect the ESC and battery -- The motor does not move, the LED turns on (lights up) once, then goes out.
After that, the LED turns on again.
4. Set the throttle to the lowest setting while the LED is ON--LED turns off and then turns ON (lights up) again.
5. While the LED is ON, set the throttle position to the speed at which you want the motor to move (Pre Glide Motor Speed: the speed at which the motor moves in 1 second after the throttle lever is set to the lowest position until the magnet is detected and the motor stops). 
6. When the motor stops (the set position is memorized) and the LED is flashing, lower the throttle to the lowest position.
7. When the LED stops blinking, it will return to normal mode.

#### How New GLDAb by Arduino works 

  1. ThrottleUp -- Motor Run
  2. Throttle max Low
  3. Red LED on and Motor Run on Setup speed
  4. After 1 second, Motor stops 

     The PreGlide time (the time the motor continues to run
     
      after the throttle stick is at its lowest position) is about 1 second.

    The PreGlide time can be changed by changing the i value.

    PreGlide time is approximately 1 second for Line88 "i<140" and Line103 "i=140".
    
    For longer PreGlide time increse i value ex. "i<200" and "i = 200".
      
  5. When Magnet passes magnet sensor,
                                 Red LED off and Motor stops
 When Magnet sensor contact magnet, 
           motor stops at max Low position of Throttle 

------If the above acts, GLDAB acts normally.




![241108 PPM toPWM & Arduino GLDAB by Arduino 4.7KOwm ESC Motor ](/image/241108%20PPM%20toPWM%20&%20Arduino%20GLDAB%20by%20Arduino%204.7KOwm%20ESC%20Motor%20.jpg)


YouTube--Making of Convert PPM signal to PWM and GLDAB for Gliding by Arduino board (Arduino pro mini)
        https://www.youtube.com/watch?v=hw5doqiESM8

The preglide time (the time the motor continues to run after the throttle stick is at its lowest position) is 0.35 seconds. (For use with small Ornithopters)
The preglide time can be changed by changing the i value.
The preglide time is approximately 0.35 seconds for Line148"i<10000" and Line 180 and 183 "i=10000".
When increasing the preglide time, increase the i value.
For example, "i<12000" and "i=12000".



### Need:

Arduino pro mini board

4.7KOhms resistor

Panasonic Hall Sensor IC DN6852-A
  
#### -------- (If you use Panasonic Hall Sensor IC DN6851, Change "val == 1" to "val == 0" in Line 180.)

Small neodymium magnet

#### ---------Set magnet so that the south pole faces the side with the Panasonic Hall Sensor IC part lettering.

Samll ppm output Receiver (1-2g)


### converting ppm signal to PWM signal (8ch) with GLDAB
select --  sketch_241109ppmtopwmRXwithGLDAB

### Only converting ppm signal to PWM signal (8ch) without GLDAB
select --  sketch_241110PPMtoPWM8ch_2


### Small Ornithopter(under 99g) using this device
#### Sterna139  
https://www.youtube.com/playlist?list=PLErvdRrwWuPqqPNT8EL3EupDDEEbGsFk_


#### Kestrel140   
 https://www.youtube.com/playlist?list=PLErvdRrwWuPooMZb0lnvFqdUjO2XE5KBm





## reference

How New GLDAB Works
http://kakutaclinic.life.coocan.jp/GLDAB.htm


New GLDAB by Arduino Pro mini
http://kakutaclinic.life.coocan.jp/GLDABArd.html
https://github.com/KazuKaku/NewGLDAB-by-Arduino


How New GLDAB by Arduino Pro mini works
YouTube Video https://www.youtube.com/watch?v=KpQxz6biprs

