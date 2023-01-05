#define F_CPU 16000000        // Set the clock frequency
#define PORTB_MASK 0b00001111 // Mask to set only the lower four bits of PORTB
#define PORTD_MASK 0b11110000 // Mask to set only the upper four bits of PORTD

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Set the lower four bits of PORTB as outputs
    DDRB = PORTB_MASK;
    // Set the upper four bits of PORTD as outputs
    DDRD = PORTD_MASK;

    while (1)
    {
        // Toggle the lower four bits of PORTB
        PORTB ^= PORTB_MASK;
        // Toggle the upper four bits of PORTD
        PORTD ^= PORTD_MASK;

            // Delay for a period of 1/60 kHz = 16.7 us
            _delay_us(16.7);
    }

    return 0; // This line is never reached
}