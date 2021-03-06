/*****************************************
* Objective: Simple DC motor on and off
* S/W: Keil uVision 5
* Author: Manoj Hansda
*******************************************/

#include <REGX51.H>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

#define ON 	1
#define OFF 0

void main()
{
	DC_motor=ON;
	delay(500000);
	DC_motor=OFF;
	delay(500000);
}
