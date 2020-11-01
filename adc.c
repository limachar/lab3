#include <avr/io.h>
#include <avr/interrupt.h>
#include "adc.h"

void ADC_init() {
	ADMUX = 0x00;//A0 pin
    ADMUX |= (1<<REFS0);/*AVcc as Vcc*/
    ADMUX |=  (1 <<ADLAR);//leftadjusted
    ADCSRA |= (1<<ADPS1)|(1<<ADPS0); /*8 prescale*/
    ADCSRA |=  (1 <<ADEN);//enable
    ADCSRA |= (1<<ADIE);//interrupt on completion
    sei();
}

