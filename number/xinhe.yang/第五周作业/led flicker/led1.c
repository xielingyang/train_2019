#include<reg51.h>
sbit led=P1^0;
unsigned int i;
	
int main()
{while(1)
	{led=1;for(i=0;i<30000;i++){};
led=0;for(i=0;i<30000;i++){};
	}
}