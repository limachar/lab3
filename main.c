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

