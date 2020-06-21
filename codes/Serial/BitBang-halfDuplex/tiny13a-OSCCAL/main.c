#include "main.h"
#include "config.h"
#include "tinySerial.h"
#include "tinySerialPlus.h"
#include <util/delay.h>

int main(void) {
	OSCCAL = 0x56;

	LED_OUT;
	LED_L;

	// $B<B9T$9$k$H!"J8;z2=$1$H(BOSCCAL$B%j%9%H$,7+$jJV$7=PNO$5$l$k(B
	// $B@5$7$/I=<($5$l$?%j%9%H$NCf$+$iA*Br$9$k$H(B
	// $B%7%j%"%kF~=PNO$K:GE,$JF0:n<~GH?t$KD4@0$G$-$k!#(B
	for(;;) {
		LED_H;
		for(uint8_t i=0;i<0x7f;i++) {
			OSCCAL=i;
			serOutP("OSCCAL = 0x"); serOutInt8Hex(i); serOutP("\r\n");
			_delay_ms(1);
		}
		LED_L;
		for(uint8_t i=0;i<10;i++) {
			_delay_ms(1000);
		}
	}
    return 0;
}
