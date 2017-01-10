/*********************************************************************************
* Objective: Calculator type entry on seven segment displays through 4x3 keypad
* S/W: Keil uVision 5
* Author: Manoj Hansda
**********************************************************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()
#include "../../functions/seven_segment.h"   // contains display()

void key_action(unsigned char key);

unsigned char *key_pressed, flag=0, digits[4]={0,0,0,0};

void main()
{
	unsigned char *val;
	
	while(1)
	{
		key_pressed=key_detect();
		
		if(key_pressed[0]!='\0')
			if(flag==0)
				key_action(key_pressed[0]);
			
		else
			flag=0;
		
		val=digits;
		display(num_codes, val);
	}
}

void key_action(unsigned char key)
{
			digits[3]=digits[2];
			digits[2]=digits[1];
			digits[1]=digits[0];
			digits[0]=key;
			flag=1;
}