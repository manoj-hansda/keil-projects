#ifndef _lcd_
#define _lcd_

#include <string.h>

#include "../TICO_BOARD.H"
#include "delay.h"

void lcd_init();
void send_cmd(unsigned char);
void send_data(unsigned char);
void send_msg(unsigned char msg[]);

void lcd_init()
{
	send_cmd(0x28); send_cmd(0x28); send_cmd(0x28);
	send_cmd(0x0F);
	send_cmd(0x06);
	send_cmd(0x02);
	send_cmd(0x01);
}

void send_cmd(unsigned char value)
{
	rs=0;
	lcd_port=value;
	en=0; delay(100); en=1;
	value=value<<4;
	lcd_port=value;
	en=0; delay(100); en=1;
}

void send_data(unsigned char value)
{
	rs=1;
	lcd_port=value;
	en=0; delay(10); en=1;
	value=value<<4;
	lcd_port=value;
	en=0; delay(10); en=1;
}

void send_msg(unsigned char msg[])
{
	unsigned char i;
	for(i=0; i<strlen(msg); i++)
		send_data(msg[i]);
}

#endif
