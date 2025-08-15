#include <avr/io.h> 
#include <util/delay.h>

const uint8_t p13 = 1 << PB5;
const uint8_t p12 = 1 << PB4;
const uint8_t p11 = 1 << PB3;

uint8_t pins[] = {p13, p12, p11};

const int delayTime = 500;

int main() {

    DDRB |= p13;
    DDRB |= p12;
    DDRB |= p11;

    while (1) {
        PORTB ^= p13;
        _delay_ms(delayTime);
        PORTB ^= p12;
        _delay_ms(delayTime);
        PORTB ^= p11;
        _delay_ms(delayTime);
    }
}