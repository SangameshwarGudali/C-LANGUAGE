#include <stdio.h> 
#include <stdlib.h> 

struct B
{
    int a[4]; 
    double d[2]; 
    float f[4]; 
}; 

int main(void)
{
    struct B inB; 
    struct B* pB; 
    int i; 

    pB = &inB; 

    /* write in array a inside inB */ 
    for(i = 0; i < 4; ++i)
        pB->a[i] = (i+1) * 100; 
    
    
    exit(0); 
}