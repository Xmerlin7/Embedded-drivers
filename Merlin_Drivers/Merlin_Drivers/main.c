/*
 * Merlin_Drivers.c
 *
 * Created: 1/2/2023 9:06:16 PM
 * Author : Merlin
 */ 

#include "MemMap.h"
#include "StdTypes.h"
#include "Utils.h"
#include "DIO_interface.h"
#include "Stepper.h"
#include "LCD.h"


/*
#define  SEGMENT_PORT      PORTA
#define  EN1     0
#define  EN2     1
#define  ENABLE_PORT       PORTA
*/
#define F_CPU   8000000UL
#include <util/delay.h>

/*
unsigned char segNumbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x07,0x7f,0x6f};
void segment_display(unsigned char n)
{
	PORTD=segNumbers[n%10];
	//PORTC=segNumbers[n];
	PORTB=segNumbers[n/10];
}

void segment_display2(unsigned char n)
{
	SET_BIT(ENABLE_PORT,EN1);
	CLEAR_BIT(ENABLE_PORT,EN2);
	SEGMENT_PORT=segNumbers[n/10];
	_delay_ms(1);
	
	SET_BIT(ENABLE_PORT,0);
	CLEAR_BIT(ENABLE_PORT,1);
	SEGMENT_PORT=segNumbers[n%10];
	_delay_ms(1);
	
}*/
int main(void)
{


DIO_Init();
LCD_Init();
u8 str[]="ksa";
LCD_WriteData('M');
LCD_WriteData('R');
LCD_WriteData('T');
LCD_WriteString(str);

 
	while (1)
	{
		
	}
}
