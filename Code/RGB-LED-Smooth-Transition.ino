#include <avr/io.h>
#include <util/delay.h>

#define RED_PIN PB1
#define GREEN_PIN PB2
#define BLUE_PIN PB3

void PWM_init() {
    // Set PB1 (OC1A), PB2 (OC1B), and PB3 (OC2) as output for PWM
    DDRB |= (1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN);

    // Configure Timer1 and Timer2 for Fast PWM mode
    TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11) | (1 << WGM10);
    TCCR1B |= (1 << WGM12) | (1 << CS10); // No prescaler

    TCCR2 |= (1 << WGM20) | (1 << WGM21) | (1 << COM21) | (1 << CS20); // Fast PWM, no prescaler

    // Initialize PWM values to 0 (LEDs off)
    OCR1A = 0;
    OCR1B = 0;
    OCR2 = 0;
}

void fadeLED(uint8_t *ledValue, uint8_t direction, uint8_t delay_ms) {
    // Gradually increase or decrease LED brightness
    for (uint8_t i = 0; i < 255; i++) {
        *ledValue += direction;
        _delay_ms(delay_ms);
    }
}

int main() {
    PWM_init();

    while (1) {
        // Fade in red
        fadeLED(&OCR1A, 1, 10);
        // Fade out red
        fadeLED(&OCR1A, -1, 10);

        // Fade in green
        fadeLED(&OCR1B, 1, 10);
        // Fade out green
        fadeLED(&OCR1B, -1, 10);

        // Fade in blue
        fadeLED(&OCR2, 1, 10);
        // Fade out blue
        fadeLED(&OCR2, -1, 10);
    }

    return 0;
}
