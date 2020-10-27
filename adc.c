#include <avr/io.h>
#include "adc.h"

void ADC_init() {
	ADMUX |= (1<<REFS0);/*AVcc as Vcc*/
    ADCSRA |= (1<<ADPS1)|(1<<ADPS0); /*8 prescale*/
        
}

    /*ADCSRA |= (1<<ADSC); single convertion, sets bit to 1
    while(ADCSRA & (1<<ADSC));
    return ADCvalue;

    ADIE ADC_vect*/