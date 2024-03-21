#include <avr/io.h>
#include <util/delay.h>

int main() {
   // Set PB1, PB2, and PB3 as output for controlling LEDs
   DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3);

   while (1) {
        // Hi-hat 1 (white LED - PB2) before the kick
        PORTB |= (1 << PB2);
        _delay_ms(58); // 128 BPM

        // Turn off white LED (PB2)
        PORTB &= ~(1 << PB2);
        _delay_ms(58); // 128 BPM

        // Kick (blue LED - PB3) on every first beat
        PORTB |= (1 << PB3);
        _delay_ms(234); // 128 BPM

        // Turn off blue LED (PB3)
        PORTB &= ~(1 << PB3);
        _delay_ms(234); // 128 BPM

        // Hi-hat 2 (white LED - PB2) between kick and snare
        PORTB |= (1 << PB2);
        _delay_ms(58); // 128 BPM

        // Turn off white LED (PB2)
        PORTB &= ~(1 << PB2);
        _delay_ms(58); // 128 BPM

        // Snare (red LED - PB1) on every second beat
        PORTB |= (1 << PB1);
        _delay_ms(234); // 128 BPM

        // Turn off red LED (PB1)
        PORTB &= ~(1 << PB1);
        _delay_ms(234); // 128 BPM

        // Hi-hat 3 (white LED - PB2) after the snare
        PORTB |= (1 << PB2);
        _delay_ms(58); // 128 BPM

        // Turn off white LED (PB2)
        PORTB &= ~(1 << PB2);
        _delay_ms(58); // 128 BPM
    }

    return 0;
}
