/************************************************************
* Objective: Interface keypad with seven segment displays
* S/W: Keil uVision 5
* Author: Manoj Hansda
*************************************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()
#include "../../functions/seven_segment.h"   // contains display()

unsigned char *key_pressed, digits[4];
void main()
{
	unsigned char i=4, *val;
	while(1)
	{
		key_pressed=key_detect();
		
		while(i--)
			digits[i]=key_pressed[0];		
		
		val=digits;
		display(num_codes, val);
	}
}