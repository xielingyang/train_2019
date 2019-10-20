#include "reg51.h" 
#define uint unsigned int
#define uchar unsigned char
void Key_Control(int keyValue);
void delay_ms(int t);
int Key_Scan(void) ;
void display();
void time_init();
uint location=0;
uint  n=0,a,b;
uchar table[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
//uchar DigCode[6]={~0x01,~0x02,~0x04,~0x08,~0x10,~0x20};
uchar DigCode[6]={~0x20,~0x10,~0x08,~0x04,~0x02,~0x01};
uint miao=0;		
uint fen=0;			
uint shi=0;	
uint button_flag=0;

unsigned char InterruptCount = 0;
			
uint date[6]={0,0,0,0,0,0};
int main()	
{   
	IE = 0x83;
	IT0 = 0; 
    
	
	  time_init();
	  while(1)         
     {  
     
		 display();
		 }
}
			
void display()
{
 	 


	for(a = 6; a > 0; a--)  
  {   for(b = 0; b <6; b++)  
	    { P1 = DigCode[b];     
      if(b == 2 || b == 4) 
        { 
				P0 = table[date[b]] | 0x80;    
				}   
      else   
         { P0 = table[date[b]];           
				 }    
     delay_ms(10);  
			}
  } 
	for(a = 6; a > 0; a--)  
	{   for(b = 0; b < 6; b++)   
		{ 
       if(location == b)   
				 { 
         P1 = 0xff;    }    
				 else    
					 { 
        P1 = DigCode[b];    
				   }     
       if(b == 2|| b == 4)    
				 {     P0 = table[date[b]] | 0x80; 
         }    
       else   
         {     P0 = table[date[b]];    }    
      delay_ms(10);   
		}  
	}  
 }
 int Key_Scan(void) 
	 { 
       int keyValue = 0xff; 
 
                 int i = 0; 
 
                 if(P2 != 0xff)    
									 {                 delay_ms(1); 
 
                                if(P2 != 0xff)                
																	{ 
                                                 keyValue = P2; 
																		     while(P2 != 0xff);
 
                                                                                                            
//																while((i < 20) && (P2 != 0xff))                         
//																    {                                
//																	    delay_ms(1);                                
//																       i++;                         
//																    }                 
																 } 
                    } 
 
                 return keyValue; 
	 } 
 void Key_Control(int keyValue) 
	 { 
                            switch(keyValue)         
									           { 
                              case(0xfe):  if(location!=0)--location;
															              else{location=5;}
                                            break; 
															
											                                                 
                              case(0xfd):   if(location!=5)++location;
															              else{location=0;}
                                            break;     
									            case(0xfb):	
																if(location==0&&miao<60)miao++;
															  else if (location==1&&miao<60)miao+=10;
																else if (location==2)fen++;
																else if (location==3)fen+=10;
																else if (location==4)shi++;
																else if (location==5)shi+=10;
													 
															 break;
																							
															case(0xf7):	if(location==0&&miao<60)miao--;
															  else if (location==1&&miao<60)miao-=10;
																else if (location==2)fen--;
																else if (location==3)fen-=10;
																else if (location==4)shi--;
																else if (location==5)shi-=10;
													 
															 break;
                             
															 
	                          }   
	 }
	 
	 
 
	 

void time_init()						   
{
    TMOD = 0x01;          
    TH0 = 0x0b;  
   	TL0 = 0xdc;          
    IE = 0x83;          
    TR0 = 1;
}




		 void timer() interrupt 1					

   { 
		 
		    TR0 = 0;          
        
				TH0 = 0x0b;       
				TL0 = 0xdc;              
				TR0 = 1;              
				InterruptCount++;             
				 if(InterruptCount >= 16)        
		 {                
	     InterruptCount = 0;                 
		   
				miao++;
						 if(miao>59)
							{
								 miao=0;
								 fen++;
							 if(fen>59)
								{
									 fen=0;
								 shi++;
								 if(shi>23)
								 {
										shi=0;
								 }
							 }
							}
				 date[0]=miao%10;
				 date[1]=miao/10;
				 date[2]=fen%10;
				 date[3]=fen/10;
				 date[4]=shi%10;
				 date[5]=shi/10;
					
						}
       
		 }
				 
	void INT0_Handler() interrupt 0 
{  Key_Control(Key_Scan()); } 
	     
 
	 							
		
	void delay_ms(int t) 
	{         
		int i, j;         
		for(i = t; i > 0; i--)                 
		for(j = 100; j > 0; j--); 
	}
 