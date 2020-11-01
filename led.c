#include <avr/io.h>
#include "led.h"
#include <stdbool.h>
bool increment = true;

void LED_init() {
	DDRD |= (1 << PD6);
}

uint8_t simple_ramp() {
	int i = 0;
	if (increment == true){
		i+=5;
		if(i == 255){
			increment = false;
		}
	}
	else if (increment == false){
		i-=5;;
		if(i == 0){
			increment = true;
		}	
	}
	return i;
}

