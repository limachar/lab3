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
volatile unsigned int adc_value = 0;//uint_8t om vi bara ska använda ADCH

ISR(TIMER2_COMPA_vect)
{
    ADCSRA |= (1<<ADSC); //start single conversion
	//while(ADCSRA & (1<<ADSC));
	//adc_value = ADCH;
	OCR0A = adc_value;	
}

ISR(ADC_vect){
	
	adc_value = ADCH;//(ADCH <<8) | ADCL; ?
}

int main (void) {

	LED_init();
	uart_init();
	timer_init();
	button_init();
	ADC_init();
	
	while (1) {
		button_pressed();
	}
	return 0;
}

