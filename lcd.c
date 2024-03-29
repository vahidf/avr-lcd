/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Stdio demo, upper layer of LCD driver.
 *
 * $Id: lcd.c 1008 2005-12-28 21:38:59Z joerg_wunsch $
 */

#include "defines.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <avr/io.h>

#include <util/delay.h>

#include "hd44780.h"
#include "lcd.h"

/*
 * Setup the LCD controller.  First, call the hardware initialization
 * function, then adjust the display attributes we want.
 */
void
lcd_init(void)
{

  hd44780_init();
  /*
   * Clear the display.
   */
  hd44780_outcmd(HD44780_CLR);
  hd44780_wait_ready(false);

  /*
   * Entry mode: auto-increment address counter, no display shift in
   * effect.
   */
  hd44780_outcmd(HD44780_ENTMODE(1, 0));
  hd44780_wait_ready(false);

  /*
   * Enable display, activate non-blinking cursor.
   */
  hd44780_outcmd(HD44780_DISPCTL(1, 1, 0));
  hd44780_wait_ready(false);
}

/*
 * Send character c to the LCD display.  After a '\n' has been seen,
 * the next character will first clear the display.
 */
int
lcd_putchar(char c, FILE *unused)
{
  static bool nl_seen;

  if (nl_seen && c != '\n')
    {
      /*
       * First character after newline, clear display and home cursor.
       */
      hd44780_wait_ready(false);
      hd44780_outcmd(HD44780_CLR);
      hd44780_wait_ready(false);
      hd44780_outcmd(HD44780_HOME);
      hd44780_wait_ready(false);
      hd44780_outcmd(HD44780_DDADDR(0));

      nl_seen = false;
    }
  if (c == '\n')
    {
      nl_seen = true;
    }
  else
    {
      hd44780_wait_ready(false);
      hd44780_outdata(c);
    }

  return 0;
}

void
lcd_clear(void)
{
	hd44780_wait_ready(false);
	hd44780_outcmd(HD44780_CLR);
}

void
lcd_status(char disp, char cursor, char blink)
{
	hd44780_wait_ready(false);
	hd44780_outcmd(HD44780_DISPCTL(disp, cursor, blink));
}

void 
lcd_shift(char shift, char right, char n)
{
	while(n > 0)
	{
		hd44780_wait_ready(false);
		hd44780_outcmd(HD44780_SHIFT(shift, right));
		n = n-1;
	}
}

void lcd_goto_home(void)
{
	hd44780_wait_ready(false);
	hd44780_outcmd(HD44780_HOME);
}


void set_dg(void)
{
  
  hd44780_wait_ready(false);
  hd44780_outcmd(0x40);
  _delay_ms(10);
  hd44780_outdata(0x41);
  _delay_ms(10);
  hd44780_outdata(0x41);
  _delay_ms(10);
  hd44780_outdata(0x41);
  _delay_ms(10);
  hd44780_outdata(0x41);
  _delay_ms(10);
  hd44780_outdata(0x41);
  _delay_ms(10);
  hd44780_outdata(0x41);
  _delay_ms(10);
  hd44780_outdata(0x41);
  _delay_ms(10);
  hd44780_outdata(0x41);

  hd44780_wait_ready(false);
}
