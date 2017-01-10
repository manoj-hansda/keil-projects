/***************************************
* Objective: Rotate a single LED left
* S/W: Keil uVision 5
* Author: Manoj Hansda
****************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

unsigned char i, bits;

void main()
{
	led_pwr_tr=0;
 
	while(1)
	{
		bits=0xFF;
		for(i=0; i<8; i++)
		{
			bits=bits>>1;
			bits=bits+0x80;
			led_port=bits;
			delay(15000);	
		}	
	}
}