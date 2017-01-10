/****************************************************
* Objective: Toggle buzzer by external interrupt 0
* S/W: Keil uVision 5
* Author: Manoj Hansda
*****************************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

bit state=0;

void main()
{
	IE=0x81;
	TCON=0x01;
	
	while(1);
}

void toggle() interrupt 0
{
	buzz=~state;
	delay(500000);
}