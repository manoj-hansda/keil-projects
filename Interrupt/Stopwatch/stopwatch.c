/********************************************************************************
* Objective: External interrupt controlled stopwatch on seven segment display
* S/W: Keil uVision 5
* Author: Manoj Hansda
*********************************************************************************/

#include <REGX51.H>

#include "../../functions/seven_segment.h"   // contains display()

unsigned char i=0, j=0, k=0, l=0, dot=0xFF, time[4];
unsigned int count=0;
						
void main()
{	
	IE=0x82;
	TMOD=0x01;
	TH0=0x3C;
	TL0=0xB0;
	TR0=1;
	
	time[0]=time[1]=time[2]=time[3]=0;
	
	while(1)
		display(num_codes, time);
}

void timer0() interrupt 1
{
	TH0=0x3C;
	TL0=0xB0;
	
	if(count++==20)
	{
		count=0;
		i++;
		if(i>9)	{	i=0;	j++;	}			
		if(j>5)	{	j=0;	k++;	}		
		if(k>9)	{	k=0;	l++;	}	
		if(l>5)	{	l=0;	}
		time[0]=i;	time[1]=j;	time[2]=k;	time[3]=l;
		dot=0x7F;
	}
	
	if(count==10)
		dot=0xFF;
}

void stop() interrupt 0
{
		TR0=0;
}