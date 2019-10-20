#include <reg51.h>
sbit led=P1^0;
void b(int x)
{
	unsigned int y;
	for(y=0;y<x;y++);
}
int main()
{
	while(1)
	{
		led=0;
		b(10000);
		led=1;
		b(10000);
	}
	return 0;
}
