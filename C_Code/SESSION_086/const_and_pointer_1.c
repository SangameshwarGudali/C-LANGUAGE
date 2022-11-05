/*  
    Const and pointer -> 
    Case 1: Pointer to const 
*/ 
#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int n = 10; 
    int* p = NULL; 

    p = &n;     // p-> pointer, n-> pointee 

    // Through pointer one can read as well as write on pointee. 

    const int* ptr;
    ptr = &n; 



    exit(0); 
}

void test(void)
{

}


/* 
1)  
    Employer 
    Employee 

2)  
    Caller 
    Callee 

3) 
    Mentor 
    Mentee 

4) 
    Pointer 
    Pointee 

    T* p;   // 8 byte 
    T instance;     // sizeof(T)
    malloc(sizeof(T)); 
*/ 

void test(void)
{
    int* p; 

    type(p) -> int*
    type(*p) -> int 

    *p = 100; 
    int m = *p; 

    const int *p;

    p -> const int* 
    *p -> const int 

    const int *p; 

    int* p; 

    int* p; 
    int *p; 

    *p -> int 
    *p = 100; 
    int m = *p; 

    const int* p; 

    *p -> const int 


    const int m = 100; 
    m = 200; 

    const int* p; 




}

void test()
{
    int n1 = 100; 
    const int n2 = 200; 
    const int* p; 
    
    p = &n2; 
    /* n2 -> const int 
        &n2 -> const int* 
        p -> const int* 
        p = &n2; 
        *p = 1000; 
    */ 

    p = &n1; 
    /* 
        n1 -> int 
        &n1 -> int* 
        p -> const int* 

        LHS(const int*) = RHS(int*); 
        *p = 5000; NOT VALID 
    */ 
   n1 = 500; 
   p = &n1; 
   *p = 500; 
}

