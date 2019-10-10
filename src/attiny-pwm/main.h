#ifndef _MAIN_H_
#define _MAIN_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// $BG[@~(B
//       /RST |     | VCC
//       PB3  |     | PB2 LED1
//  LED2 PB4  |     | PB1
//       GND  |     | PB0

#define LED2 ( 1<<PB4 )
#define LED2_INIT DDRB  |=  LED2
#define LED2_H    PORTB |=  LED2 
#define LED2_L    PORTB &=~ LED2
#define LED2_I    PORTB ^=  LED2

#define LED1 ( 1<<PB2 )
#define LED1_INIT DDRB  |=  LED1
#define LED1_H    PORTB |=  LED1
#define LED1_L    PORTB &=~ LED1
#define LED1_I    PORTB ^=  LED1

// PWM$B$N<~GH?t(B
#define PWM_HZ 75

// 1$BIC%+%&%s%?(B
uint8_t timer_ct0;

#endif
