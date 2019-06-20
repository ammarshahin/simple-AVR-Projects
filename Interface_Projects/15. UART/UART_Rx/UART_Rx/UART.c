/*
 * UART.c
 *
 * Created: 4/15/2019 7:37:03 PM
 *  Author: Ammar Shahin
 */ 
 
#include "UART.h"

TU08 ch_Recieved='\0';
TU08 ch_Transmited='\0';

void UART_Init()
{
	
		
		/* set baud rate as 9600 and 8MHZ */
		UBRRL=51;
		UBRRH=0;
		
		/* set frame as 8bit mode , 1 stop bit ,no parity */
		UCSRC=0x86; //  0b10000110  set B1,B2(8bit mode) Clear B3( 1 stop bit) Clear B4,B5(no parity)
		
		/* enable RX,TX */
		UCSRB=0x18; // 0b00011000   UCSRB |=(1<<
	
	//UBRRL = 51;
	//UBRRH = 0;
	//
	//UCSRA|= (Normal_Speed)|(Multiprocessor_Off);
	//
	//UCSRB|= (RX_Interrupt_ON)|(TX_Interrupt_Off)|(UDRE_Interrupt_ON)
			//|(Recieve_ON)|(Transmit_ON)|(Off_9Bit)|(Bit9Tx_Off);
			//
	//UCSRC|=(USCRC_Acess)|(Asynchronus_Mode)|(Parity_Disabled)
			//|(One_StopBit)|(Mode_8Bit);
}

void UART_Transmit(TU08 ch)
{
	ch_Transmited = ch;
	/*while (GET_BIT(UCSRA,UDRE)==0)
	{
	}
	UDR=ch;*/
}




TU08 UART_Recieve()
{
	//TU08 ch;
	//while (GET_BIT(UCSRA,RXC)==0)
	//{
	//}
	//ch = UDR;
	//return ch;
	return ch_Recieved;
}


ISR(USART_UDRE_vect)
{
	UDR=ch_Transmited;
}

ISR(USART_RXC_vect)
{
	ch_Recieved = UDR;
}