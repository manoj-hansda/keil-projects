/***********************************************************
* Objective: Serial transmission on UART from 4x3 keypad
* S/W: Keil uVision 5
* Author: Manoj Hansda
*************************************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()
#include "../../functions/lcd.h"             // contains send_cmd(), send_data(), send_msg()

void key_action(unsigned char);

unsigned char *key_pressed, flag=0;

void main()
{
	delay(1275);
	lcd_init();
	
	IE=0x90;
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
	
	while(1)
		key_pressed=key_detect();
}

void serial() interrupt 4
{ 
	if(key_pressed[0]!='\0')
		{
			ES=0;
			if(flag==0)
			key_action(key_pressed[0]);
			ES=1;
		}
	else
		flag=0;
}

void key_action(unsigned char value)
{
		send_data(value);
		SBUF=value;
		TI=0;
		flag=1;
}