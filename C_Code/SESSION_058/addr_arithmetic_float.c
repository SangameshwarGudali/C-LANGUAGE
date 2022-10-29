#include <stdio.h> 
#include <stdio.h> 

int main(void)
{
    float* p = (float*)1000; 
    int i; 
    for(i = 0; i < 5; ++i)
        printf("p + %d = %llu\n", i, (unsigned long long int)(p+i)); 
    exit(0); 
}
 