/******************************************************************
* Objective: Blink LED over 1 second using timer 0 (16 bit mode)
* S/W: Keil uVision 5
* Author: Manoj Hansda
*******************************************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board

unsigned int count=0;

void main()
{
	led_pwr_tr=0;
	led_port=0x00;

	IE=0x82;
	TMOD=0x01;
	TH0=0x3C;
	TL0=0xB0;
	TR0=1;

	while(1);
}

void timer0() interrupt 1
{
	TH0=0x3C;
	TL0=0xB0;
	if(count++==20)
	{
		count=0;
		led_port=~led_port;
	}
}
