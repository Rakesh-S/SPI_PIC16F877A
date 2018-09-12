/* This example demonstrate sending single 
	character 'A' using spi protocol (Master mode) in PIC16F877A 
*/

#include<pic.h>
void delay(int a)
{
	int i,j;
	for(i=0;i<a;i++)
		for(j=0;j<a;j++);
}
void spi_init()
{
	SSPSTAT = 0X80;
	SSPCON = 0X20;
}
void spi_sent(b)
{
	SSPBUF = b;
	delay(200);
}	
int main()
{
	TRISC = 0X10;
	spi_init();
	while(1)
	{
		spi_sent('B');
		while(WCOL == 1);
		WCOL = 0;
		delay(300);
	}
}
