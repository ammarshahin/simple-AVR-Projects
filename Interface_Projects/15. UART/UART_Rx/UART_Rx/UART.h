/*
 * UART.h
 *
 * Created: 4/15/2019 7:37:03 PM
 *  Author: Ammar Shahin
 */ 
 

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#include "BasicTypes.h"
#include "BitMasking_Macros.h"


/*************************UCSRA CONFIGURATION******************************/
typedef enum
{
   Normal_Speed=0x00,	
   Double_Speed=0x02,
   	
}UART_Speed;

typedef enum 
{
   Multiprocessor_Off=0x00,
   Multiprocessor_On=0x01,
   	
}Multiprocessor_mode;
/*************************UCSRB CONFIGURATION******************************/
typedef enum
{
   RX_Interrupt_Off=0x00,	
   RX_Interrupt_ON=0x80,
   	
}RX_Interrupt;

typedef enum
{
	TX_Interrupt_Off=0x00,
	TX_Interrupt_ON=0x40,
	
}TX_Interrupt;

typedef enum
{
	UDRE_Interrupt_Off=0x00,
	UDRE_Interrupt_ON=0x20,
	
}UDRE_Interrupt;

typedef enum
{
	Recieve_Off=0x00,
	Recieve_ON=0x10,
	
}Recieve_Enable; 

typedef enum
{
	Transmit_Off=0x00,
	Transmit_ON=0x08,
	
}Transmit_Enable;

typedef enum
{
    Off_9Bit=0x00,	
    ON_9Bit=0x04,
		
}Transmit_9bit;

typedef enum
{
    Bit9Tx_Off=0x00,	
    Bit9Tx_ON=0x01,
		
}Ninth_Bit;

/*************************UCSRC CONFIGURATION******************************/

typedef enum
{
    UBRRH_Acess=0x00,	
    USCRC_Acess=0x80,
		
}Register_Select;

typedef enum
{
    Asynchronus_Mode=0x00,
    Synchronus_Mode=0x40,
		
}Mode_Select;

typedef enum 
{
    Parity_Disabled=0x00,	
    Parity_Reserved=0x10,
    Parity_Even=0x20,
    Parity_Odd=0x30,
		
}Parity_Mode;

typedef enum
{
    One_StopBit=0x00,	
    Two_StopBit=0x08,
		
}StopBit_Number;

typedef enum
{
    Mode_5Bit=0x00,	
    Mode_6Bit=0x02,
    Mode_7Bit=0x04,
    Mode_8Bit=0x06,
		
}Character_Size;

typedef enum
{
    RisingTx_FallingRx=0x00,
    FallingTx_RisingRx=0x01,
		
}Clock_Polarity_Synchronus;


void UART_Init();
void UART_Transmit(TU08 ch);
TU08 UART_Recieve();

#endif /* UART_H_ */