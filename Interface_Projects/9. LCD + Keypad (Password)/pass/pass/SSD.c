/*
 * SSD.c
 *
 * Created: 4/4/2019 12:44:20 PM
 *  Author: ammarPC
 */ 

#include "SSD.h"

void display_8d(TU08 i)
{
	switch(i)
	{
		case 0 :
		PORTC = 0xc0;
		break;
		case 1 :
		PORTC = 0xf9;
		break;
		case 2 :
		PORTC = 0xa4;
		break;
		case 3 :
		PORTC = 0xb0;
		break;
		case 4 :
		PORTC = 0x99;
		break;
		case 5 :
		PORTC = 0x92;
		break;
		case 6 :
		PORTC = 0x82;
		break;
		case 7 :
		PORTC = 0xf8;
		break;
		case 8 :
		PORTC = 0x80;
		break;
		case 9 :
		PORTC = 0x90;
		break;
		default:
		break;
	}
}

void display_BCD(TU08 i)
{
	switch(i)
	{
		case 0 :
		
		break;
		case 1 :
		PORTC = 0xf1;
		break;
		case 2 :
		PORTC = 0xf2;
		break;
		case 3 :
		PORTC = 0xf3;
		break;
		case 4 :
		PORTC = 0xf4;
		break;
		case 5 :
		PORTC = 0xf5;
		break;
		case 6 :
		PORTC = 0xf6;
		break;
		case 7 :
		PORTC = 0xf7;
		break;
		case 8 :
		PORTC = 0xf8;
		break;
		case 9 :
		PORTC = 0xf9;
		break;
		default:
		break;
	}
}