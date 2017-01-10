/*********************************************************************************
* Objective: Serial reception on UART from keyboard and display it on 16x2 LCD
* S/W: Keil uVision 5
* Author: Manoj Hansda
**********************************************************************************/

#include <REGX51.H>

#include "../../functions/lcd.h"             // contains send_cmd(), send_data(), send_msg()

void main()
{
	delay(1275);
	lcd_init();
	
	IE=0x90;
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;

	while(1);
}

void serial() interrupt 4
{
	if(RI==1)
	{
		send_data(SBUF);
		RI=0;
	}
}