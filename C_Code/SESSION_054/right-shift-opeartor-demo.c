#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    unsigned char b = 128; 
    int i; 
    unsigned char c; 

    printf("(start):b = %hhu\n", b); 
    c = (b >> 1); 
    i = 1; 
    printf("(unsigned char):%hhu >> %d = %hhu\n", b, i, c); 
    c = (b >> 2);
    i = 2;  
    printf("(unsigned char):%hhu >> %d = %hhu\n", b, i, c); 
    c = (b >> 3); 
    i = 3; 
    printf("(unsigned char):%hhu >> %d = %hhu\n", b, i, c); 
    c = (b >> 4); 
    i = 4; 
    printf("(unsigned char):%hhu >> %d = %hhu\n", b, i, c); 
    c = (b >> 5); 
    i = 5; 
    printf("(unsigned char):%hhu >> %d = %hhu\n", b, i, c); 
    c = (b >> 6); 
    i = 6; 
    printf("(unsigned char):%hhu >> %d = %hhu\n", b, i, c); 
    c = (b >> 7); 
    i = 7; 
    printf("(unsigned char):%hhu >> %d = %hhu\n", b, i, c); 
    c = (b >> 8); 
    i = 8; 
    printf("(unsigned char):%hhu >> %d = %hhu\n", b, i, c); 
    exit(0); 
}