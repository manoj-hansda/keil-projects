#ifndef _keypad_
#define _keypad_

#include "../TICO_BOARD.H"

unsigned char * key_detect()
{
	unsigned char key[4];
	key[0]=key[1]=key[2]=key[3]='\0';

	row1=0; row2=row3=row4=1;
	if(col1==0) {	key[0]='1';	key[1]='A';	key[2]='B';	key[3]='C';	}
	if(col2==0) {	key[0]='2';	key[1]='D';	key[2]='E';	key[3]='F';	}
	if(col3==0) {	key[0]='3';	key[1]='G';	key[2]='H';	key[3]='I';	}

	row2=0; row1=row3=row4=1;
	if(col1==0) {	key[0]='4';	key[1]='J';	key[2]='K';	key[3]='L';	}
	if(col2==0) {	key[0]='5';	key[1]='M';	key[2]='N';	key[3]='O';	}
	if(col3==0) {	key[0]='6';	key[1]='P';	key[2]='Q';	key[3]='R';	}

	row3=0; row1=row2=row4=1;
	if(col1==0) {	key[0]='7';	key[1]='S';	key[2]='T';	key[3]='U';	}
	if(col2==0) {	key[0]='8';	key[1]='V';	key[2]='W';	key[3]='X';	}
	if(col3==0) {	key[0]='9';	key[1]='Y';	key[2]='Z';	key[3]='C';	}

	row4=0; row1=row2=row3=1;
	if(col1==0) {	key[0]='*';	key[1]='*';	key[2]='*';	key[3]='*';	}
	if(col2==0) {	key[0]='0';	key[1]=' ';	key[2]=' ';	key[3]=' ';	}
	if(col3==0) {	key[0]='#';	key[1]='#';	key[2]='#';	key[3]='#';	}

	return (key);
}

#endif
