#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

int cpa_add(int, int); 
int cpa_sub(int, int); 
int cpa_mul(int, int); 
int cpa_div(int, int); 

int main(void)
{
    int (*pfn) (int, int); 
    int result; 

    pfn = cpa_add; 
    result = pfn(20, 10); 
    printf("result = %d\n", result); 

    pfn = cpa_sub; 
    result = pfn(20, 10); 
    printf("result = %d\n", result); 

    pfn = cpa_mul; 
    result = pfn(20, 10); 
    printf("result = %d\n", result); 

    pfn = cpa_div; 
    result = pfn(20, 10); 
    printf("result = %d\n", result); 

    return (0); 
}

int cpa_add(int n1, int n2)
{
    return (n1+n2); 
}

int cpa_sub(int n1, int n2)
{
    return (n1-n2); 
}

int cpa_mul(int n1, int n2)
{
    return (n1*n2); 
}

int cpa_div(int n1, int n2)
{
    assert(n2 != 0); 
    return (n1/n2); 
}