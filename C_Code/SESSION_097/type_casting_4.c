#include <stdio.h> 
#include <stdlib.h> 

/* 
num:    
1       2       3       4       5       6       7       8    
d0      40      c0      30      b0      20      a0      10 
1000    1001    1002    1003    1004    1005    1006    1007

*/ 
unsigned long long int num = 0x10a020b030c040d0; 

int main(void)
{
    unsigned char n1; // B1 
    unsigned short int n2; // B2 B3
    unsigned int n3; //  B4 B5 B6 B7
    unsigned char n4; // B8 


    return (EXIT_SUCCESS); 
}

/* 
1       2       3       4       5       6       7       8    
d0      40      c0      30      b0      20      a0      10 
1000    1001    1002    1003    1004    1005    1006    1007    1008

num == M[1000:1007]
= num;     all 8 bytes will be read 

&num == 1000 

*(&num)
&num == 1000
*(&num) == *1000 
M[1000:1007]

I want to read M[1000]

*(char*)&num == M[1000]

n1 = *(unsigned char*)((char*)&num + 0); 


n2 = M[1001:1002]; 


Goal 1: From variable named num, calculate the 
        address of second byte of num. 

    A == ((char*)&num + 1)
    n2 = *(short*)A; 
    n2 = *(short*)((char*)&num + 1); 

    n3 = *(unsigned int*)((char*)&num + 3); 

    n4 = *(unsigned char*)((char*)&num + 7); 
*/ 

