/***************************************
* Objective: LEDs coverge and diverge
* S/W: Keil uVision 5
* Author: Manoj Hansda
****************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

unsigned char i, d=5, bits1, bits2;

void main()
{
	led_pwr_tr=0;	
	   
	while(1)
	{
		bits1=0x7F; bits2=0xFE;

		for(i=0; i<8; i++)
		{	
			while(d--)
			{
				led_port=bits1;
				delay(500);
				led_port=bits2;
				delay(500);
			}
			bits1=bits1>>1;
			bits1=bits1+0x80;
			bits2=bits2<<1;
			bits2=bits2+0x01;
			d=5;
		 }
	}
}
