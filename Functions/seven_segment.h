#ifndef _seven_segment_
#define _seven_segment_

#include "../TICO_BOARD.H"
#include "delay.h"

enum alpha {A, C, E, F, H, I, L, p, S, U};
unsigned char alpha_codes[10]={0x88, 0xC6, 0x86, 0x8E, 0x89, 0xF9, 0xC7, 0x8C, 0x92, 0xC1};
unsigned char num_codes[10]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char char_codes[20]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0xC6, 0x86, 0x8E, 0x89, 0xF9, 0xC7, 0x8C, 0x92, 0xC1};

void display(char codes[], char *datas)
{
	seg_port=codes[datas[0]];
	unit_tr_ca=0;
	delay(10);
	unit_tr_ca=1;

	seg_port=codes[datas[1]];
	tens_tr_ca=0;
	delay(10);
	tens_tr_ca=1;

	seg_port=codes[datas[2]];
	hund_tr_ca=0;
	delay(10);
	hund_tr_ca=1;

	seg_port=codes[datas[3]];
	thou_tr_ca=0;
	delay(10);
	thou_tr_ca=1;
}

#endif
