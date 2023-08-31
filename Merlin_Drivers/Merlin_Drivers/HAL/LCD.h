/*
 * LCD.h
 *
 * Created: 2/1/2023 7:51:52 PM
 *  Author: Merlin
 */ 


#ifndef LCD_H_
#define LCD_H_

#define  F_CPU 8000000UL

#include "StdTypes.h"
#include "DIO_interface.h"
#include <util/delay.h>
/***************************config***********************/
#define LCD_MODE       4_BIT

#define D0       PINB0
#define D1       PINB1
#define D1       PINB1
#define D1       PINB1


#define  LCD_PORT      PD



#define  RS            PINC0
#define  RW            PINC1
#define  EN            PINC2
/********************************************************/

void LCD_WriteCommand(u8 command);
void LCD_WriteData(u8 data);
void LCD_Init(void);
void LCD_WriteString(u8*str);
#endif /* LCD_H_ */