/*************************************************************************
* Objective: Show PASS or FAIL on 7-segment displays based on pin entry
* S/W: Keil uVision 5
* Author: Manoj Hansda
**************************************************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"         // contains key_detect()
#include "../../functions/seven_segment.h"  // contains display()

char * key_action(unsigned char key);
void check(void);

unsigned char *key_pressed, flag=0, match=1;
unsigned char digits[4]={0,0,0,0}, pwd[4]={1,2,3,4}, *val, *values2;
unsigned char pass[4]={S,S,A,p}, fail[4]={L,I,A,F};

void main()
{
	while(1)
	{
		key_pressed=key_detect();
		
		if(key_pressed[0]!='\0')
			if(flag==0)
				val=key_action(key_pressed[0]);
			
		else
			flag=0;

		display(num_codes, val);
	}
}

char * key_action(unsigned char key)
{
	if(key!=0x0F && key!=0xF0)
	{
		digits[3]=digits[2];
		digits[2]=digits[1];
		digits[1]=digits[0];
		digits[0]=key;
		flag=1;
	}

	else if(key==0xF0)
		check();

	return digits;
}

void check(void)
{
	unsigned char i;
	
	for(i=0; i<4; i++)
	{
		if(digits[i]!=pwd[3-i])
			match=0;
	}
	
	if(match==1)
	{
		val=pass;
		while(1)
			display(alpha_codes, val);
	}
	
	else if(match==0)
	{
		val=fail;
		while(1)
			display(alpha_codes, val);
	}
}