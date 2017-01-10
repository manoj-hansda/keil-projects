/******************************************
* Objective: Count external interrupt 0
* S/W: Keil uVision 5
* Author: Manoj Hansda
********************************************/

#include <REGX51.H>

#include "../../functions/seven_segment.h"   // contains display()

unsigned char i=0, j=0, k=0, l=0;
unsigned char count[4]={0,0,0,0};

void main()
{
	IE=0x81;
	TCON=0x01;
	
	while(1)
		display(num_codes, count);
}

void toggle() interrupt 0
{
	i++;
	if(i>9)	{	i=0;	j++;	}			
	if(j>9)	{	j=0;	k++;	}		
	if(k>9)	{	k=0;	l++;	}	
	if(l>9)	{	l=0;	}
	
	count[0]=i;	count[1]=j;	count[2]=k;	count[3]=l;
}