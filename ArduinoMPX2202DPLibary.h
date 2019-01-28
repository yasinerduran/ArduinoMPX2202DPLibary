#define ArduinoMPX2202DPLibary_H
#include <Arduino.h>

class MPX2202DP{
    private:
        int pin_1;
        int pin_2;
        float last_pressures [2];
        float last_pressures_bar [2];
        float referance_voltage = map(512, 0, 1024, 0, 5);
        const float bar_equal = 0.0689475729;
    public:
        MPX2202DP(int pin_1_, int pin_2_);
        void initSensor();
        float * measurePressure();
        float * measurePressureForBar();
        
};
