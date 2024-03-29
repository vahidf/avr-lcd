/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <joerg@FreeBSD.ORG> wrote this file.  As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return.        Joerg Wunsch
 * ----------------------------------------------------------------------------
 *
 * Stdio demo
 *
 * $Id: stdiodemo.c 1008 2005-12-28 21:38:59Z joerg_wunsch $
 */

#include "defines.h"

#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

#include <avr/io.h>
#include <avr/pgmspace.h>

#include <util/delay.h>

#include "lcd.h"
//#include "uart.h"

/*
 * Do all the startup-time peripheral initializations.
 */
static void
ioinit(void)
{
//  uart_init();
  lcd_init();
}

//FILE uart_str = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
FILE lcd_str = FDEV_SETUP_STREAM(lcd_putchar, NULL, _FDEV_SETUP_WRITE);

main(void)
{
  uint8_t i;
  char buf[20], s[20];

  ioinit();

//  stdout = stdin = &uart_str;
  stderr = &lcd_str;

	while(1) {
	lcd_clear();
	lcd_goto_home();
	//fprintf(&lcd_str, "Vahid Fardi!");
	
		_delay_ms(2000);
		lcd_clear();
		_delay_ms(2000);
		set_dg();
		_delay_ms(1000);
		//lcd_clear();
		//lcd_goto_home();
		//fprintf(&lcd_str, "Vahid");
		while(1);
//		_delay_ms(2000);
	}

/*
  for (;;)
    {
      printf_P(PSTR("Enter command: "));
      if (fgets(buf, sizeof buf - 1, stdin) == NULL)
	break;
      if (tolower(buf[0]) == 'q')
	break;

      switch (tolower(buf[0]))
	{
	default:
	  printf("Unknown command: %s\n", buf);
	  break;

	case 'l':
	  if (sscanf(buf, "%*s %s", s) > 0)
	    {
	      fprintf(&lcd_str, "Got %s\n", s);
	      printf("OK\n");
	    }
	  else
	    {
	      printf("sscanf() failed\n");
	    }
	  break;

	case 'u':
	  if (sscanf(buf, "%*s %s", s) > 0)
	    {
	      fprintf(&uart_str, "Got %s\n", s);
	      printf("OK\n");
	    }
	  else
	    {
	      printf("sscanf() failed\n");
	    }
	  break;
	}
    }
  fprintf(stderr, "Bye-bye");
  delay_1s();
  for (i = 0; i < 3; i++)
    {
      putc('.', stderr);
      delay_1s();
    }
  fprintf(stderr, "\n ");

  return 0;
*/

}
