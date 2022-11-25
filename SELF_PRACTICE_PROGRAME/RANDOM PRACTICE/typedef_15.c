#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned long long int num = 0x3B9ACA0B;
    int i;
    
    for(i=0; i<sizeof(unsigned long long int); ++i)
        printf("Addresses = %hx\n", *((unsigned short*)((char*)&num) + i));
    
    return(0);
}