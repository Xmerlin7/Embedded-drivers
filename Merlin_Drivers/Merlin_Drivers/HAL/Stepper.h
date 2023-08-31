

#ifndef STEPPER_H_
#define STEPPER_H_
#include "StdTypes.h"
#include "DIO_interface.h"
#define   F_CPU 8000000UL
#include <util/delay.h> 


#define  BI_POLER      0
#define  UNI_POLER     1


/****************************STEPPER PIN CONFING****************/

#define  MOTOR_TYPE   BI_POLER

#define  COIL1A       PINA0
#define  COIL1B		  PINA1
#define  COIL2A		  PINA2
#define	 COIL2B		  PINA3

#define  DELAY		  500

#define  STEPrev	  512
/***************************************************************/
		
void STEPPER_CW(void);
void STEPPER_CCW(void);
void STEPPER_CW(void);
void STEPPER_CCW(void);
void STEPPER_CW_Half(void);
void STEPPER_CW_ANDGLE(u16 angle);
void STEPPER_CW_rev(u8 rev);





#endif /* STEPPER_H_ */