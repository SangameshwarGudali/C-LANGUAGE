#include <stdio.h> 
#include <stdlib.h> 
// int printf(char*, ...); 
void exit(int); 

int main(void) 
{
    printf("sizeof(short) = %zu\n", sizeof(short)); 
    printf("sizeof(int) = %zu\n", sizeof(int)); 
    printf("sizeof(long) = %zu\n", sizeof(long)); 
    printf("sizeof(long long) = %zu\n", sizeof(long long)); 
    exit(0); 
}