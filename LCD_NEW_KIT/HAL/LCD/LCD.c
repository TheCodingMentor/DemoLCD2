/*
 * LCD.c
 *
 * Created: 8/14/2019 2:19:26 PM
 *  Author: Mina
 */ 

#include "LCD.h"

static void SendFallingEdge(void);
	
void LCD_vInit(void)
{
	
	/*Data pins connected to PA4-7*/
	DIO_vSetPortDirHighNibble(LCD_DATA_PORT_REG,0xFF);
	
	DIO_vSetPinDir(LCD_CTRL_PORT_REG,RS,eOutput);
	DIO_vSetPinDir(LCD_CTRL_PORT_REG,RW,eOutput);
	DIO_vSetPinDir(LCD_CTRL_PORT_REG,EN,eOutput);

	/*Set the write pin to 0*/
	DIO_vWrite(LCD_CTRL_PORT_REG,RW,0);
	
	/*Write a command and choose RS by 0*/
	DIO_vWrite(LCD_CTRL_PORT_REG,RS,0);
	_delay_ms(5);
	/*4 Bit Mode Command*/
	LCD_vSendCmd_4BitMode(0x03);
	LCD_vSendCmd_4BitMode(0x03);
	LCD_vSendCmd_4BitMode(0x03);
	LCD_vSendCmd_4BitMode(0x02);
	LCD_vSendCmd_4BitMode(0x28);
	/*Clear LCD Command*/
	LCD_vSendCmd_4BitMode(0x01);
	/*Turn on the cursor command*/
	LCD_vSendCmd_4BitMode(0x0E);
	_delay_ms(30);
}


void LCD_vSendCmd_4BitMode(char cmd)
{
	DIO_vWrite(LCD_CTRL_PORT_REG,RS,0);
	
	/*Send High nibble*/
	DIO_vWritePortHighNibble(LCD_DATA_PORT_REG , cmd);
	SendFallingEdge();
	
	/*Send Low nibble*/
	DIO_vWritePortHighNibble(LCD_DATA_PORT_REG , (cmd<<4) );
	SendFallingEdge();
}


void LCD_vSendData_4BitMode(char data)
{	
	DIO_vWrite(LCD_CTRL_PORT_REG,RS,1);
	
	/*Send High nibble*/
	DIO_vWritePortHighNibble(LCD_DATA_PORT_REG , data );
	SendFallingEdge();
	
	/*Send Low nibble*/
	DIO_vWritePortHighNibble(LCD_DATA_PORT_REG , (data<<4) );
	SendFallingEdge();
}

void LCD_vPrintString(char * str)
{
	
	//while( (*str) != '\0')
	while(*str)
	{
		LCD_vSendData_4BitMode(*str);
		str++;
	}
}

static void SendFallingEdge(void)
{
	/*Set Enable pin*/
	DIO_vWrite(LCD_CTRL_PORT_REG,EN,1);
	/*Wait for time for data to be written*/
	_delay_ms(5);
	/*Clear Enable pin*/
	DIO_vWrite(LCD_CTRL_PORT_REG,EN,0);
	_delay_ms(5);
}

void LCD_vClearScreen(void)
{
	/*Clear LCD Command*/
	LCD_vSendCmd_4BitMode(0x01);
}