#include<reg51.h>
sfr lcd_data_port=0x90; /* P1 port as data port */
sbit rs=P2^0; /* Register select pin */
sbit rw=P2^1; /* Read/Write pin */
sbit en=P2^2; /* Enable pin */
void delay(unsigned int count) /* Function to provide delay Approx 1ms */
		{
			int i,j;
			for(i=0;i<count;i++)
			for(j=0;j<112;j++);
		}
void LCD_Command (char cmd) /* LCD16x2 command funtion */
		{
			lcd_data_port= cmd;
			rs=0; /* command reg. */
			rw=0; /* Write operation */
			en=1;
			delay(1);
			en=0;
			delay(5);
		}
void LCD_Char (char char_data) /* LCD data write function */
		{
			lcd_data_port=char_data;
			rs=1; /*Data reg.*/
			rw=0; /*Write operation*/
			en=1;
			delay(1);
			en=0;
			delay(5);
		}
void LCD_String (char *str) /* Send string to LCD function */
		{
			int i;
			for(i=0;str[i]!=0;i++) /* Send each char of string till the NULL */
				{
					LCD_Char (str[i]); /* Call LCD data write */
				}
		}
void LCD_String_xy (char row, char pos, char *str) /* Send string to LCD function */
		{
			if (row == 0)
			LCD_Command((pos & 0x0F)|0x80);
			else if (row == 1)
			LCD_Command((pos & 0x0F)|0xC0);
			LCD_String(str); /* Call LCD string function */
		}
void LCD_Init (void) /* LCD Initialize function */
		{
			delay(20); /* LCD Power ON Initialization time >15ms */
			LCD_Command (0x38); /* Initialization of 16X2 LCD in 8bit mode */
			LCD_Command (0x0C); /* Display ON Cursor OFF */
			LCD_Command (0x06); /* Auto Increment cursor */
			LCD_Command (0x01); /* clear display */
			LCD_Command (0x80); /* cursor at home position */
		}
void LCD_Custom_Char (unsigned char loc, unsigned char *msg)
		{
			unsigned char i;
			if(loc<8)
				{
					/* Command 0x40 and onwards forces the device to point CGRAM address */
					LCD_Command (0x40 + (loc*8));
					for(i=0;i<8;i++) /* Write 8 byte for generation of 1 character */
					LCD_Char(msg[i]);
				}
		}
void main()
		{ 
			char i;
			/* Custom char set for alphanumeric LCD Module */
			unsigned char Character1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };
			unsigned char Character2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
			unsigned char Character3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
			unsigned char Character4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
			unsigned char Character5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
			unsigned char Character6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
			unsigned char Character7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 }
		    unsigned char Character8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };
			LCD_Init();
			LCD_Custom_Char(0, Character1); // Build Character1 at position 0
			LCD_Custom_Char(1, Character2); // Build Character2 at position 1
			LCD_Custom_Char(2, Character3); // Build Character3 at position 2
			LCD_Custom_Char(3, Character4); // Build Character4 at position 3
			LCD_Custom_Char(4, Character5); // Build Character5 at position 4
			LCD_Custom_Char(5, Character6); // Build Character6 at position 5
			LCD_Custom_Char(6, Character7); // Build Character6 at position 6
			LCD_Custom_Char(7, Character8); // Build Character6 at position 7
			LCD_Command(0x80); /* Cursor at home position */
			LCD_String("Custom char LCD");
			LCD_Command(0xc0);
			for(i=0;i<8;i++) // Function will send data 1 to 8 to lcd
				{
					LCD_Char(i);
					LCD_Char(' '); //Space between each custom char
				}
			while(1);
		}