#include <avr/io.h>
#include "led.h"
#include <stdbool.h>
bool increment = true;
uint8_t i = 0;

void LED_init() {
	DDRD |= (1 << PD6);
}

uint8_t simple_ramp() {
	
	if (increment == true){
		i+=1;
		if(i == 255){
			increment = false;
		}
	}
	else if (increment == false){
		i-=1;
		if(i == 0){
			increment = true;
		}	
	}
	return i;
}

