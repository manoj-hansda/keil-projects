/**************************************************************************************************
* Objective: Pressing differnet keys from 4x3 keypad triggers different functions on 8 LED panel
* S/W: Keil uVision 5
* Author: Manoj Hansda
***************************************************************************************************/

#include <REGX51.H>

#include "../../functions/keypad.h"          // contains key_detect()
#include "../../functions/delay.h"           // contains delay()
#include "led_functions.c"          				 // contains led functions

void key_action(unsigned char);

bit flag=0;
unsigned char *key_pressed;

void main()
{
	led_pwr_tr=0;
	
	while(1)
	{
		key_pressed=key_detect();
		if(key_pressed[0]!='\0')
			if(flag==0)
				key_action(key_pressed[0]);
	}
}

void key_action(unsigned char key)
{
	switch(key)
	{
		case 1:
			binary_counting();
			break;
		
		case 2:
			led_blink();
			break;
		
		case 3:
			swap_4_led();
			break;
		
		case 4:
			rotate_led_left();
			break;
		
		case 5:
			rotate_led_right();
			break;
		
		case 6:
			conv_and_div();
			break;
		
		case 7:
			multi_led_rotate();
			break;
		
		case 8:
			sand_glass();
			break;
	}
}