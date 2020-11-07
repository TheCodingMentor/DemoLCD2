/*
 * DIO.c
 *
 * Created: 8/14/2019 11:03:39 AM
 *  Author: Mina
 */ 

#include "DIO.h"
#include <avr/io.h>

void DIO_vSetPinDir(char portName , char pinNum , eDIO_Dir dir)
{
	switch(portName)
	{
		case 'A':
		case 'a':
		if (eOutput == dir)
		{
			DDRA |= (1<<pinNum);
		} 
		else
		{
			DDRA &= ~(1<<pinNum);
		}
		break;
		
		case 'B':
		case 'b':
		if (eOutput == dir)
		{
			DDRB |= (1<<pinNum);
		}
		else
		{
			DDRB &= ~(1<<pinNum);
		}
		break;
		
		case 'C':
		case 'c':
		if (eOutput == dir)
		{
			DDRC |= (1<<pinNum);
		}
		else
		{
			DDRC &= ~(1<<pinNum);
		}
		break;
		
		case 'D':
		case 'd':
		if (eOutput == dir)
		{
			DDRD |= (1<<pinNum);
		}
		else
		{
			DDRD &= ~(1<<pinNum);
		}
		break;
		
		default:
		break;
		
	}
}

void DIO_vWrite(char portName , char pinNum , eDIO_Level val)
{
	switch(portName)
	{
		case 'A':
		case 'a':
		if (eHigh == val)
		{
			PORTA |= (1<<pinNum);
		}
		else
		{
			PORTA &= ~(1<<pinNum);
		}
		break;
		
		case 'B':
		case 'b':
		if (eHigh == val)
		{
			PORTB |= (1<<pinNum);
		}
		else
		{
			PORTB &= ~(1<<pinNum);
		}
		break;
		
		case 'C':
		case 'c':
		if (eHigh == val)
		{
			PORTC |= (1<<pinNum);
		}
		else
		{
			PORTC &= ~(1<<pinNum);
		}
		break;
		
		case 'D':
		case 'd':
		if (eHigh == val)
		{
			PORTD |= (1<<pinNum);
		}
		else
		{
			PORTD &= ~(1<<pinNum);
		}
		break;
		
		default:
		break;
		
	}
}

char DIO_u8Read(char portName, char pinNum)
{
	char tempVar =0;
	
	switch (portName)
	{
	case 'A':
	case 'a':
		tempVar = (PINA >> pinNum) & 1;
		break;
	
	case 'B':
	case 'b':
		tempVar = (PINB >> pinNum) & 1;
		break;
	
	case 'C':
	case 'c':
		tempVar = (PINC >> pinNum) & 1;
		break;
	
	case 'D':
	case 'd':
		tempVar = (PIND >> pinNum) & 1;
		break;
	
	default:
		tempVar = 0;
		break;
	}
	
	return tempVar;
}


void DIO_vWritePortHighNibble(char portName , char writeVal)
{
	switch(portName)
	{
		case 'A':
		PORTA &= 0x0f;
		PORTA |= (writeVal & 0xf0);
		break;
		case 'B':
		PORTB &= 0x0f;
		PORTB |= (writeVal & 0xf0);
		break;
		case 'C':
		PORTC &= 0x0f;
		PORTC |= (writeVal & 0xf0);
		break;
		case 'D':
		PORTD &= 0x0f;
		PORTD |= (writeVal & 0xf0);
		break;
		default:
		break;
	}
}


void DIO_vSetPortDirHighNibble(char portName , char writeVal)
{
	switch(portName)
	{
		case 'A':
			DDRA &= 0x0f;
			DDRA |= (writeVal & 0xf0);
			break;
		case 'B':
			DDRB &= 0x0f;
			DDRB |= (writeVal & 0xf0);
			break;
		case 'C':
			DDRC &= 0x0f;
			DDRC |= (writeVal & 0xf0);
			break;
		case 'D':
			DDRD &= 0x0f;
			DDRD |= (writeVal & 0xf0);
			break;
		default:
		break;
	}
}