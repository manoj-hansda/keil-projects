/********************************************
* Objective: Keypad interface of 16x2 LCD
* S/W: Keil uVision 5
* Author: Manoj Hansda
*********************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()
#include "../../functions/lcd.h"             // contains send_cmd(), send_data(), send_msg()

unsigned char *key_pressed, flag=0;

void main()
{
	delay(1275);
	lcd_init();
	
	while(1)
	{
		key_pressed=key_detect();
		if(key_pressed[0]!='\0')
			if(flag==0)
			{
				send_data(key_pressed[0]);
				flag=1;	
			}
			
		else
			flag=0;
	}
}