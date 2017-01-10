/**************************************************
* Objective: Transmit whole string through UART
* S/W: Keil uVision 5
* Author: Manoj Hansda
****************************************************/

#include <REGX51.H>
#include <string.h>

#include "../../TICO_BOARD.H"                // contains Port and Pin definitions of TICO kit board
#include "../../functions/delay.h"           // contains delay()

void show_data();
void show_data2();

unsigned char p=0, k=0, j, str[15], flag=0;
unsigned char show1[]="Hello Guest! What's your name? ";
unsigned char show2[]="Welcome ";
unsigned char show3[]=", we have following items for you:";
unsigned char show4[]="1.Cookies 2.Cakes";

void main()
{

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
		if(SBUF==0x0D)
		{	
			RI=0;
			if(flag==0) show_data();
			else show_data2();
		}
		else
		{
			str[p]=SBUF;
			p++;
			RI=0;
		}
	}
}

void show_data()
{
	for(j=0; j<strlen(show1); j++)
	{
		SBUF=show1[j]; delay(1000); TI=0;
	}
	flag=1;
	p=0;
}

void show_data2()
{
	for(j=0; j<strlen(show2); j++)
	{
		SBUF=show2[j]; delay(1000); TI=0;
	}
	for(j=0; j<strlen(str); j++)
	{
		SBUF=str[j]; delay(1000); TI=0;
	}
	for(j=0; j<strlen(show3); j++)
	{
		SBUF=show3[j]; delay(1000); TI=0;
	}
	
	SBUF=0x0D; delay(1000); TI=0;
	
	for(j=0; j<strlen(show4); j++)
	{
		SBUF=show4[j]; delay(1000); TI=0;
	}
}