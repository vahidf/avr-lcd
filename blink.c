#define F_CPU 10000000UL
#include <avr/io.h>
#include <util/delay.h>

void delayms(uint16_t millis) {
  uint16_t loop;
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}

int main(void) {
  DDRB |= 1<<PB0; /* set PB0 to output */
  while(1) {
    PORTB &= ~(1<<PB0); /* LED on */
    delayms(500);
    PORTB |= 1<<PB0; /* LED off */
    delayms(500);
  }
  return 0;
}

