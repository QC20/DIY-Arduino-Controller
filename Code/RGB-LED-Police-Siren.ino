#include <avr/io.h>
#include <util/delay.h>

#define WHITE_PIN PB1
#define BLUE_PIN PB2

void blinkLED(uint8_t pin, uint8_t delay_ms) {
    PORTB |= (1 << pin); // Turn on the LED
    _delay_ms(delay_ms);
    PORTB &= ~(1 << pin); // Turn off the LED
    _delay_ms(delay_ms);
}

int main() {
    // Set PB1 (WHITE_PIN) and PB2 (BLUE_PIN) as output for LEDs
    DDRB |= (1 << WHITE_PIN) | (1 << BLUE_PIN);

    while (1) {
        // Fast blinking white
        for (int i = 0; i < 5; i++) {
            blinkLED(WHITE_PIN, 100); // Blink white with 100ms delay
        }

        // Fast blinking blue
        for (int i = 0; i < 5; i++) {
            blinkLED(BLUE_PIN, 100); // Blink blue with 100ms delay
        }
    }

    return 0;
}
