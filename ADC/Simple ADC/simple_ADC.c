/********************************************
* Objective: Analog-to-Digital conversion
* S/W: Keil uVision 5
* Author: Manoj Hansda
**********************************************/

#include <REGX51.H>

#include "../../functions/seven_segment.h"   // contains display()

unsigned char * convert();

unsigned char unit=0,tens=0,hund=0,thou=0, tmp, *val;

void main()
{
P0=0xff;
P1=0xff;
P2=0xff;
P3=0xff;
led_pwr_tr=0;
unit_tr_ca=0;
TMOD=0x01;
TL0=0xB0;
TH0=0xff;
TR0=1;
IE=0x82;

clock=0;
unit_tr_ca=0;
ALE=0;
SC=0;
EOC=1;
OE=0;

	while(1)
	{
		ADD_A=0;	ADD_B=1;

		ALE=0;	delay(100);	ALE=1;

		SC=1;	delay(100);	SC=0;

		while(EOC==1);
		while(EOC==0);

		seg_port=0xFF;
		OE=1;
		tmp=seg_port;
		OE=0;

		seg_port=0X00;	  
		tmp=seg_port;
		val=convert();  
		display(num_codes, val);
		delay(100);
		clock=0;
	}
}

unsigned char * convert()
{
	unsigned char value[4];
	
	unit=tmp%10; 
	tens=(tmp/10)%10;
	hund=(tmp/100)%10;
	thou=tmp/1000;
	
	value[0]=unit;	value[1]=tens;	value[2]=hund;	value[3]=thou;
	return value;
}

void action() interrupt 1
{
	clock=~clock;
}