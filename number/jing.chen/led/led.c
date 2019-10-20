#include <reg51.h>

sbit led=P1^0;
int main ()
{
	
	while(1)
	{
	if (led=1)led=0;
		else led=1;
	}
	
	
return 0;
}