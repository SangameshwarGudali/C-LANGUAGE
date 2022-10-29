#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    short* p = (short*)1000; 
    int i; 
    for(i = 0; i < 5; ++i)
        printf("p + %d = %llu\n", i, (unsigned long long int)(p+i)); 
    exit(0); 
}

/* 
    short* p = (short*)1000; 

     
    p + 0 = address in p + 0 = 1000 
    WRONG ANSWERS !
    p + 1 = address in p + 1 = 1001
    p + 2 = address in p + 2 = 1002 
    p + 3 = address in p + 3 = 1003
    p + 4 = address in p + 4 = 1004 


    POINTER ARITHEMETIC != MATHEMATICAL ARITHMETIC 
    char* p = 1000; 
    short* ps = 1000; 

*/ 