/* This example demonstrate sending single 
	character 'A' using spi protocol in PIC16F877A 
*/

#include<pic.h>
#define SS RC2
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
	SS = 0;
	SSPBUF = b;
	delay(200);
	SS = 1;
	delay(200);
}	
int main()
{
	TRISC = 0X10;
	spi_init();
	while(1)
	{
		spi_sent('A');
		delay(300);
	}
}
