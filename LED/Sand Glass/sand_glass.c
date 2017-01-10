/*****************************************
* Objective: Sand glass on 8 LED panel
* S/W: Keil uVision 5
* Author: Manoj Hansda
******************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

unsigned char i, hold, value=0, length=8, bits=0x80;
	
void main()
{
	while(1)
	{															 
		hold=bits;
	  for(i=0; i<length; i++)
		{
			led_port=~bits;
			delay(30000);
			bits=bits>>1;
		}
		length--;
		bits=hold|0x80;
		value=value<<1;
		bits=bits+~value;
	}
}