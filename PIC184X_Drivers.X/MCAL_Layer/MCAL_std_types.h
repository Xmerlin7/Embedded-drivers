/* 
 * File:   MCAL_std_types.h
 * Author: Merlin
 *
 * Created on May 3, 2023, 4:50 AM
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* ?Section : Includes*/

#include "Std_Libraries.h"
#include "compiler.h"


/* ?Section : Data type Declarations*/

#define CPU_TYPE_8  8
#define CPU_TYPE_16 16
#define CPU_TYPE_32 32
#define CPU_TYPE_64 64

/*****************CPU_TYPE*************************/

#define CPU_TYPE (CPU_TYPE_8)

/*****************SELECTING_CPU********************/
#if (CPU_TYPE == CPU_TYPE_64)
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;
typedef uint8 Std_ReturnType;

#elif (CPU_TYPE == CPU_TYPE_32)

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;
typedef uint8 Std_ReturnType;

#elif (CPU_TYPE == CPU_TYPE_16)

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_8)

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef float float32;
typedef uint8 Std_ReturnType;

#endif



/* ?Section : Macro Declarations*/

#define STD_HIGH        0X01;
#define STD_LOW         0X00;

#define STD_ON          0X01;
#define STD_OFF         0X00;

#define STD_ACTIVE      0X01;
#define STD_IDLE        0X01;

#define E_OK        (Std_ReturnType)0x01;
#define E_NOT_OK    (Std_ReturnType)0x00;

#define ZERO_INIT 0

/* ?Section : Macro  Like function Declarations*/

/* ?Section : Functions Declarations*/



#endif	/* MCAL_STD_TYPES_H */

