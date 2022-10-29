#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    char* p1 = (char*)1000; 
    short* p2 = (short*)1000; 
    int* p3 = (int*)1000; 
    double* p4 = (double*)1000; 

    printf("p1 + 1 = %llu\n", (unsigned long long int)(p1 + 1)); /* 1001 */ 
    printf("p2 + 1 = %llu\n", (unsigned long long int)(p2 + 1)); /* 1002 */ 
    printf("p3 + 1 = %llu\n", (unsigned long long int)(p3 + 1)); /* 1004 */ 
    printf("p4 + 1 = %llu\n", (unsigned long long int)(p4 + 1)); /* 1008 */ 

    exit(0); 
}

/* 
    T* p = (T*)1000; 

    p + 1 = 1000 + 1 * sizeof(T)

    p + k = 1000 + k * sizeof(T)

    int* p = 1000; 
    k = 6

    p + 6 = 1000 + 6 * sizeof(int)
            = 1000 + 6 * 4 = 1000 + 24 = 1024 
    
    Let T be data type. 
    Let p be its pointer. 
    And let x be address IN p. 

    T* p = x; 
    p + k = x + k * sizeof(T);

    double* p = 7000; 

    p + 9 ?? 

    T = double
    x = 7000 
    k = 9 

    x + k * sizeof(T)

    7000 + 9 * sizeof(double)
    7000 + 9 * 8 = 7000 + 72 = 7072 

    345345353455 * 45765545456
    =

    x * y 
*/ 

