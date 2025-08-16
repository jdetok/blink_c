#include <avr/io.h> 
#include <util/delay.h>

// assign variables to represent arduino digital pins
// this template example blinks three LEDs 
// if only doing blink for on board LED, only init p13 (1 << PB5)
const uint8_t p13 = 1 << PB5;
const uint8_t p12 = 1 << PB4;
const uint8_t p11 = 1 << PB3;

// append pins to an array (only p13 if blink)
uint8_t pins[] = {p13, p12, p11};

// delay time between blinks
const int delayTime = 500;

int main() {
    // setup the pins as outputs
    for (int i=0; i < sizeof(pins); i++) {
        DDRB |= pins[i];
    }

    // loop runs forever
    while (1) {
        // each pin turn on, wait for delayTime, turn off
        for (int i=0; i < sizeof(pins); i++) {
            PORTB ^= pins[i];
            _delay_ms(delayTime);
            PORTB ^= pins[i];
        }
    }
}

/*
// ON BOARD LED (digital pin 13) EXAMPLE
const uint8_t p13 = 1 << PB5;
int main() {
    // setup the pins as outputs
    DDRB |= p13;

    // loop runs forever
    while (1) {
        PORTB ^= p13;
        _delay_ms(delayTime);
        PORTB ^= p13;
    }
}
*/