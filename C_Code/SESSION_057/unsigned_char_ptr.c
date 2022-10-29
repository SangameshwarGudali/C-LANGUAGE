#include <stdio.h> 
#include <stdlib.h> 

unsigned char c; 
unsigned char c_copy; 
unsigned char* p; 

int main(void)
{
    /* printf() addr of c, addr of c_copy addr of p */ 
    p = &c; 
    /* printf() addr in p */ 
    *p = 210; 
    printf("c = %hhu\n", c);
    c_copy = *p; 
    printf("c_copy = %hhu\n", c_copy); 
    /* printf() addr of p */ 
    exit(0); 
}