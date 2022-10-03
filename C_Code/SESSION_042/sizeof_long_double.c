#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    printf("sizeof(double):%zu\n", sizeof(double)); 
    printf("sizeof(long double):%zu\n", sizeof(long double)); 
    exit(0); 
}

/* 
    on MSVC, x86, MSVC, x64 : long double not implemented : 8 bytes 
    on GCC, x86 : sizeof(long double): 12 byte 
    on GCC, x64 : sizeof(long double): 16 byte 

    P2 : MMX : 64 
    P3 : SSE : 128 
         AVX : 256 : 128 bit : 2 float
         AVX 512 : 128 bit : 4 float 
    GPU 
    INTEL : GPU : Intel HD 5000 

    SIMD -> 
    SOFTWARE SIMULATE.  
*/ 