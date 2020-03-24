#include "HumidityRelay.h"

#define RELAY_PIN   2
#define HUMIDITY   55

/* Normal constructor */
HumidityRelay ctr(RELAY_PIN, HUMIDITY);

/* No pin constructor */
//HumidityRelay ctr(HUMIDITY);

void setup() {
    /* Reverse: On = LOW, Off = HIGH */
    //ctr.reverse(true);

    /* Mode: 0 = Cool, 1 = Heat; Default Cool */
    //ctr.mode(MODE_HEAT);
}

void loop() {
    float humidity = 44.62;

    /* Signal the timer on each pass of loop() */
    ctr.process(humidity);

    /* Factor is +/- of the enactment humidity, defaults to 1 */
    ctr.factor(3);
    uint8_t factor = factor();

    /* Check the current state of the relay */
    bool state = ctr.state();

    /* Check reverse state */
    bool reversed = ctr.reverse();
    
    /* Get the on or off humidity */
    uint8_t onHum  = ctr.onHum();
    uint8_t offHum = ctr.offHum();

    /* Set the on and off temps */
    ctr.onHum(ON_HUM);
    ctr.offHum(OFF_HUM);

    /* Get/set the relay pin */
    int8_t = ctr.pin();
    //ctr.pin(RELAY_PIN);

    /* Disable the relay */
    //ctr.pin(-1);
}
