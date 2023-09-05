#include <avr/io.h>
#include <util/delay.h>

#define RED_PIN PB1
#define GREEN_PIN PB2
#define BLUE_PIN PB3

#define BEAT_DELAY 234 // Approx. 128 BPM (milliseconds)

void blinkLED(uint8_t pin, uint8_t delay_ms) {
    PORTB |= (1 << pin); // Turn on the LED
    _delay_ms(delay_ms);
    PORTB &= ~(1 << pin); // Turn off the LED
    _delay_ms(delay_ms);
}

int main() {
    // Set PB1 (RED_PIN), PB2 (GREEN_PIN), and PB3 (BLUE_PIN) as output for LEDs
    DDRB |= (1 << RED_PIN) | (1 << GREEN_PIN) | (1 << BLUE_PIN);

    while (1) {
        // Kick (Red) on every beat
        blinkLED(RED_PIN, BEAT_DELAY);

        // Hi-hat (White) on every beat
        blinkLED(RED_PIN, BEAT_DELAY / 2);
        blinkLED(GREEN_PIN, BEAT_DELAY / 2);

        // Snare (Blue) on every second beat
        _delay_ms(BEAT_DELAY / 2); // Delay half a beat
        blinkLED(BLUE_PIN, BEAT_DELAY);
        _delay_ms(BEAT_DELAY / 2); // Delay half a beat
    }

    return 0;
}
