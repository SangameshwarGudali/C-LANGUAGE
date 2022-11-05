#include <stdio.h> 
#include <stdlib.h> 

void input(int* p_arr, int size); 
void output(int* p_arr, int size); 

int main(void)
{
    int arr[5] = {0, 0, 0, 0, 0}; 
    int i; 

    puts("Showing array before sending it to input function"); 
    output(&arr[0], 5); 
    input(&arr[0], 5); 
    puts("Showing array after sending it to input function"); 
    output(&arr[0], 5); 

    return (0); 
}

void input(int* p_arr, int size)
{
    int i; 

    for(i = 0; i < size; ++i)
        *(p_arr + i) = (i+1) * 100; 
}

void output(int* p_arr, int size)
{
    int i; 
    for(i = 0; i < size; ++i)
        printf("*(p_arr + %d):%d\n", i, *(p_arr + i)); 
}