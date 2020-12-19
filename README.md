# Building_An_Embedded_System_Arduino
This repository contains a simple embedded system using Arduino UNO.

## Goal
The goal of this work is to become familiar with the Arduino environment to drive simple actuators (in this case LEDs).

## System
This embedded system uses Arduino UNO board to control 4 LEDs with different colors. In normal operation, in each 5 seconds period the system will have the the following pattern of activity, with, at most, only one LED active at a time (1 second slots):

1. Red LED ON
2. Green LED ON
3. Blue LED ON
4. Yellow LED ON
5. All LEDs OFF

This behavior is then repeated. ```Circuit.png``` represents the circuit to drive the LEDs to be assembled. 

### Extended Feature
After the implementation of the system described earlier, a new feature was developed: interface the circuit to a press button. Whenever the button is pressed (OFF → ON → OFF) the LED activated at the moment must remain ON (before, in stage 5, the system stops with all LEDs OFF). With the system stopped it is easier to read the voltage drop on each LED. When the button is pressed again the system will continue its normal operation sequence.
