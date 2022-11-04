#include <stdio.h> 
#include <stdlib.h> 

struct Test
{
    int num; 
    char c; 
    float f_num; 
}; 

/*  
    The function show accepts an address of 
    instance of struct Test as actual parameter 
    and catches the address in pointer to struct Test 
    in formal parameter. 

    Role of the function is to show the contents of 
    the input struct Test instance 
*/ 
void show(struct Test* p_instanceof_struct_test); 

int main(void)
{
    struct Test inT;    /* allocate an instance of struct Test */ 
    
    inT.num = 1000; 
    inT.c = 'Z'; 
    inT.f_num = 100.43; 
    show(&inT); 
    
    return (0); 
}

void show(struct Test* p_instanceof_struct_test)
{
    printf("member (num) = %d\n", p_instanceof_struct_test->num); 
    printf("member (c) = %c\n", p_instanceof_struct_test->c); 
    printf("member (f_num) = %f\n", p_instanceof_struct_test->f_num); 
}