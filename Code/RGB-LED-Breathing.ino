#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

#define NUM_STEPS 1000
#define BREATH_DELAY_MS 10

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

void pwm_breath(int num_steps, int delay_ms) {
    for (int i = 0; i <= num_steps; i++) {
        int value = 128 + 127 * sin(i * 2 * 3.14159265359 / num_steps); // Larger amplitude sine wave
        OCR1A = value;
        OCR1B = value;
        OCR2A = value;
        _delay_ms(delay_ms);
    }
}

int main() {
    // Initialize PWM
    initPWM();

    while (1) {
        // Create a more pronounced breathing effect
        pwm_breath(NUM_STEPS, BREATH_DELAY_MS);
    }

    return 0;
}
