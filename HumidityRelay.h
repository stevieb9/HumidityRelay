#ifndef HUMIDITYRELAY_H
#define HUMIDITYRELAY_H

#include "Arduino.h"
#include "../ArduinoRelay/ArduinoRelay.h"

#define MODE_HUMIDIFY   true
#define MODE_DEHUMIDIFY false

using namespace std;

class HumidityRelay : public ArduinoRelay {

    private:
        uint8_t _onHum  = 0;
        uint8_t _offHum = 0;
        uint8_t _mode   = true; // true=humidify, false=dehumidify
        uint8_t _factor  = 1;

    public:
        HumidityRelay(int8_t pin, uint8_t hum);
        HumidityRelay(uint8_t hum);

        uint8_t onHum () { return _onHum; }
        uint8_t onHum (uint8_t onHum) { _onHum = onHum; return _onHum; }

        uint8_t offHum () { return _offHum; }
        uint8_t offHum (uint8_t offHum) { _offHum = offHum; return _offHum; }

        uint8_t mode () { return _mode; }
        uint8_t mode (uint8_t mode) { _mode = mode; return _mode; }

        uint8_t factor () { return _factor; }
        uint8_t factor (uint8_t factor) { _factor = factor; return _factor; }

        void process (float humidity);
};

#endif

