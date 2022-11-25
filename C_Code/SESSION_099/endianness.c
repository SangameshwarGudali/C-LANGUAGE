#include <stdio.h> 
#include <stdlib.h> 

/* 
    Matters computational: 
    previously known as algorithm for programmers 
*/ 

int main(void)
{
    int num = 0xa0b0c0d0; 

    if(*(unsigned char*)&num == 0xd0)
        puts("Little Endian"); 
    else if(*(unsigned char*)&num == 0xa0)
        puts("Big Endian"); 
    else 
        puts("strange machine"); 

    return (0); 
}
