/*
 * LCD_NEW_KIT.c
 *
 * Created: 8/14/2019 2:15:27 PM
 *  Author: Mina
 */ 


#include <avr/io.h>
#define F_CPU 8000000ul
#include "LCD.h"
#include "LM35.h"

int main(void)
{
	LCD_vInit();
	//LCD_vPrintString("Mina");
	LM35_vInit();
    while(1)
    {
		char y = LM35_u16Read();
        char tens  = (y/10) + '0';
		char units = (y%10)  + '0';
		//LCD_vSendData_4BitMode('5');
		LCD_vSendData_4BitMode(tens);
		LCD_vSendData_4BitMode(units);
		
		_delay_ms(1000);
		LCD_vClearScreen();
	}
}