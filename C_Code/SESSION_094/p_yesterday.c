#include <stdio.h>
#include <stdlib.h> 

int my_add(int a, int b); 
int my_sub(int a, int b); 
int my_mul(int a, int b); 
int my_quo(int a, int b); 
int my_rem(int a, int b); 

void test_1(void); 
void test_2(void); 
void test_3(void); 

int main(void)
{
    int n1 = 17, n2 = 4; 
    int i, ret; 

    int     (*   (*p)    [5])   (int, int); 
    p = test_4(); 

    for(i = 0; i < 5; ++i)
    {
        ret = (*p)[i](n1, n2); 
    }

    return (0); 
}

int (*   (  * test_4(void)    )   [5])(int, int)
{
    static int (*arr[5])(int, int); 

    arr[0] = my_add; 
    arr[1] = my_sub; 
    arr[2] = my_mul; 
    arr[3] = my_quo; 
    arr[4] = my_rem; 

    return &arr; 
}

void test_3(void)
{
    int n1 = 17, n2 = 4; 
    int i; 
    int ret; 
    int arr1[5]; 
    int (*p1)[5]; 
    
    int*    arr2    [5]; 
    int* (*p2)      [5]; 

    int (*      arr3    [5])(int, int); 
    int (*      (*p3)   [5])(int, int); 

    p1 = &arr1; 
    p2 = &arr2; 
    
    arr3[0] = my_add; 
    arr3[1] = my_sub; 
    arr3[2] = my_mul; 
    arr3[3] = my_quo; 
    arr3[4] = my_rem; 
     
    p3 = &arr3; 

    for(i = 0; i < 5; ++i)
    {
        ret = arr3[i](n1, n2); 
        ret = (*p3)[i](n1, n2); 
    }
}

void test_2(void)
{
    // declare an array 5 of pointers to function 
    // accepting two integers and returning an integer 
    int (*arr[5])(int, int); 
    int i; 
    int ret; 
    int n1 = 17, n2 = 4; 
    arr[0] = my_add; 
    arr[1] = my_sub; 
    arr[2] = my_mul; 
    arr[3] = my_quo; 
    arr[4] = my_rem; 

    for(i = 0; i < 5; ++i)
        ret = arr[i](n1, n2); 
}


void test_1(void)
{
    int (*pfn)(int, int); 
    int ret; 
    int n1 = 17, n2 = 4; 

    pfn = my_add; 
    ret = pfn(n1, n2); 

    pfn = my_sub; 
    ret = pfn(n1, n2); 

    pfn = my_mul; 
    ret = pfn(n1, n2); 

    pfn = my_quo; 
    ret = pfn(n1, n2); 

    pfn = my_rem; 
    ret = pfn(n1, n2); 
}

int my_add(int a, int b)
{
    return (a+b); 
}

int my_sub(int a, int b)
{
    return (a-b); 
}

int my_mul(int a, int b)
{
    return (a*b); 
}

int my_quo(int a, int b)
{
    return (a/b); 
}

int my_rem(int a, int b)
{
    return (a%b); 
}