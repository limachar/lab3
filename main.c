#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdbool.h>

#include "led.h"
#include "serial.h"
#include "timer.h"
#include "adc.h"
#include "button.h"
volatile unsigned int adc_value = 0;
volatile bool button_status = false;
volatile last_button_status = false;
int button_state = 0;
int count = 0;

ISR(TIMER2_COMPA_vect)
{
   is_button_pressed(&button_state);
}

ISR(ADC_vect){
	
	adc_value = ADCH;
}

int main (void) {

	LED_init();
	uart_init();
	timer_init();
	button_init();
	ADC_init();
	

	while (1) {

		switch(button_state){
			case 0:
				TCCR0A |= (1 << COM0A1);
				OCR0A = simple_ramp();
				break;
			case 1:
				ADCSRA |= (1<<ADSC);
				OCR0A = adc_value;
				break;
			case 2:
				TCCR0A &= ~(1 << COM0A1);
				count++;
				if(count == 500){
				PORTD ^= (1 << PD6);
				count = 0;
				}
				break;
			case 3:
				PORTD &= ~(1 << PD6);
				break;
			default:
				break;

		}
	}
	return 0;
}

