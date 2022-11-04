#include <stdio.h> 
#include <stdlib.h> 

int calculate_sum(  int (*p)[10], 
                    int n 
                ); 


int main(void)
{
    int arr[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000}; 
    int S; 
    puts("summation of array - experienced"); 
    S = calculate_sum(&arr, 10);  
    printf("S = %d\n", S); 
    return (0); 
}

int calculate_sum(  int (*p)[10], 
                    int n 
                )
{
    int i; 
    int sum; 

    sum = 0; 
    for(i = 0; i < n; ++i)
        sum = sum + (*p)[i]; 

    return (sum); 
}

/* 
    int a[5]; 

    1000:   [   ][  ][  ][  ][  ]

    &a[0]   == 1000 
    &a      == 1000

    int     a  [5]; 

    typeof(a)       == int     [5]
    typeof(a[0])    == int 
    typeof(&a[0])   == int* 

    typeof(&a) == int (*p)[5]

    int *p  [5]

    int* p[5]; /* p is an array 5 of pointer to int 

    
[   ]

    int (*(*p)[10])(int, int); 

    void* malloc()

    struct X
    {
        int a; 
        char b; 
        float c; 
    }inX; 

    [       ]c
        [   ]b
    [       ]a       inX    (25000)


    &inX;           25000
    &inX.a          25000

    struct X* pX = &inX

    int* p = &inX.a; 

*/ 