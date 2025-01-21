# New GLDAB by Arduino with convert PPM to PWM signal output

I've added code that converts PPM signals to PWM signals to the New GLDAB by Arduino.
This makes it possible to create a lightweight Ornithopter using a small ppm output receiver.

How New GLDAB Works
http://kakutaclinic.life.coocan.jp/GLDAB.htm

250117 NewGLDAB Action

New GLDAB by Arduino Pro mini

http://kakutaclinic.life.coocan.jp/GLDABArd.html
https://github.com/KazuKaku/NewGLDAB-by-Arduino

How New GLDAB by Arduino Pro mini works

YouTube Video https://www.youtube.com/watch?v=KpQxz6biprs

The preglide time (the time the motor continues to run after the throttle stick is at its lowest position) is 0.35 seconds. (For use with small Ornithopters)
The preglide time can be changed by changing the i value.
The preglide time is approximately 0.35 seconds for Line148"i<10000" and Line 180 and 183 "i=10000".
When increasing the preglide time, increase the i value.
For example, "i<12000" and "i=12000".

New GLDAB by Arduino modified to receive ppm signal from RX and output PWM signal.

This allows you to use a small 1g receiver without using a large RX.　PWM output is 8ch.

241108 PPM toPWM & Arduino GLDAB by Arduino 4.7KOwm ESC Motor
 
## How New GLDAB by Arduino with convert PPM to PWM signal output works

YouTube--Making of Convert PPM signal to PWM and GLDAB for Gliding by Arduino board (Arduino pro mini)
        https://www.youtube.com/watch?v=hw5doqiESM8

## converting ppm signal to PWM signal (8ch) with GLDAB
sketch_241109ppmtopwmRXwithGLDAB

## Only converting ppm signal to PWM signal (8ch) without GLDAB
sketch_241110PPMtoPWM8ch_2


## Small Ornithopter(under 99g) using this device
### Sterna139  
 https://www.youtube.com/playlist?list=PLErvdRrwWuPqqPNT8EL3EupDDEEbGsFk_

### Kestrel140   
 https://www.youtube.com/playlist?list=PLErvdRrwWuPooMZb0lnvFqdUjO2XE5KBm

