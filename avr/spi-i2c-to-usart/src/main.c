#include "main.h"
#include "config.h"
#include "usart.h"
#include "i2c.h"
#include "spi.h"
#include "setup.h"

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>

void change_setup(void) {
	if( cfg1 & CFG1_NCONFIG ) return;
	if( cfg1 & CFG1_SPI_EN ) {
		if( cfg1 & CFG1_SPI_MSTR ) {
			init_spi_master();
		} else {
			init_spi_slave();
		}
	}
}

int main(void) {

	cli();
	FLG_ENTER_SETUP_INIT;
	LED1_INIT;
	init_usart();
	sei();

	printf_P(PSTR("------------------------------\r\n"));
	printf_P(PSTR(" spi/i2c to usart converter\r\n"));
	printf_P(PSTR("------------------------------\r\n"));

	_delay_ms(1000);

	LED1_L;
	setup_load();
	change_setup();

	for(;;) {
		LED1_I;
		_delay_ms(500);
		if( setup_wc_enter() ) change_setup();

	}
    return 0;
}
