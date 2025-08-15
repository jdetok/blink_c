#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    DDRB |= (1 << PB5);

    while (1) {
        PORTB ^= (1 << PB5);
        _delay_ms(500);
    }
}

// int main() {
//   // initialize digital pin LED_BUILTIN as an output.
//   DDRB = 0xff;
//   while (true) {
//     PINB = 0xff;
//     for (long i = 0; i < 500000; i++) {
//       asm("");
//     }
//   }
// }