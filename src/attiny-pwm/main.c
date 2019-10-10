#include "main.h"

// タイマ割込 TCNT0がOCR0Aになったら発動する
// LED2はPWMで1秒ごとの点滅
ISR(TIM0_COMPA_vect) {
	timer_ct0++;
	// 周期がきたらLED2を反転させる
	// 毎回同じ周期なのでデュティー比は50%
	if(timer_ct0 == PWM_HZ) {
		LED2_I;
		timer_ct0=0;
	}
}

int main(void) {

	// 初期化
	LED1_INIT;
	LED2_INIT;
	timer_ct0=0;

	// 割り込み禁止
	cli();

	// clk(I/O)/1024
	TCCR0B = (1<<CS02)|(1<<CS00);

	// Waveform Generation Mode: 1 PWM (Phase Correct)
	TCCR0A = (1<<WGM01);

	// Timer/Counter0 Overflow Interrupt Enable
	TIMSK0 |= (1<<OCIE0A);  

	// トップ値を設定
	OCR0A = 0x7d;

	LED1_H;
	LED2_H;
	_delay_ms(3000);
	LED1_L;
	LED2_L;

	sei();

	for(;;){
		// LED1は_delay_msで0.5秒の点滅
		LED1_I;
		_delay_ms(500);
	}

	return 0;
}
