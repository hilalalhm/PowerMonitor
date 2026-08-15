#ifndef PZEM_SENSOR_H
#define PZEM_SENSOR_H

#include <PZEM004Tv30.h>

struct PowerData {
    float voltage = 0.0;
    float current = 0.0;
    float power = 0.0;
    float energy = 0.0;
    float frequency = 0.0;
    float pf = 0.0;
};

// PZEM (RX2 Pin 16, TX2 Pin 17)
PZEM004Tv30 pzem(Serial2, 16, 17);

void updatePZEMData(PowerData &data) {
    float v = pzem.voltage();
    float i = pzem.current();
    float p = pzem.power();
    float e = pzem.energy();
    float f = pzem.frequency();
    float pfVal = pzem.pf();

    if (isnan(v)) {
        data.voltage = 0;
        data.current = 0;
        data.power = 0;
        data.energy = 0;
        data.frequency = 0;
        data.pf = 0;
    } else {
        data.voltage = v;
        data.current = i;
        data.power = p;
        data.energy = e;
        data.frequency = f;
        data.pf = pfVal;
    }
}

#endif