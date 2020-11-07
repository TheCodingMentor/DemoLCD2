/*
 * LM35.c
 *
 * Created: 8/16/2019 12:45:17 AM
 *  Author: Mina
 */ 
#include "LM35.h"



void LM35_vInit(void)
{
	ADC_vInit();		
}

unsigned char LM35_u16Read(void)
{
	
	char temp =  ADC_u16Read()/2;
	
	return temp;
}