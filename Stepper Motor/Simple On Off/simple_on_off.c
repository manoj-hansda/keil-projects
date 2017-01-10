/**********************************************
* Objective: Simple stepper motor on and off
* S/W: Keil uVision 5
* Author: Manoj Hansda
***********************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

#define ON  0
#define OFF 1

void main()
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
