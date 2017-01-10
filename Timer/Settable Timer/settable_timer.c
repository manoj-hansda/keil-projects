/******************************************
* Objective: Settable timer on 16x2 LCD
* S/W: Keil uVision 5
* Author: Manoj Hansda
********************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()
#include "../../functions/lcd.h"             // contains send_cmd(), send_data(), send_msg()

void key_action(unsigned char);

unsigned char i=48,j=48,k=48,l=48,m=48,count=0,pos=0;
unsigned char *key_pressed, g=0, flag=0, txt[4];

void main()
{
	delay(1275);
	lcd_init();

	send_msg("Set Time:");

	send_data('m');
	send_data('m');
	send_data(':');
	send_data('s');
	send_data('s');

	send_cmd(0xC0);
	send_data(l);
	send_data(k);
	send_data(':');
	send_data(j);
	send_data(i);
	send_data(':');
	send_data(m);

	send_cmd(0x89);
	while(1)
	{
		key_pressed=key_detect();
		if(key_pressed[0]!='\0')
		{
			if(flag==0)
			key_action(key_pressed[0]);
		}
		else
			flag=0;

		if(g==4)
			break;
	}

	send_cmd(0x0C);
	IE=0x83;

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

		if(i==txt[3] && j==txt[2] && k==txt[1] && l==txt[0])
		{
			TR0=0;
		}

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
	TMOD=0x01;
	TH0=0x3C;
	TL0=0xB0;
	TR0=1;
}

void key_action(unsigned char value)
{
		txt[pos]=value;
		pos++;
		send_data(value);
		flag=1;
		g++;
		if(g==2)
			send_cmd(0x8C);
}
