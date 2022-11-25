#include <stdio.h> 
#include <stdlib.h> 

struct A 
{
    int a; 
    char b; 
    float c; 
}; 

struct A inA; 
struct A* pA = &inA; 
struct A* pA1;  

int main(void)
{

    printf("&inA = %llu\n", (unsigned long long int)&inA); 
    printf("&inA.a = %llu\n", (unsigned long long int)&inA.a); 
    printf("&inA.b = %llu\n", (unsigned long long int)&inA.b); 
    printf("&inA.c = %llu\n", (unsigned long long int)&inA.c); 
    printf("&pA->a = %llu\n", (unsigned long long int)&pA->a); 
    printf("&pA->b = %llu\n", (unsigned long long int)&pA->b); 
    printf("&pA->c = %llu\n", (unsigned long long int)&pA->c); 
    printf("&pA1->a = %llu\n", (unsigned long long int)&pA1->a); 
    printf("&pA1->b = %llu\n", (unsigned long long int)&pA1->b); 
    printf("&pA1->c = %llu\n", (unsigned long long int)&pA1->c);

    printf("offset(struct A, a) = %llu\n", (unsigned long long int)(&((struct A*)0)->a)); 
    printf("offset(struct A, b) = %llu\n", (unsigned long long int)(&((struct A*)0)->b)); 
    printf("offset(struct A, c) = %llu\n", (unsigned long long int)(&((struct A*)0)->c)); 


    return (0); 
}

/* 
pA->c 

(*pA).c 

struct A
{
    int a; 
    char b; 
    float c; 
}; 

int main()
{
    struct A inA; 

    = inA; 
}
float f; // M [2000:2003]
f = pA->c; (*pA).c

&pA->c

S1: Fetch the address from pA (1000)
S2: Add offset of c in struct A to address in pA 
    offset of c in struct A == 8 
    1000 + 8 = 1008 
S3: 1008 is a target source address 

S4: Examine the type of 'c' 
    float 
    sizeof(float) == 4 
    read 4 bytes from 1008

    M[2000:2003] <- M[1008:1011]

-------------------------------------------------------
struct A* pA = 0;
&pA->c == 
*/ 

/* 
struct A inA; 

inA.c 

struct A* pA; 

pA -> pointer to struct A 
*pA -> struct A

&(*pA).a

&pA->a
*/ 

/*  CPA PRINCIPLE 2: 
        BASIC IS ADVANCED. 
        ADVANCED IS BASIC. 

        If you treat basic as advanced then 
        you will have ability to treat advanced as basic. 

        - Yogeshwar Shukla. 
*/ 

/* 

(*pA)[i];   // BAROBAR AHE 
    
    int (*p)[5]; // BAROBAR AHE 

    p = &arr;   // BAROBAR AHE 

    (*p)[i];    // BAROBAR AHE 

    (p)[i];     // CHUK AHE 

    (pA).a      // CHUK AHE 

*/ 