#include "reg51.h"
sbit led =P2^1;
int main()
{ int i;
    while(1)
{ 
	led=0;
	for(i=1000;i>0;i--);
	led=1;
	for(i=1000;i>0;i--);
	}
}