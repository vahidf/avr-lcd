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
 * $Id: lcd.h 1008 2005-12-28 21:38:59Z joerg_wunsch $
 */

#define LCD_SHIFT					1
#define CURSOR_SHIFT			0
#define RIGHT							1
#define LEFT							0

/*
 * Initialize LCD controller.  Performs a software reset.
 */
void	lcd_init(void);

/*
 * Send one character to the LCD.
 */
int	lcd_putchar(char c, FILE *stream);


/*
*	Clear LCD
*/
void lcd_clear(void);

void lcd_status(char disp, char cursor, char blink);

void lcd_shift(char shift, char right, char n);

void lcd_goto_home(void);

void set_dg(void);
