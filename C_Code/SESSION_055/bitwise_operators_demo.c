#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int n1 = 100; 
    int n2 = 57; 
    int rs; 

    puts("Bitwise NOT:"); 
    rs = ~n1; 
    printf("n1 = %d, ~n1 = %d\n", n1, rs); 
    rs = ~n2; 
    printf("n2 = %d, ~n2 = %d\n", n2, rs); 

    puts("Bitwise AND:"); 
    rs = n1 & n2; 
    printf("n1 = %d, n2 = %d, n1 & n2 = %d\n", n1, n2, rs); 

    puts("Bitwise OR:"); 
    rs = n1 | n2; 
    printf("n1 = %d, n2 = %d, n1 | n2 = %d\n", n1, n2, rs); 

    puts("Bitwise XOR:"); 
    rs = n1 ^ n2; 
    printf("n1 = %d, n2 = %d, n1 ^ n2 = %d\n", n1, n2, rs); 

    exit(0); 
}

/* 
1:  Convert n1 into its binary represnetaiton. 
2.  Convert n2 into its binary representation. 
3.  Take bitwise not of n1 
    and convert the answer into decimal 
4.  Take bitwise not of n2 
    and convert the answer into decimal 
5.  Take bitwise AND of n1 and n2 
    and convert the answer into decimal 
6.  Take bitwise OR of n1 and n2 
    and conver the answer into decimal 
7.  Take bitwise XOR of n1 and n2 
    and convert the answer into decimal 
8.  Verify your calculations by running program 
*/ 