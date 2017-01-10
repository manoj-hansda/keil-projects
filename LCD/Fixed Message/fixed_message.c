/********************************************
* Objective: Fixed message on LCD display
* S/W: Keil uVision 5
* Author: Manoj Hansda
**********************************************/

#include <REGX51.H>

#include "../../functions/lcd.h"             // contains send_cmd(), send_data(), send_msg()

void main()
{
	delay(1275);
	lcd_init();
	send_msg("Welcome");
	while(1);
}