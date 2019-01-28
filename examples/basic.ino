#include "ArduinoMPX2202DPLibary.h"

MPX2202DP pressureSensor(A6, A7);
void setup(){
    Serial.begin(115200);
    pressureSensor.initSensor();
}

void loop(){
    float * measurement = pressureSensor.measurePressure();
    Serial.println(measurement[0]);
    Serial.println(measurement[1]);
    delete(measurement);
    delay(1000);

}
