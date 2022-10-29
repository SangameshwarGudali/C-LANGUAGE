#include <stdio.h> 
#include <stdlib.h> 

int a; 
int b; 
int c; 
int* pa; 
int* pb; 
int* pc; 

int main(void)
{
    printf("Address of (a) = %llu\n", (unsigned long long int)&a); 
    printf("Address of (b) = %llu\n", (unsigned long long int)&b); 
    printf("Address of (c) = %llu\n", (unsigned long long int)&c);
    
    pa = &a; 
    pb = &b; 
    pc = &c; 

    printf("Address of (pa) = %llu\n", (unsigned long long int)&pa); 
    printf("Address of (pb) = %llu\n", (unsigned long long int)&pb); 
    printf("Address of (pc) = %llu\n", (unsigned long long int)&pc); 

    printf("Address in pa = %llu\n", (unsigned long long int)pa); 
    printf("Address in pb = %llu\n", (unsigned long long int)pb); 
    printf("Address in pc = %llu\n", (unsigned long long int)pc); 

    printf("a = %d\n", a); 
    *pa = 500; 
    printf("a = %d\n", a); 

    printf("b = %d\n", b); 
    *pb = 1000; 
    printf("b = %d\n", b); 

    printf("c = %d\n", c); 
    *pc = *pa + *pb; 
    printf("c = %d\n", c); 

    printf("Address in pa = %llu\n", (unsigned long long int)pa); 
    printf("Address in pb = %llu\n", (unsigned long long int)pb); 
    printf("Address in pc = %llu\n", (unsigned long long int)pc); 

    exit(0); 
}