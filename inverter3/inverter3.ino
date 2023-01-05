/*This code sets pins 0-3 of PORTD as outputs and generates a square wave with a frequency 
of 60 kHz by toggling the pins high and low in a loop, with a delay of 16.66 us in between.*/
#define F_CPU 16000000 // 16 MHz clock speed
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRD |= 0b00001111; // Set pins 0-3 of PORTD as output
  while (1)
  {
    PORTD |= 0b00001111; // Set pins 0-3 of PORTD high
    _delay_us(16.66); // Delay for 16.66 us
    PORTD &= 0b11110000; // Set pins 0-3 of PORTD low
    _delay_us(16.66); // Delay for 16.66 us
  }
  return 0;
}
