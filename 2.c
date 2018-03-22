#include <avr/io.h>
int main(void)
{
	unsigned char TB7SEG[] = {
	0b00111111, 0b00000110, 0b01011011, 0b01001111,
	0b01100110, 0b01101101, 0b01111101, 0b00000111,
	0b01111111, 0b01101111, 0b01110111, 0b01111100,
	0b00111001, 0b01011110, 0b01111001, 0b01110001};

	unsigned char DISPLY, mask, count, i;
	unsigned char SWITCH, SW1, SW2, SW3, temp;
	DDRD = 0xFF;
	DDRC = 0x00;
	DDRB = 0x00;
	while(1)
	{

		SW1 = PINB;
		SW1 = SW1 & 0x0F;
		SW1 = SW1 << 4;
		SW2 = PINC;
		SW2 = SW2 & 0x0F;
		SWITCH = SW1+SW2;
		mask = 0b00000001;
		count = 0;

		SW3 = PINB;
		SW3 = SW3 & 0b00100000;
		SW3 = SW3 >> 5;
		for(i=0;i<8;i++)
			{
				temp = SWITCH & (mask<<i);
				if(temp)
				count++;
			}
		if(!SW3)
		count = 8 - count;

		DISPLY = TB7SEG[count];
		PORTD = ~DISPLY;
		}
}