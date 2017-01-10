#include "../../functions/delay.h"          // contains delay()

void binary_counting(void)
{
	unsigned char bits=0;
	while(bits<256)
	{
		led_port=~bits;
		delay(50000);
		bits++;
	}
}

void led_blink(void)
{
	unsigned char bits=0;	
	led_pwr_tr=0;
	while(1)
	{
		led_port=~bits;
		delay(30000);
	}
}

void swap_4_led(void)
{
	unsigned char bits=0x0F;
	while(1)
	{
		led_port=~bits;
		delay(30000);
	}
}

void rotate_led_left(void)
{
	unsigned char i, bits;
	led_pwr_tr=0;
	while(1)
	{
		bits=0xFF;
		for(i=0; i<8; i++)
		{
			bits=bits>>1;
			bits=bits+0x80;
			led_port=bits;
			delay(15000);	
		}	
	}
}

void rotate_led_right(void)
{
	unsigned char i, bits;
	led_pwr_tr=0;
	while(1)
	{
		bits=0xFF;
		for(i=0; i<8; i++)
		{
			bits=bits<<1;
			bits=bits+0x01;
			led_port=bits;
			delay(15000);	
		}	
	}
}

void conv_and_div(void)
{
	
}

void multi_led_rotate(void)
{
	unsigned char i, bits, led=4;
	led_pwr_tr=0;	   
	while(1)
	{		
		for(i=0; i<led; i++)
		{
			bits=bits>>1;
			led_port=bits;
			delay(15000);  		
		}
		for(i=0; i<8; i++)
		{
			bits=bits>>1;
			bits=bits+0x80;
			led_port=bits;
			delay(15000);	
		}	
	}
}

void sand_glass(void)
{
	unsigned char i, hold, value=0, length=8, bits=0x80;

	while(1)
	{															 
		hold=bits;
	  for(i=0; i<length; i++)
		{
			led_port=~bits;
			delay(30000);
			bits=bits>>1;
		}
		length--;
		bits=hold|0x80;
		value=value<<1;
		bits=bits+~value;
	}	
}