#include <stdio.h> 
#include <stdlib.h> 

#define OFFSET_OF(TypeName, MemberName) ((unsigned long long int)(&(((TypeName*)0)->MemberName)))
#define CONTAINER_OF(Address, TypeName, MemberName) ((TypeName*)((unsigned long long)Address - OFFSET_OF(TypeName, MemberName)))

struct A 
{
    int a; 
    char b; 
    float c; 
}; 

void show(float* pf); 
void show_1(float* pf); 

int main(void)
{
    struct A inA1 = {10, 'a', 1.1}; 
    struct A inA2 = {20, 'b', 2.2}; 
    struct A inA3 = {30, 'c', 3.3}; 

    show(&inA1.c); 
    show(&inA2.c); 
    show(&inA3.c); 

    puts("Using show_1()"); 
    show_1(&inA1.c); 
    show_1(&inA2.c); 
    show_1(&inA3.c); 

    return (0); 
}

void show(float* pf)
{
    // We must subtract offset of member c 
    // in struct A from pf. And we must type-cast 
    // pf into unsigned long long int to suppress 
    // pointer arithmetic 

    struct A* pA = (struct A*)((unsigned long long int)pf - 
                    (unsigned long long int)(&((struct A*)0)->c)); 

    printf("pA->a=%d, pA->b=%c, pA->c=%.2f\n", 
            pA->a, pA->b, pA->c); 
}

void show_1(float* pf)
{
    struct A* pA = CONTAINER_OF(pf, struct A, c); 
    printf("pA->a=%d, pA->b=%c, pA->c=%.2f\n", 
            pA->a, pA->b, pA->c);    
}