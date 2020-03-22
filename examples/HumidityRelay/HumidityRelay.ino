#include "TemperatureRelay.h"

#define RELAY_PIN   2
#define TEMP   78

/* Normal constructor */
TemperatureRelay ctr(RELAY_PIN, TEMP);

/* No pin constructor */
//TemperatureRelay ctr(TEMP);

void setup() {
    /* Optionally set a name for the object */
    ctr.name("CTR");

    /* Reverse: On = LOW, Off = HIGH */
    //ctr.reverse(true);

    /* Mode: 0 = Cool, 1 = Heat; Default Cool */
    //ctr.mode(MODE_HEAT);
}

void loop() {
    float tempF = 77.28;

    /* Signal the timer on each pass of loop() */
    ctr.process(tempF);

    /* Factor is +/- of the enactment temp, defaults to 1 */
    ctr.factor(3);
    uint8_t factor = factor();

    /* Check the current state of the pin */
    bool state = ctr.state();

    /* Check reverse state */
    bool reversed = ctr.reverse();
    
    /* Get the name of the object */
    char* name = ctr.name();

    /* Get the on or off temp */
    uint8_t onTemp  = ctr.onTemp();
    uint8_t offTemp = ctr.offTemp();

    /* Set the on and off temps */
    ctr.onTemp(ON_TEMP);
    ctr.offTemp(OFF_TEMP);

    /* Get/set the relay pin */
    int8_t = ctr.pin();
    //ctr.pin(RELAY_PIN);

    /* Disable the relay */
    //ctr.pin(-1);
}
