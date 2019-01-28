#include "ArduinoMPX2202DPLibary.h"

MPX2202DP :: MPX2202DP(int pin_1_, int pin_2_){
    pin_1 = pin_1_;
    pin_2 = pin_2_;
}

float * MPX2202DP :: measurePressure(){
    float pin_1_voltage = map(analogRead(pin_1), 0, 1024, 0, 5);
    float pin_2_voltage = map(analogRead(pin_2), 0, 1024, 0, 5);
    
    last_pressures[0] = 25 * (((pin_1_voltage - referance_voltage)*100)/5);
    last_pressures[1] = 25 * (((pin_2_voltage - referance_voltage)*100)/5);
    
    return last_pressures;
}

float * MPX2202DP :: measurePressureForBar(){
     measurePressure();
    return {last_pressures[0]*bar_equal, last_pressures[1]*bar_equal};
}

// For the pins mode in setup loop
void MPX2202DP :: initSensor(){
    pinMode(pin_1, INPUT);
    pinMode(pin_2, INPUT);
}