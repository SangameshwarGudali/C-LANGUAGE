#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int n = 100; 
    const int* const p = &n; 
}

/* 
    int* p; 
    p is a R/W pointer to R/W integer 

    const int* p; 
    p is a R/W pointer to RO integer (RO integer = const integer)

    int *const p = initialization expr;
    p is a RO pointer  to R/W integer (RO pointer = const pointer)

    const int* const p = initialization expr; 
    p is a RO pointer  to RO integer (RO pointer = const pointer, RO integer = const integer) 
*/ 