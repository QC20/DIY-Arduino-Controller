#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// change this value to adjust the speed of the smooth color transitions
#define PWM_DELAY_MS 6

void initPWM() {
    // Set PB1 (OC1A), PB2 (OC1B), and PB3 (OC2A) as output for PWM
    DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3);

    // Set non-inverted fast PWM mode with 8-bit resolution for Timer 1 (PB1 and PB2)
    TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
    TCCR1B |= (1 << CS10) | (1 << WGM12);

    // Set non-inverted fast PWM mode with 8-bit resolution for Timer 2 (PB3)
    TCCR2A |= (1 << COM2A1) | (1 << WGM20);
    TCCR2B |= (1 << CS20) | (1 << WGM22);

    // Initialize the PWM values (0% duty cycle)
    OCR1A = 0;
    OCR1B = 0;
    OCR2A = 0;
}

void pwm_delay(int ms) {
    for (int i = 0; i < ms; i++) {
        _delay_ms(1);
    }
}

int main() {
    // Initialize PWM
    initPWM();

    while (1) {
        // Smooth transition from off to red (PB1)
        for (int i = 0; i <= 255; i++) {
            OCR1A = i;
            _delay_ms(PWM_DELAY_MS);
        }

        // Smooth transition from red to green (PB1 to PB2)
        for (int i = 0; i <= 255; i++) {
            OCR1A = 255 - i;
            OCR1B = i;
            _delay_ms(PWM_DELAY_MS);
        }

        // Smooth transition from green to blue (PB2 to PB3)
        for (int i = 0; i <= 255; i++) {
            OCR1B = 255 - i;
            OCR2A = i;
            _delay_ms(PWM_DELAY_MS);
        }

        // Smooth transition from blue to off (PB3)
        for (int i = 0; i <= 255; i++) {
            OCR2A = 255 - i;
            _delay_ms(PWM_DELAY_MS);
        }

        // Smooth transition from off to red (PB1)
        for (int i = 0; i <= 155; i++) {
            OCR1A = i + 100;
            _delay_ms(PWM_DELAY_MS);
        }
    }
    

    return 0;
}
