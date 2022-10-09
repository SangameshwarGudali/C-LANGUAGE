#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int a[5] = {100, 200, 300, 400, 500};
    int i; 
    int N = 5; 

    for(i = 0; i <= N-1; i = i + 1)
    {
        printf("&a[%d]:%llu\n", i, (unsigned long long int)&a[i]); 
    }

    exit(0); 
}

/* 
1. Take array of 8 characters and print the address of each element in the array 
2. Take array of 8 short integers and print the address of each element int the array. 
3. Take array of 8 long long integers and ....<SAME>......
4. Take array of 8 floating point numbers and ....<SAME>....
5. Take array of 8 doubles and ....<SAME>.....
*/ 