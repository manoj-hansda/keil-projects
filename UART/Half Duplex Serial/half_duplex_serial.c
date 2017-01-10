#include <REGX51.H>
#define led_port P0

sbit led_pwr_tr=P1^4;

void main()
{
	led_pwr_tr=0;
	
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
		led_port=SBUF;
		RI=0;
	}

}