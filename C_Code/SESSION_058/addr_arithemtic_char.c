#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    char* p = (char*)1000; 
    
    int i; 
    
    for(i = 0; i < 5; ++i)
        printf("p + %d = %llu\n", i, (unsigned long long int)(p+i)); 
    
    exit(0); 
}

/* 
    char* p = (char*)1000; 

    p + 0   Address in p + 0  = 1000 
    p + 1   Address in p + 1  = 1001 
    p + 2   Address in p + 2  = 1002 
    p + 3   Address in p + 3  = 1003 
    p + 4   Address in p + 4  = 1004 
*/ 








/* 
1000 is DUMMY OR INVALID ADDRESS 

int n; 
&n; 

float f; 
&f; 

1000 
2000
0
3500

REAL MODE : 8086 : TURBO 
SEGMENTED MEMORY 

FLAT MEMORY MODEL 
*/ 