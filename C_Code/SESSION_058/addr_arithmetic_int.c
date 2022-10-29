#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int* p = (int*)1000; 
    int i; 
    for(i = 0; i < 5; ++i)
        printf("p + %d = %llu\n", i, (unsigned long long int)(p+i)); 
    exit(0); 
}
 