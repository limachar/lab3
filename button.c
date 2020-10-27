#include <avr/io.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdbool.h>

#include "button.h"

bool buttonlast = false;
bool buttonstate;

void button_init() {
	DDRD &= ~(1<<PD2); /*0 becomes an input*/
}

void button_pressed(){
	char pressed[]={"pushed\r\n"};
	char released[]={"released\r\n"};

		if(PIND & (1<<PD2)){
			buttonstate = true; 
		}
		else{
			buttonstate = false;
		}
		if((buttonstate == true) && (buttonlast == false)){
			printf_P(PSTR("%s"),pressed);
		}
		else if((buttonstate == false) && (buttonlast == true)){
			printf_P(PSTR("%s"),released);
		}
		buttonlast = buttonstate;
} 