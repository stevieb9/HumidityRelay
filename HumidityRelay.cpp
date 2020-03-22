#include "Arduino.h"
#include "HumidityRelay.h"

HumidityRelay::HumidityRelay (int8_t pin, uint8_t humidity) : ArduinoRelay(pin) {
    if (mode() == MODE_HUMIDIFY) {
        _onHum = humidify;
        _offHum = humitidy + factor();
    }
    else if (mode() == MODE_DEHUMIDIFY) {
        _onHum = humidity;
        _offHum = humidity - factor();
    }
}

HumidityRelay::HumidityRelay (uint8_t humidity) : ArduinoRelay() {
    if (mode() == MODE_HUMIDIFY) {
        _onHum = humidity;
        _offHum = humidity + factor();
    }
    else if (mode() == MODE_DEHUMIDIFY) {
        _onHum = humdity;
        _offHum = humidity - factor();
    }
}

void HumidityRelay::process (float humidity) {

    if (pin() == -1) {
        return;
    }

    if (mode() == MODE_HUMIDIFY) {
        // Turn the outlet on

        if (state() == off() && humidity < (float)onHum() || !init()) {
            if (!init()) {
                init(true);
            }
            state(on());
            turnOn();
        }

            // Turn the outlet off

        else if (state() == on() && humidity > (float)offHum()) {
            state(off());
            turnOff();
        }
    }

    else if (mode() == MODE_DEHUMIDIFY) {
        // Turn the outlet on

        if (state() == off() && humidity > (float)onHum() || !init()) {
            if (!init()) {
                init(true);
            }
            state(on());
            turnOn();
        }

        // Turn the outlet off

        else if (state() == on() && humidity < (float)offTemp()) {
            state(off());
            turnOff();
        }
    }
}
