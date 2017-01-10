/*****************************************************************
* Objective: Toggle 8 LED panel on off by external interrupt 0
* S/W: Keil uVision 5
* Author: Manoj Hansda
*******************************************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
						
void main()
{
	led_pwr_tr=0;
	led_port=0x00;
	
	IE=0x81;
	TCON=0x01;

	while(1);
}

void toggle() interrupt 0
{
	led_port=~led_port;
}