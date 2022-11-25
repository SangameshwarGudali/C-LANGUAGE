#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    // 1010 0000 1011 0000 1100 0000 1101 0000
    unsigned int num = 0xa0b0c0d0; 
    unsigned char x; 

    x = (unsigned char)num; 
    /* 
        rhs type: unsigned int -> 4 byte 
        lhs type: unsigned char -> 1 byte 
        lhs_type != rhs_type; 
    */ 
   printf("x = %hhx", x); 

   return (0); 
}

/* 
    unsigned char u = 1; 
    short s_int; 
    int i; 
    long long int lng_num; 

    lng_num = u; //1 
    lng_num = s_int; //2
    lng_num = i; //4
*/ 

/* 
1
01
001
0001
000001
0000001

000000000000000000000000000000000000000000000000000000000000001

unsigned char c = 1; 

0000 0001 

(unsigned long long)c 
*/ 
