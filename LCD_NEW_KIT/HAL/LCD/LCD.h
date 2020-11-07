/*
 * LCD.h
 *
 * Created: 8/14/2019 2:19:41 PM
 *  Author: Mina
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_cfg.h"
#include "DIO.h"
#include <util/delay.h>
	
void LCD_vInit(void);
void LCD_vSendCmd_4BitMode(char cmd);
void LCD_vPrintString(char * str);
void LCD_vClearScreen(void);

#endif /* LCD_H_ */