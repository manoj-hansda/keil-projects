/**********************************************************************
* Objective: Toggle stepper motor on and off by external interrupt 0
* S/W: Keil uVision 5
* Author: Manoj Hansda
***********************************************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

bit ON=0, OFF=1;

void main()
{
	IE=0x81;
	TCON=0x01;
	
	while(1)
	{
		coil1=ON; coil2=OFF; coil3=OFF; coil4=OFF;
		delay(30000);
		
		coil1=OFF; coil2=ON; coil3=OFF; coil4=OFF;
		delay(30000);
		
		coil1=OFF; coil2=OFF; coil3=ON; coil4=OFF;
		delay(30000);
		
		coil1=OFF; coil2=OFF; coil3=OFF; coil4=ON;
		delay(30000);
	}
}

void toggle() interrupt 0
{
	ON=~ON;
}
