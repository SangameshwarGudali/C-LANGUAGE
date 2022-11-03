#include <stdio.h> 
#include <stdlib.h> 

void swap(int* pa, int *pb); 

int main(void)
{
    int m = 100; 
    int n = 200; 

    printf("main:addr(m)=%llu, addr(n)=%llu\n", (unsigned long long int)&m, 
                                                (unsigned long long int)&n); 

    printf("Before swap:m=%d, n=%d\n", m, n); 
    swap(&m, &n); 
    printf("After swap:m=%d, n=%d\n", m, n); 

    return (0); 
}

void swap(int* pa, int* pb)
{
    int tmp; 
    printf("In swap\n"); 
    printf("Address OF pa = %llu\n", (unsigned long long int)&pa); 
    printf("Address OF pb = %llu\n", (unsigned long long int)&pb); 
    printf("Address IN pa = %llu\n", (unsigned long long int)pa); 
    printf("Address IN pb = %llu\n", (unsigned long long int)pb); 
    tmp = *pa; 
    *pa = *pb; 
    *pb = tmp; 
}