#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdint.h>

uint8_t ss_zero = 0x3F;
uint8_t ss_one = 0x06;
uint8_t ss_two = 0x5B;
uint8_t ss_three = 0x4F;
uint8_t ss_four = 0x66;
uint8_t ss_five = 0x6D;
uint8_t ss_six = 0x7D;
uint8_t ss_seven = 0x07;
uint8_t ss_eight = 0x7F;
uint8_t ss_nine = 0x4F;

uint8_t ConvertCountToSevenSegmentData(uint8_t count)
{
    switch(count) {
        case 0: return ss_zero;
        case 1: return ss_one;
        case 2: return ss_two;
        case 3: return ss_three;
        case 4: return ss_four;
        case 5: return ss_five;
        case 6: return ss_six;
        case 7: return ss_seven;
        case 8: return ss_eight;
        case 9: return ss_nine;
        default: return ss_zero;
    }
}

#endif