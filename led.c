#include <avr/io.h>
#include "led.h"

void LED_init() {
	PORTD |= (1 << PD6);
}

uint8_t simple_ramp() {
	
}

