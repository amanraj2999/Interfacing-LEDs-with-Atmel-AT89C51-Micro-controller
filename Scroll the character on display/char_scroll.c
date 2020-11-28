#include<reg51.h>
sbit rs=P1^0; //data-command pin
sbit rw=P1^1; //read-write pin
sbit en=P1^2; //data enable pin
void lcdcmd(unsigned char); //function declarations
void lcddat(unsigned char);
void delay();
void main()
{
	P2=0x00; //output declaration
	lcdcmd(0x38); // 5X7 matrix crystal
	delay();
	lcdcmd(0x01); //clear screen
	delay();
	lcdcmd(0x10); // cursor blinking
	delay();
	lcdcmd(0x0c); //display on
	delay();
	lcdcmd(0x81); //force cursor first line first position
	delay();
	lcddat('A'); //defining characters to be displayed on lcd screen
	delay();
	lcddat('M'); delay(); //giving delay
	lcddat('A'); delay();
	lcddat('N'); delay();
	lcddat(' '); delay();
	lcddat('R'); delay();
	lcddat('A'); delay();
	lcddat('J'); delay();
	lcddat(' '); delay();
	lcddat('I'); delay();
	lcddat('N'); delay();
	lcddat('T'); delay();
	lcddat('E'); delay();
	lcddat('R'); delay();
	lcddat('N'); delay();
	lcddat(' '); delay();
	lcdcmd(0xc3); delay(): //move cursor to second line position three
	lcddat('A'); delay();
	lcddat('T'); delay();
	lcddat(' '); delay();
	lcddat('I'); delay();
	lcddat('I'); delay();
	lcddat('T'); delay();
	lcddat('P'); delay();
	while(1)
		{
			lcdcmd(0x1C); delay(); //scroll the entire text to the right
		}
	}
void lcdcmd(unsigned char val) //defining lcdcmd() function
	{
		P2=val; rs=0; rw=0;
		en=1; delay();
		en=0;
	}
void lcddat(unsigned char val) //defining lcddat() function
	{
		P2=val; rs=1; rw=0;
		en=1; delay();
		en=0;
	}
void delay() //defining delay() function
	{ 
		unsigned int i;
		for (i=0;i<12000;i++); //loop for delay
	}