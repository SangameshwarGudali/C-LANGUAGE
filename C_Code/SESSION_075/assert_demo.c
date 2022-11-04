#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

void demo1(void); 
void demo2(void); 

int main(void)
{
    demo1(); 
    demo2(); 
    return (0); 
}

void demo1(void)
{
    int nr; 
    int dr; 

    printf("Enter the value for numerator:"); 
    scanf("%d", &nr); 

    printf("Enter the value for denomenator:"); 
    scanf("%d", &dr); 

    assert(dr != 0); 

    printf("Quotient = %d, Remainder = %d\n", nr / dr, nr % dr); 
}

void demo2(void)
{
    int nr_bytes; 
    int* ptr = 0; 
    printf("Enter number of bytes you want to allocate dynamically:"); 
    scanf("%d", &nr_bytes); 

    ptr = malloc(nr_bytes); 
    assert(ptr != 0); 

    free(ptr); 
    ptr = 0; 
}

