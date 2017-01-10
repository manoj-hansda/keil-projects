/***********************************************************************
* Objective: Rotate multi LEDs left or right
* S/W: Keil uVision 5
* Author: Manoj Hansda
*************************************************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

void left(void);
void right(void);						

unsigned char i, bits, led=4;									//number of LEDs

void main()
{
	led_pwr_tr=0;	
	   
	while(1)
	{		
		left();						//toggle left or right by
		//right();				//un-commenting one of both
	}
}

void left(void)
{	
	for(i=0; i<led; i++)
	{
	  bits=bits>>1;
	  led_port=bits;
	  delay(15000);  		
	}
	for(i=0; i<8; i++)
	{
	  bits=bits>>1;
	  bits=bits+0x80;
	  led_port=bits;
	  delay(15000);	
	}	
}

void right(void)
{
	for(i=0; i<led; i++)
	{
	  bits=bits<<1;
	  led_port=bits;
	  delay(15000);  		
	}
	for(i=0; i<8; i++)
	{
	  bits=bits<<1;
	  bits=bits+0x01;
	  led_port=bits;
	  delay(15000);	
	}	
}