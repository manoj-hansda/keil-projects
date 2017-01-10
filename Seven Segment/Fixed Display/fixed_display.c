/*******************************************************
* Objective: Fixed display on seven segment displays
* S/W: Keil uVision 5
* Author: Manoj Hansda
*********************************************************/

#include <REGX51.H>

#include "../../functions/seven_segment.h"   // contains display()

unsigned char values[]={1,2,3,4};

void main()
{
	unsigned char *val=values;
	
	while(1)
		display(num_codes, val);
}