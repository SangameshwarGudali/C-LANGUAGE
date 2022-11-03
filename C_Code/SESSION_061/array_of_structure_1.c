#include <stdio.h> 
#include <stdlib.h> 

struct A
{
    int m; 
    struct B 
    {
        short s1; 
        short s2; 
        int a[4]; 
    }inB; 
    int n; 
}; 

struct A arr[4] = {
    {   
        1000, 
        {
            100, 
            200, 
            {-1, -2, -3, -4}
        },    
        10000
    }, 
    
    {
        2000, 
        {
            300, 
            400, 
            {-5, -6, -7, -8}
        },    
        20000
    }, 

    {
        3000, 
        {   
            500, 
            600, 
            {-9, -10, -11, -12}
        }, 
        30000
    }, 
    
    {
        4000, 
        {
            700, 
            800, 
            {-13, -14, -15, -16}
        }, 
        40000
    }
}; 

int main(void)
{
    int i, j; 

    for(i = 0; i < 4; ++i)
    {
        printf("arr[%d].m == %d\n", i, arr[i].m); 
        printf("arr[%d].inB.s1 == %hd\n", i, arr[i].inB.s1);
        printf("arr[%d].inB.s2 == %hd\n", i, arr[i].inB.s2);
        for(j = 0; j < 4; ++j)
            printf("arr[%d].inB.a[%d] == %d\n", i, j, arr[i].inB.a[j]); 
        printf("arr[%d].n == %d\n", i, arr[i].n); 
        puts("----------------------------------------------------------"); 
    }

    exit(0); 
}