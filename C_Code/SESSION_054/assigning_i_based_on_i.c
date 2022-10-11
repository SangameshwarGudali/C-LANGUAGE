#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int i = 10; 
    i = i + 1; /* i == 11 */ 
    printf("i = %d\n", i); 

    i = 10; 
    i = i + 5; /* i == 15 */ 
    printf("i = %d\n", i);

    i = 10; 
    i = i - 1;  /* i == 9 */ 
    printf("i = %d\n", i);

    i = 10; 
    i = i - 4; /* i == 6 */ 
    printf("i = %d\n", i);

    i = 10; 
    i = i * 2; /* i == 20 */ 
    printf("i = %d\n", i);

    i = 10; 
    i = i * 5; /* i == 50 */ 
    printf("i = %d\n", i);

    i = 10; 
    i = i / 2;  /* i == 5 */ 
    printf("i = %d\n", i);

    i = 10; 
    i = i / 5;  /* i == 2 */ 
    printf("i = %d\n", i);

    /* Shorthand notation */ 
    i = 10; 
    i += 1; /* i += 1 == i = i + 1 */ 
    printf("i = %d\n", i);

    i = 10; 
    i += 5; /* i += 5 == i = i + 5 */ 
   /* Generalize : i = i + j;  i += j */ 
    printf("i = %d\n", i);

    i = 10; 
    i -= 1; /* i = i - 1; */ 
    printf("i = %d\n", i);

    i = 10; 
    i -= 5; /* i = i - 5; */ 
    printf("i = %d\n", i);

    i = 10; 
    i *= 2;     /* i = i * 2 */ 
    printf("i = %d\n", i);

    i = 10; 
    i *= 5;     /* i = i * 5 */ 
    printf("i = %d\n", i);

    i = 10; 
    i /= 2;     /* i = i / 2 */ 
    printf("i = %d\n", i);

    i = 10; 
    i /= 5;     /* i = i / 5 */ 
    printf("i = %d\n", i);

    exit(0); 
}
    
/* 
    Let BinOP be a binary operator 
    i = i BinOP (RHS)
    i BinOP= RHS; 
*/ 


