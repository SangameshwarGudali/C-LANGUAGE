#include <stdio.h> 
#include <stdlib.h> 

/* Type Declaration of a function */ 
int max3(int, int, int); 

int main(void)
{
    int max_val; 
    int p=100; 
    int q=200; 
    int r=300; 
/*------------------*/ 
    int x=200; 
    int y=500; 
    int z=90; 
/*------------------*/ 
    int m=1000; 
    int n=791; 
    int u=1589; 
/*------------------*/ 
    max_val = max3(p, q, r); 
    printf("maxof(%d, %d, %d) = %d\n", p, q, r, max_val); 

    max_val = max3(x, y, z); 
    printf("maxof(%d, %d, %d) = %d\n", x, y, z, max_val); 

    max_val = max3(m, n, u); 
    printf("maxof(%d, %d, %d) = %d\n", m, n, u, max_val);  

    max_val = max3(3000, 2000, 5000); 
    printf("maxof(%d, %d, %d) = %d\n", 3000, 2000, 5000, max_val); 

    exit(0);  
}

/* definition of algorithm */ 
/* function definition */ 
int max3(int num1, int num2, int num3)  /* header of func def */ 
/* body of func def */ 
{
    int max_integer; 

    if(num1 > num2)
        max_integer = num1; 
    else 
        max_integer = num2; 

    if(num3 > max_integer)
        max_integer = num3; 

    return (max_integer); 
}

/* 
    int max3(int num1, int num2, int num3) 
    int     ->  Return Value Type 
    max3    ->  Name of function 
    formal  
*/  

