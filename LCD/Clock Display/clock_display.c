/******************************************************************
* Objective: External interrupt triggered stopwatch on 16x2 LCD
* S/W: Keil uVision 5
* Author: Manoj Hansda
*******************************************************************/

#include <REGX51.H>

#include "../../functions/lcd.h"             // contains lcd_init(), send_cmd(), send_data(), send_msg()

unsigned char i=48,j=48,k=48,l=48,m=48,count=0;

void main()
{
	delay(1275);
	lcd_init();

	send_msg("STOPWATCH:");

	send_cmd(0xC0);

	send_data(l);
	send_data(k);
	send_data(':');
	send_data(j);
	send_data(i);
	send_data(':');
	send_data(m);

	IE=0x83;
	TMOD=0x01;
	TH0=0x3C;
	TL0=0xB0;
	TR0=1;

	while(1);
}

void timer0() interrupt 1
{
	TH0=0x3C;
	TL0=0xB0;

	if(count++==1)
	{
		count=0;
		m++;
		if(m>57)	{	m=48;	i++;	}
		if(i>57)	{	i=48;	j++;	}
		if(j>53)	{	j=48;	k++;	}
		if(k>57)	{	k=48;	l++;	}
		if(l>53)	{	l=48;	}
		send_cmd(0xC0);
		send_data(l);
		send_data(k);
		send_data(':');
		send_data(j);
		send_data(i);
		send_data(':');
		send_data(m);
	}
}

void stop() interrupt 0
{
		TR0=0;
}
