#include <avr/io.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdbool.h>

#include "button.h"

bool buttonlast = false;
bool buttonstate = false;

void button_init() {
	DDRD &= ~(1<<PD2); /*0 becomes an input*/
}


bool is_button_pressed(int *button_state){
	if(PIND & (1<<PD2)){
		buttonstate = true; 
	}
	else{
		buttonstate = false;
	}
	if((buttonstate == true) && (buttonlast == false)){

	}
	else if((buttonstate == false) && (buttonlast == true)){
		*button_state+=1;
		if(*button_state >  3)
		*button_state = 0;
		}
	buttonlast = buttonstate;
} 
	
