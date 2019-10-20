#include <reg51.h>
void delay(unsigned int);
int main()
{
	unsigned char a[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
	int i;
	while(1)
	{for(i=0;i<8;i++)
		{P1=a[i];
		delay(100);
		}
	}
	return 0;
}

void delay(unsigned int t)
{register unsigned int bt;
	for(; t ;t--)
	for(bt=0;bt<255;bt++);

}