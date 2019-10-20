#include <reg51.h>

sbit led1=P1^0;
sbit led2=P1^1;
sbit led3=P1^2;
sbit led4=P1^3;
sbit led5=P1^4;
sbit led6=P1^5;
sbit led7=P1^6;
sbit led8=P1^7;
void delay(int z)
{
	unsigned int x,y;
for(x=z;x>0;x--)
	y++;
}
int main()
{
while(1)
{
	led1=0;
	delay(200);
	led1=1;
	led2=0;
	delay(200);
	led2=1;
	led3=0;
	delay(200);
	led3=1;
	led4=0;
	delay(200);
	led4=1;
	led5=0;
	delay(200);
	led5=1;
	led6=0;
	delay(200);
	led6=1;
	led7=0;
	delay(200);
	led7=1;
	led8=0;
	delay(200);
	led8=1;
}
return 0;
}