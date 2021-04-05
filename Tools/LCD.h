/*
 * LCD.h
 *
 * Created: 17-3-2021 11:08:01
 *  Author: Davy
 */ 

#ifndef LCD_CONTROLLER_H
#define LCD_CONTROLLER_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>

void lcd_strobe_lcd_e(void);
void init_4bits_mode(void);
void lcd_write_string(char *str);
void lcd_write_data(unsigned char byte);
void lcd_write_cmd(unsigned char byte);
void lcd_write_integer(int givenint);
void lcd_clear(void);

#endif //LCD_CONTROLLER_H