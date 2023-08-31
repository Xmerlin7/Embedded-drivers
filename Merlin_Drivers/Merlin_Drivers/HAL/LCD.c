/*
 * LCD.c
 *
 * Created: 2/1/2023 7:52:16 PM
 *  Author: Merlin
 */ 

#include "LCD.h"
void LCD_WriteCommand(u8 command)
{
	
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);	
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);//0x38 8 bit mode,2 line,5*7 dot
	_delay_ms(1);
	LCD_WriteCommand(0x0c);//cursor,screen,0x0e,0x0f
	_delay_ms(1);
	LCD_WriteCommand(0x01);//clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x06);//increase SS RAM address
	_delay_ms(1);
	LCD_WriteCommand(0x080);
	_delay_ms(1);
}
/***********************************LCD SERVICES*********************/
void LCD_WriteString(u8*str)
{
	u8 i;					   //i=0
	for (i=0;str[i];i++)      //while (str[i])
	{
		LCD_WriteData(str[i]);
								//i++
	}
}