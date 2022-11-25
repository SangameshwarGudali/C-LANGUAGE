#include <stdio.h>
#include <stdlib.h> 

int my_add(int a, int b); 
int my_sub(int a, int b); 
int my_mul(int a, int b); 
int my_quo(int a, int b); 
int my_rem(int a, int b); 


int (*   (*   test_4(void)   )  [5])(int, int)
{
    static int (*arr[5])(int, int); 

    arr[0] = my_add; 
    arr[1] = my_sub; 
    arr[2] = my_mul; 
    arr[3] = my_quo; 
    arr[4] = my_rem; 

    return &arr; 
}

int main()
{
    int n1 = 17, n2 = 4; 
    int i; 
    int ret; 
    int (   *   (*    (*pfn)  (void))   [5])(int, int); 
    int (*(*p_arr)[5])(int, int); 
    pfn = test_4; 
    p_arr = pfn(); 
    for(i = 0; i < 5; ++i)
    {
        ret = (*p_arr)[i](n1, n2); 
    }

    return (0); 
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