#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

struct A
{
    int a; 
    char b; 
    float c; 
}; 

/* 
    inA -> struct A
    &inA -> struct A* 

    inA.a -> int 
    &inA.a -> int* 

    inA.b -> char 
    &inA.b -> char* 

    inA.c -> float 
    &inA.c -> float* 
*/ 
int main(void)
{
    unsigned long long int off_a, off_b, off_c; 
    struct A inA = {0, '\0', 0.0}; 
    struct A* pA = 0; 

    puts("Using instance of structure"); 
    off_a = (unsigned long long int)&inA.a - (unsigned long long int)&inA; 
    off_b = (unsigned long long int)&inA.b - (unsigned long long int)&inA; 
    off_c = (unsigned long long int)&inA.c - (unsigned long long int)&inA; 

    printf("off_a=%llu, off_b=%llu, off_c=%llu\n", off_a, off_b, off_c); 
    
    off_a = 0; 
    off_b = 0; 
    off_c = 0; 

    puts("Using struct A* pA = 0;"); 
    off_a = (unsigned long long int)(&pA->a); 
    off_b = (unsigned long long int)(&pA->b); 
    off_c = (unsigned long long int)(&pA->c); 
    printf("off_a=%llu, off_b=%llu, off_c=%llu\n", off_a, off_b, off_c);

    off_a = 0; 
    off_b = 0; 
    off_c = 0; 

    puts("Offset of technique without macro"); 
    off_a = (unsigned long long int)(&(((struct A*)0)->a)); 
    off_b = (unsigned long long int)(&(((struct A*)0)->b)); 
    off_c = (unsigned long long int)(&(((struct A*)0)->c)); 
    printf("off_a=%llu, off_b=%llu, off_c=%llu\n", off_a, off_b, off_c);

    #define OFFSET_OF(Type, mem) ((unsigned long long int)(&(((Type*)0)->mem)))
    off_a = 0; 
    off_b = 0; 
    off_c = 0; 

    puts("By Offset of macro"); 
    off_a = OFFSET_OF(struct A, a); 
    off_b = OFFSET_OF(struct A, b); 
    off_c = OFFSET_OF(struct A, c); 
    printf("off_a=%llu, off_b=%llu, off_c=%llu\n", off_a, off_b, off_c);



    exit(0); 
}