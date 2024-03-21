#include <avr/io.h>
#include <util/delay.h>

#define LED_BLUE PB1
#define LED_WHITE PB2

#define FAST_BLINK_DELAY_MS 200
#define SLOW_BLINK_DELAY_MS 1000

void initLEDs() {
    // Set LED pins (PB1 and PB2) as output
    DDRB |= (1 << LED_BLUE) | (1 << LED_WHITE);
}

void toggleLED(uint8_t pin) {
    PORTB ^= (1 << pin); // Toggle the LED state
}

int main() {
    // Initialize LEDs
    initLEDs();

    while (1) {
        // Blue light on, green light off (fast blink)
        PORTB |= (1 << LED_BLUE);
        PORTB &= ~(1 << LED_WHITE);
        _delay_ms(FAST_BLINK_DELAY_MS);

        // Both blue and green lights on (fast blink)
        PORTB |= (1 << LED_BLUE) | (1 << LED_WHITE);
        _delay_ms(FAST_BLINK_DELAY_MS);

        // Blue light on, green light off (slow blink)
        PORTB |= (1 << LED_BLUE);
        PORTB &= ~(1 << LED_WHITE);
        _delay_ms(SLOW_BLINK_DELAY_MS);

        // Both blue and green lights on (slow blink)
        PORTB |= (1 << LED_BLUE) | (1 << LED_WHITE);
        _delay_ms(SLOW_BLINK_DELAY_MS);
    }

    return 0;
}
