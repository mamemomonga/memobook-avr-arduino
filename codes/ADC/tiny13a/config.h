#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <avr/io.h>

/*
 ATtiny13A 8PDIP

/RST | 1    8 | VCC
 PB3 | 2    7 | PB2 ADC1
 PB4 | 3    6 | PB1 USART TX
 GND | 4    5 | PB0
*/

#define LED       ( 1<<PB2 )
#define LED_OUT     DDRB  |=  LED 
#define LED_IN    { DDRB  &=~ LED; PORTB &=~ LED; }
#define LED_INPU  { DDRB  &=~ LED; PORTB |=  LED; }
#define LED_H       PORTB |=  LED 
#define LED_L       PORTB &=~ LED 
#define LED_I       PORTB ^=  LED 
#define LED_IS_H  ( PINB &    LED )
#define LED_IS_L !( PINB &    LED )

#define BAUD 38400

#endif

