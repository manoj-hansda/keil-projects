/*********************************
* Objective: Blink 8 LED panel
* S/W: Keil uVision 5
* Author: Manoj Hansda
***********************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

unsigned char bits=0;

void main()
{	
	led_pwr_tr=0;
	
	while(1)
	{
		led_port=~bits;
		delay(30000);
	}
}