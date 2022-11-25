#include <stdio.h> 
#include <stdlib.h> 

/* 
    Declare a function accepting pointer to arr 
    5 of integers. The function should set array 
    elements (by accessing array through pointer)
    to (index + 1) * 100 
*/ 
void set_array(int(*p_arr)[5]); 

/* 
    Declare a function accepting pointer to arr 
    5 of integers. The function should print all 
    elements in the array (by accessing array 
    through pointer). 
*/ 
void show_array(int(*)[5]); 

int main(void)
{
    int a[5] = {0, 0, 0, 0, 0}; 

    puts("Before set_array:"); 
    show_array(&a); 
    set_array(&a); 
    puts("After set_array:"); 
    show_array(&a); 
    
    return (0); 
}

void set_array(int(*p_arr)[5])
{
    int i; 
    for(i = 0; i < 5; ++i)
        (*p_arr)[i] = (i+1) * 100; 
}

void show_array(int(*p_arr)[5])
{
    int i; 
    for(i = 0; i < 5; ++i)
        printf("(*p_arr)[%d]:%d\n", i, (*p_arr)[i]); 
} 