#include <avr/io.h>
#include <util/delay.h>

int main() { 
   // Set PB1, PB2, and PB3 as output for controlling LEDs
   DDRB |= (1 << PB1) | (1 << PB2) | (1 << PB3);

   while (1) {
        // Turn on red LED (PB1)
        PORTB |= (1 << PB1);
        _delay_ms(500);
        
        // Turn off red LED (PB1)
        PORTB &= ~(1 << PB1);
        _delay_ms(500);
        
        // Turn on green LED (PB2)
        PORTB |= (1 << PB2);
        _delay_ms(500);
        
        // Turn off green LED (PB2)
        PORTB &= ~(1 << PB2);
        _delay_ms(500);
        
        // Turn on blue LED (PB3)
        PORTB |= (1 << PB3);
        _delay_ms(500);
        
        // Turn off blue LED (PB3)
        PORTB &= ~(1 << PB3);
        _delay_ms(500);
	}
   
   return 0;
}
