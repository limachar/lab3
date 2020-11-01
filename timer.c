#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

void timer_init() {

	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1); /*fast PWM*/
	TCCR0B = (1 << CS00) | (1 << CS01); /*64*/
	TCNT0 = 0x00;


	TCCR2A = (1 << WGM21)| (1 << COM2A1);
	TCCR2B = (1 << CS20) | (1 << CS21) | (1 << CS22);
	TCNT2 = 0x00;
	OCR2B = 0x9C;
	TIMSK2 |= (1<<OCIE2A);
	sei();
}

