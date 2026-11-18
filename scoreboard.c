#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(INT0_vect)
{
    PORTB ^= _BV(3); // (1 << PORTB3);
}

int main()
{
    // Set data direction for PORTB3 to output
    DDRB |= _BV(3);

    // Set MCUCR register to trigger on falling edge
    MCUCR |= _BV(1);

    // Set General Interrupt Mask register to enable INT0
    GIMSK |= _BV(6);

    sei();

    while (1)
    {
        
    }


    return 0;
}
