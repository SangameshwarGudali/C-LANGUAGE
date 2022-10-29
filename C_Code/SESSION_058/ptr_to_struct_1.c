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
    struct A inA; /* int n; */ 
    struct A* pA; /* int* p; */ 

    pA = &inA;  /* p = &n; */ 

    pA->a = 100; 
    pA->b = 'A'; 
    pA->c = 3.14f; 

    printf("pA->a=%d pA->b=%c pA->c=%f\n", pA->a, pA->b, pA->c); 

    pA->a = 1000; 
    pA->b = 'Z'; 
    pA->c = 31.4f; 

    printf("pA->a=%d pA->b=%c pA->c=%f\n", pA->a, pA->b, pA->c); 

    exit(0); 
}