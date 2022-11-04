#include <stdio.h> 
#include <stdlib.h> 

/* 
    S1: Define information structure A with following members. 
        n of the type int. 
        s of the type short. 
        m of the type long.
    
    S2: Allocate structure instance dynamically using malloc. 

    S3: Write 100 on n, 200 on s and 300 on m. 

    S4: Display n, s, and m members of dynamically allocated 
        instance of struct A. 

    S5: Free dynamically allocated instance of struct A. 
*/ 

struct A
{
    int n; 
    short s; 
    long int m; 
}; 

int main(void)
{
    struct A* pA = 0; 

    pA = malloc(sizeof(struct A)); 
    if(pA == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    pA->n = 100; 
    pA->s = 200; 
    pA->m = 300; 

    printf("pA->n=%d, pA->s=%hd, pA->m=%ld", pA->n, pA->s, pA->m);

    free(pA); 
    pA = 0; 

    exit(0); 
}