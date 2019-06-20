/*
 * SSD.c
 *
 * Created: 31-Mar-19 6:10:55 PM
 *  Author: Ammar Shahin
 */ 
#include "SSD.h"

void SSD_Init()
{
	SSD_DIR=0x7f;
	#ifdef  SSD_COMMAN_CATHODE
		SSD_PORT=0x3f;
	#endif //SSD_COMMAN_CATHODE
	
	#ifdef SSD_COMMAN_ANODE
		SSD_PORT=0x40;
	#endif // SSD_COMMAN_ANODE
}

void SSD_Display_8Bit(TU08 number)
{
	symbole x = number;
	switch (x)
	{
		case 0:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x3f;
			#endif //SSD_COMMAN_CATHODE
			
			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0xc0;
			#endif // SSD_COMMAN_ANODE
		break;

		case 1:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x06;//00110000
			#endif //SSD_COMMAN_CATHODE
			
			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0xf9;
			#endif // SSD_COMMAN_ANODE
		break;

		case 2:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x5b;
			#endif //SSD_COMMAN_CATHODE
		
			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0xa4;
			#endif // SSD_COMMAN_ANODE
		break;

		case 3:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x4f;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0xb0;
			#endif // SSD_COMMAN_ANODE
		break;

		case 4:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x66;
			#endif //SSD_COMMAN_CATHODE
			
			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x99;
			#endif // SSD_COMMAN_ANODE
		break;

		case 5:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x6d;
			#endif //SSD_COMMAN_CATHODE
		
			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x92;
			#endif // SSD_COMMAN_ANODE
		break;

		case 6:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x7d;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x82;
			#endif // SSD_COMMAN_ANODE
		break;

		case 7:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x07;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0xf8;
			#endif // SSD_COMMAN_ANODE
		break;

		case 8:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x7f;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x80;
			#endif // SSD_COMMAN_ANODE
		break;

		case 9:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x6f;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x90;
			#endif // SSD_COMMAN_ANODE
		break;

		case A:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x77;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x08;
			#endif // SSD_COMMAN_ANODE
		break;

		case B:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x7c;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x03;
			#endif // SSD_COMMAN_ANODE
		break;

		case C:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x39;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x70;
			#endif // SSD_COMMAN_ANODE
		break;

		case D:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x5e;
			#endif //SSD_COMMAN_CATHODE

			#ifdef  SSD_COMMAN_ANODE
				SSD_PORT=0x21;
			#endif // SSD_COMMAN_ANODE
		break;

		case E:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x79;
			#endif //SSD_COMMAN_CATHODE

			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x30;
			#endif // SSD_COMMAN_ANODE
		break;

		case F:
			#ifdef  SSD_COMMAN_CATHODE
				SSD_PORT=0x71;
			#endif //SSD_COMMAN_CATHODE
			
			#ifdef SSD_COMMAN_ANODE
				SSD_PORT=0x38;
			#endif // SSD_COMMAN_ANODE
		break;

		default:
		break;
	}
}

void SSD_Display_BCD(TU08 i)
{
	PUTVAL_LOWER_NIBBLE(SSD_PORT,i);
}