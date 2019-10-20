#include<reg52.h> 
void delay(unsigned int cnt) 
{
    while(--cnt);
}

int main()
{
    bit flag = 0;                  

    P0=0x7f;                       
    while(1)                    
    {  
        if (flag == 0)           
        {
            delay(30000);       
            P0 = P0 >> 1;          
            P0 |= 0x80;            
    
            if(P0==0xfe)        
            { 
                flag = 1;       
            }
        
        }
        else
        {
            delay(30000);       
            P0 = P0 << 1;          
            P0 |= 0x01;           
    
            if(P0==0x7f)        
            { 
                flag = 0;
            }
        }
    }
}