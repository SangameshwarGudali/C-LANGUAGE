#include <stdio.h> 
#include <stdlib.h> 

struct A
{
    int a; 
    char b; 
    float c; 
}; 

int main(void)
{
    struct A* p = (struct A*)1000; 
    int i; 

    printf("sizeof(struct A):%llu\n", sizeof(struct A)); 
    for(i = 0; i < 5; ++i)
        printf("p + %d = %llu\n", i, (unsigned long long int)(p+i)); 
    exit(0); 
}
/* 
    p + 0 = 1000 + 0 * 12 = 1000
    p + 1 = 1000 + 1 * 12 = 1012 
    p + 2 = 1000 + 2 * 12 = 1024 
    p + 3 = 1000 + 3 * 12 = 1036 
    p + 4 = 1000 + 4 * 12 = 1048

    Let T be a data type. 
    Let p be its pointer. 
    Let x be the address IN pointer. 

    T* p = x; 

    p + k = Address in p + k * sizeof(T)

    address in p = 1000 
    k = 3 
    sizeof(T) = 12 

    1000 + 3 * 12 = 1036  
*/ 

/* 
1000:   [   ][   ][   ][   ]
1004:   [   ][P  ][P  ][P  ]   
1008:   [   ][   ][   ][   ]
*/ 