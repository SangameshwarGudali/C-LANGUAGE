#include <stdio.h> 
#include <stdlib.h> 

void set_array(int* p_arr, int size); 
void show_array(int* p_arr, int size); 

int main(void)
{
    int a[5] = {0, 0, 0, 0, 0}; 

    puts("Before set array:"); 
    show_array(a, 5); 
    set_array(a, 5); 
    puts("After set array"); 
    show_array(a, 5); 

    return (0); 
}

void set_array(int* p_arr, int size)
{
    int i; 
    for(i = 0; i < size; ++i)
        *(p_arr + i) = (i+1)*100; 
}

void show_array(int* p_arr, int size)
{
    int curr_element; 
    int i; 

    for(i = 0; i < size; ++i)
    {
        curr_element = p_arr[i]; 
        printf("p_arr[%d]:%d\n", i, p_arr[i]); 
    }
}

