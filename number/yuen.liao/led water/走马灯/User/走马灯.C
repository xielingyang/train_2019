#include "reg51.h"
sbit L0=P0^0;
sbit L1=P0^1;
sbit L2=P0^2;
sbit L3=P0^3;
sbit L4=P0^4;
sbit L5=P0^5;
sbit L6=P0^6;
sbit L7=P0^7;
void delay(void)
{  int i;
	for(i=30000;i>0;i--);
}
void main()
{  L0=0;
   delay();
   L0=1;
   delay();
   L1=0;
   delay();
   L1=1;
   delay();
   L2=0;
   delay();
   L2=1;
   delay();
   L3=0;
   delay();
   L3=1;
   delay();
   L4=0;
   delay();
   L4=1;
   delay();
   L5=0;
   delay();
   L5=1;
   delay();
   L6=0;
   delay();
   L6=1;
   delay();
   L7=0;
   delay();
   L7=1;
   delay();
   }