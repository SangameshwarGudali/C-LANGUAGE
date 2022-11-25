#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    int n = 0x0a0b0c0d; 
    
    if(*(char*)&n == 0xd) 
        puts("Little Endian Machine"); 
    else if(*(char*)&n == 0xa)
        puts("Big Endian Machine"); 

    return 0; 
}