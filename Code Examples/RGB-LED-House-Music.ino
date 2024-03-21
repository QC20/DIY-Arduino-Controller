#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLUE_LED PB1
#define RED_LED PB2
#define WHITE_LED PB3

volatile uint8_t beat_count = 0;

ISR(TIMER0_COMPA_vect) {
    beat_count++;
}

void initTimer() {
    TCCR0A = (1 << WGM01); // CTC mode
    OCR0A = 125;           // Set the compare value for 128 BPM
    TIMSK0 = (1 << OCIE0A); // Enable timer compare interrupt
    TCCR0B = (1 << CS02);   // Prescaler of 256, 16MHz / 256 = 62500 Hz
}

int main() {
    DDRB |= (1 << BLUE_LED) | (1 << RED_LED) | (1 << WHITE_LED);
    initTimer();
    sei(); // Enable global interrupts

    while (1) {
        if (beat_count % 2 == 0) {
            // Blue LED on kick
            PORTB |= (1 << BLUE_LED);
            _delay_ms(50); // Adjust the delay for visual effect
            PORTB &= ~(1 << BLUE_LED);
        }

        if (beat_count % 4 == 0) {
            // Red LED on snare
            PORTB |= (1 << RED_LED);
            _delay_ms(50); // Adjust the delay for visual effect
            PORTB &= ~(1 << RED_LED);
        }

        // White LED on every beat (hi-hat)
        PORTB |= (1 << WHITE_LED);
        _delay_ms(50); // Adjust the delay for visual effect
        PORTB &= ~(1 << WHITE_LED);
    }

    return 0;
}
