/*******************************************************
* Objective: Display custom character on LCD display
* S/W: Keil uVision 5
* Author: Manoj Hansda
********************************************************/

#include <REGX51.H>

#include "../../functions/lcd.h"             // contains send_cmd(), send_data(), send_msg()

#include "symbols.c"           							 // contains 8 custom symbols

unsigned char CG_RAM[8]={0x40, 0x48, 0x50, 0x58, 0x60, 0x68, 0x70, 0x78};

void main()
{
	unsigned char i, j;
	
	delay(1275);
	lcd_init();
	
	for(i=0; i<8; i++)
	{
		send_cmd(CG_RAM[i]);
		for(j=0; j<8; j++)
			send_data(SYMBOLS[i][j]);
	}
	
	send_cmd(0x88);
	
	for(i=0; i<8; i++)
		send_data(i);
	
	while(1);
}