/*
 * DIO.h
 *
 * Created: 8/14/2019 11:03:52 AM
 *  Author: Mina
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "DIO_Types.h"


void DIO_vSetPinDir(char portName , char pinNum , eDIO_Dir dir);
void DIO_vWrite(char portName , char pinNum , eDIO_Level val);
char DIO_u8Read(char portName, char pinNum);
void DIO_vSetPortDirHighNibble(char portName , char writeVal);
void DIO_vWritePortHighNibble(char portName , char writeVal);

#endif /* DIO_H_ */