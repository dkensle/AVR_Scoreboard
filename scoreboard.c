#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "definitions.h"


uint8_t g_prev_count = 0;
uint8_t g_count = 0;
uint8_t g_ready_to_increment = 0;

// pin configuration
int g_data_pin = 3;
int g_clk_pin = 2;
int g_latch_pin = 4;


void ShiftOut(int clk_pin, int data_pin, uint8_t data);

ISR(INT0_vect)
{
    if (g_ready_to_increment > 5)
    {
        ++g_count;
        if (g_count > 9) {
            g_count = 0;
        }
        g_ready_to_increment = 0;
    }
}

int main()
{
    // Set data direction for PORTB3 to output
    DDRB |= _BV(g_data_pin);
    DDRB |= _BV(g_clk_pin);
    DDRB |= _BV(g_latch_pin);

    // Set MCUCR register to trigger on falling edge
    MCUCR |= _BV(1);

    // Set General Interrupt Mask register to enable INT0
    GIMSK |= _BV(6);

    sei();

    while (1)
    {
        _delay_ms(100);
        ++g_ready_to_increment;
        if (g_prev_count != g_count)
        {
            uint8_t data = ConvertCountToSevenSegmentData(g_count);
        }

    }


    return 0;
}

void ShiftOut(int clk_pin, int data_pin, uint8_t data)
{
    for (uint8_t bit = 0; bit < 8; ++bit)
    {
        // Set the data pin
        if (data & 0x80) {
            // Set high
            PORTB |= _BV(data_pin);
        } else {
            // Set low
            PORTB &= ~(_BV(data_pin));
        }


        // Set the clk pin
        PORTB |= _BV(clk_pin);

        // Unset the clk pin
        PORTB &= ~(_BV(clk_pin));

        data <<= 1;
    }


}