#include <reg51.h>
#include <intrins.h>
sbit led1=P1^0;
void main()
{
	void delay();
	unsigned int a=0x01;
	while(1)
	{
	P1=a;
	delay();
	a=_crol_(a,1);
	delay();
}
	}
void delay()
{unsigned int j;
	for(j=1;j<4500;j++);
}