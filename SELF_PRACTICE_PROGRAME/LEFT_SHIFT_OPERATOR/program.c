#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    unsigned char b = 1; 
    unsigned char c; 
    unsigned int n = 1; 
    unsigned int rs; 
    unsigned int i;
    unsigned short si = 1; 
    unsigned short j; 
    unsigned short rs_s; 

    printf("(at start)b = %hhu\n", b); 
    c = b << 1; 
    printf("(after c = b<<1):b=%hhu\tc=%hhu\n", b, c); 
    c = b << 2; 
    printf("(after c = b<<2):b=%hhu\tc=%hhu\n", b, c); 
    c = b << 3; 
    printf("(after c = b<<3):b=%hhu\tc=%hhu\n", b, c); 
    c = b << 4; 
    printf("(after c = b<<4):b=%hhu\tc=%hhu\n", b, c); 
    c = b << 5; 
    printf("(after c = b<<5):b=%hhu\tc=%hhu\n", b, c); 
    c = b << 6; 
    printf("(after c = b<<6):b=%hhu\tc=%hhu\n", b, c); 
    c = b << 7; 
    printf("(after c = b<<7):b=%hhu\tc=%hhu\n", b, c); 
    c = b << 8; 
    printf("(after c = b<<8):b=%hhu\tc=%hhu\n", b, c); 

    printf("n at start = %u\n", n); 
    for(i = 1; i <= 64; ++i)
    {
        rs = (n << i); 
        printf("(unsigned int):%u << %u = %u\n", n, i, rs); 
    }
        
    printf("si at start = %hu\n", si); 
    for(j = 1; j <= 32; ++j)
    {
        rs_s = (si << j); 
        printf("(unsigned short):%hu << %hu = %hu\n", si, j, rs_s); 
    }   
    
    b = 1; 
    for(i = 1; i <= 32; ++i)
    {
        c = (b << i); 
        printf("(unsigned char):%hhu << %d = %hhu\n", b, i, c); 
    }
    exit(0); 
}