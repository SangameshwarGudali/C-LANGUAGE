#include <stdio.h> 
#include <stdlib.h> 

int n = 0;
int *p;     /* p is pointer to int */ 

char z = 'A'; 
char* pc;   /* pc is a pointer to char */ 

unsigned short us = 2578; 
unsigned short* p_short; 

/* 
    T var_name; 
    T *p; 
*/ 

int main(void)
{
     
    printf("&n = %llu\n", (unsigned long long)&n); 
    p = &n; 
    
    printf("BEFORE executing (*p = 150) | Address IN p = %llu\n", (unsigned long long)p); 
    printf("BEFORE executing (*p = 150) | n = %d\n", n);
    *p = 150; 
    printf("AFTER executing (*p = 150) | n = %d\n", n);
    printf("AFTER executing (*p = 150) | Address IN p = %llu\n", (unsigned long long)p); 
    exit(0); 
}

/* 

*p = p chya atly address war

lhs = *p; 

p chya atlya address war read operation kara 
PERFORM READ OPERATION ON ADDRESS IN P 

*p = rhs; 
p chya atlya address war write operation kara 
PERFORM WRITE OPERATION ON ADDRESS IN p. 

THIS DOES NOT CHANGE THE CONTENT INSIDE p. 

p WILL CONTINUE TO HOLD THE ADDRESS ASSIGNED TO IT 
*/ 
