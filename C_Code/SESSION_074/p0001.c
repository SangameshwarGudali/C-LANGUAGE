/* 
Goal:   To demonstrate that the lifetime of 
        a memory block allocated dynamically 
        using dynamic memory allocation functions 
        such as malloc() is completely controlled 
        by programmer. 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

void f1(int* p); 
void f2(int* p); 
void f3(int* p); 

int main(void)
{
    int* p = 0; 

    p = malloc(sizeof(int)); 
    if(p == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    *p = 100; 
    printf("main:before f1():p = %llu, *p = %d\n", 
            (unsigned long long int)p, 
            *p); 
    f1(p); 
    printf("main:after f1():p = %llu, *p = %d\n", 
            (unsigned long long int)p, 
            *p); 
    f2(p); 
    printf("main:after f2():p = %llu, *p = %d\n", 
            (unsigned long long int)p, 
            *p);
    f3(p); 
    printf("main:after f3():p = %llu, *p = %d\n", 
            (unsigned long long int)p, 
            *p);
    free(p); 
    p = 0; 
    exit(0); 
}

void f1(int* p)
{
    printf("f1:p = %llu, *p = %d\n", (unsigned long long int)p, *p); 
    *p = 200; 
}

void f2(int* p)
{
    printf("f2:p = %llu, *p = %d\n", (unsigned long long int)p, *p); 
    *p = 300; 
}

void f3(int* p)
{
    printf("f3:p = %llu, *p = %d\n", (unsigned long long int)p, *p); 
    *p = 400; 
}
