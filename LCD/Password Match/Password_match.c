/*****************************************************
* Objective: User input password check on 16x2 LCD
* S/W: Keil uVision 5
* Author: Manoj Hansda
*******************************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()
#include "../../functions/lcd.h"             // contains send_cmd(), send_data(), send_msg()

void key_action(unsigned char key);
void backspace(void);
void check(void);

unsigned char i=0, *key_pressed, flag=0, match=1, txt[20], pwd[]="manoj";

void main()
{
	delay(1275);
	lcd_init();
	
	while(1)
	{
		key_pressed=key_detect();
		if(key_pressed[0]!='\0')
			if(flag==0)
				key_action(key_pressed[0]);
			
		else
			flag=0;
	}
}


void key_action(unsigned char key)
{
	if(key==0x0F)
		backspace();
	
	else if(key==0xF0)
		check();

	else
	{
		txt[i++]=key;
		send_data(key);
	}
	
	flag=1;		
}

void backspace(void)
{
		send_cmd(0x04);
		send_data(' ');
}

void check(void)
{
	for(i=0; i<strlen(txt); i++)
		if(txt[i]!=pwd[i])
			match=0;
	
	if(match==1)
	{
		send_cmd(0xC0);
		send_msg("Access Granted");
	}
	
	else if(match==0)
	{
		send_cmd(0xC0);
		send_msg("Access Denied");
	}
}