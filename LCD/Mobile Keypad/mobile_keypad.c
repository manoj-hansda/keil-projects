/***************************************************************
* Objective: Mobile type input through 4x3 keypad to 16x2 LCD
* S/W: Keil uVision 5
* Author: Manoj Hansda
****************************************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()
#include "../../functions/lcd.h"             // contains send_cmd(), send_data(), send_msg()

unsigned char i=0, l=0, var=0, *key_pressed, flag=0;
unsigned int  count=0;

void main()
{
	delay(1275);
	lcd_init();

	IE=0x82;
	TMOD=0x01;
	TH0=0x3C;
	TL0=0xB0;
	send_cmd(0x88);

	while(1)
	{
		key_pressed=key_detect();
		if(key_pressed[0]!='\0')
		{
			if(flag==0)
			{
				TR0=1;
				flag=1;
			}
		}

		else
		{
			TR0=0;
			flag=0;
			count=0;
			send_cmd(0x06);
		}
	}
}

void timer0() interrupt 1
{
	TH0=0x3C;
	TL0=0xB0;

	count++;

	if(count==5)
		send_data(key_pressed[0]);

	else if(count==30)
	{
		send_cmd(0x04);
		send_data(' ');
		send_cmd(0x06);
		send_data(key_pressed[1]);
	}

	else if(count==60)
	{
		send_cmd(0x04);
		send_data(' ');
		send_cmd(0x06);
		send_data(key_pressed[2]);
	}

	else if(count==90)
	{
		send_cmd(0x04);
		send_data(' ');
		send_cmd(0x06);
		send_data(key_pressed[3]);
	}

}
