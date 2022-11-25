#include <stdio.h> 
#include <stdlib.h> 

unsigned long long int n; 

int main(void)
{
    printf("1:n = %llx\n", n); 
    *(char*)&n = 0xff; 
    printf("2:n = %llx\n", n);
    *(short*)((char*)&n + 1) = 0xffff; 
    printf("3:n = %llx\n", n);
    *(int*)((char*)&n + 3) = 0xffffffff; 
    printf("4:n = %llx\n", n);
    *(char*)((char*)&n + 7) = 0xff; 
    printf("5:n = %llx\n", n);
    return (0); 
}