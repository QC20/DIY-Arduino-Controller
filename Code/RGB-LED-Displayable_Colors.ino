#include <avr/io.h>
#include <util/delay.h>
#include <math.h>

#define NUM_STEPS 1000
#define BREATH_DELAY_MS 4

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

void cycle_colors() {
    int color_variations = 12; // Number of color variations

    while (1) {
        for (int color = 0; color < color_variations; color++) {
            // Adjust color pattern here
            switch (color) {
                case 0:
                    // Red
                    OCR1A = 255;
                    OCR1B = 0;
                    OCR2A = 0;
                    break;
                case 1:
                    // Green
                    OCR1A = 0;
                    OCR1B = 255;
                    OCR2A = 0;
                    break;
                case 2:
                    // Blue
                    OCR1A = 0;
                    OCR1B = 0;
                    OCR2A = 255;
                    break;
                case 3:
                    // Yellow (Red + Green)
                    OCR1A = 255;
                    OCR1B = 255;
                    OCR2A = 0;
                    break;
                case 4:
                    // Cyan (Green + Blue)
                    OCR1A = 0;
                    OCR1B = 255;
                    OCR2A = 255;
                    break;
                case 5:
                    // Magenta (Red + Blue)
                    OCR1A = 255;
                    OCR1B = 0;
                    OCR2A = 255;
                    break;
                case 6:
                    // Orange (Red + Green, higher intensity)
                    OCR1A = 255;
                    OCR1B = 128;
                    OCR2A = 0;
                    break;
                case 7:
                    // Purple (Red + Blue, higher intensity)
                    OCR1A = 128;
                    OCR1B = 0;
                    OCR2A = 255;
                    break;
                case 8:
                    // Teal (Green + Blue, higher intensity)
                    OCR1A = 0;
                    OCR1B = 255;
                    OCR2A = 128;
                    break;
                case 9:
                    // White (Red + Green + Blue, higher intensity)
                    OCR1A = 255;
                    OCR1B = 255;
                    OCR2A = 255;
                    break;
                case 10:
                    // Pink (Red + Blue, high intensity)
                    OCR1A = 255;
                    OCR1B = 0;
                    OCR2A = 128;
                    break;
                case 11:
                    // Sky Blue (Green + Blue, high intensity)
                    OCR1A = 0;
                    OCR1B = 128;
                    OCR2A = 255;
                    break;
                default:
                    // Turn off LEDs
                    OCR1A = 0;
                    OCR1B = 0;
                    OCR2A = 0;
                    break;
            }
            
            _delay_ms(1000); // Delay between color variations
        }
    }
}

int main() {
    // Initialize PWM
    initPWM();

    while (1) {
        // Create a more pronounced breathing effect
        pwm_breath(NUM_STEPS, BREATH_DELAY_MS);
        _delay_ms(500); // Delay between breathing effects

        // Cycle through color variations
        cycle_colors();
    }

    return 0;
}
