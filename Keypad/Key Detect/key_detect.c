/******************************************************************************************
* Objective: Detect key from 4x3 keypad and blink their binary equivalent on 8 LED panel
* S/W: Keil uVision 5
* Author: Manoj Hansda
*******************************************************************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()

unsigned char  *key_pressed;

void main()
{
	led_pwr_tr=0;
	
	while(1)
	{
		key_pressed=key_detect();
		led_port=~key_pressed[0];
	}
}