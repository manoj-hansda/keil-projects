#ifndef TICO_BOARD
#define TICO_BOARD

#define led_port P0		// 8 lED panel port
#define seg_port P0		// 7 segment display port
#define lcd_port P0		// 16x2 LCD port
#define adc_port P3         	// ADC Port

sbit led_pwr_tr=P1^4;		// LED panel power on pnp transistor

sbit rs=P2^4;			// LCD register select
sbit en=P2^5;			// LCD enable

// 4x3 keypad matrix
sbit row1=P1^0;
sbit row2=P1^1;
sbit row3=P1^2;
sbit row4=P1^3;
sbit col1=P1^5;
sbit col2=P1^6;
sbit col3=P1^7;

// 7 segment displays power on pnp transistor
sbit unit_tr_ca=P2^0;
sbit tens_tr_ca=P2^1;
sbit hund_tr_ca=P2^2;
sbit thou_tr_ca=P2^3;

// DC motor
sbit DC_motor=P3^4;

// Stepper motor windings
sbit coil1=P3^4;
sbit coil2=P3^5;
sbit coil3=P3^6;
sbit coil4=P3^7;

// Buzzer
sbit buzz=P2^7;

// Relay
sbit relay=P2^6;

// ADC Controls

sbit SC=P3^2;
sbit ALE=P3^2;
sbit EOC=P3^3;
sbit clock=P3^4;
sbit OE=P3^5;
sbit ADD_A=P3^6;
sbit ADD_B=P3^7;

#endif
