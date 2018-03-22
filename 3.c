#include <avr/io.h>
int main(void)
{
	unsigned char TB7SEG[] = {
	0b00111111, 0b00000110, 0b01011011, 0b01001111,
	0b01100110, 0b01101101, 0b01111101, 0b00000111,
	0b01111111, 0b01101111, 0b01110111, 0b01111100,
	0b00111001, 0b01011110, 0b01111001, 0b01110001};
	unsigned char DISPLY;
	unsigned char SWITCH;
	//กำหนดทิศทางให้บอร์ด
	DDRD = 0xFF; //output
	DDRB = 0x00; //input
	DDRC = 0x01;
	while(1)//ต้องการลูปไม่รู้จบ
	{
		SWITCH = PINB;//ตัวแปล อ่านค่า
		SWITCH &= 0b00111100; // 0-3 ต้องกำจัดข้อมูลที่ไม่มีโดยการ & 0b00001111
		SWITCH = SWITCH >> 2; //ใช้สำหรับชิปเพื่อให้ตรง

		if(SWITCH < 8){
			PORTC = 0x01;
		}else {
			PORTC = 0x00;
			SWITCH = 16 - SWITCH;
		}


		DISPLY = TB7SEG[SWITCH];
		PORTD = ~DISPLY;
	}
}