#include <avr/io.h> 
#include <util/delay.h>

const uint8_t p13 = 1 << PB5;
const uint8_t p12 = 1 << PB4;
const uint8_t p11 = 1 << PB3;

uint8_t pins[] = {p13, p12, p11};

const int delayTime = 500;

int main() {

    for (int i=0; i < sizeof(pins); i++) {
        DDRB |= pins[i];    
    }

    while (1) {
        for (int i=0; i < sizeof(pins); i++) {
            PORTB ^= pins[i];
            _delay_ms(delayTime);
            PORTB ^= pins[i];
        }
    }
}