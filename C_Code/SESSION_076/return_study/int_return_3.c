#include <stdio.h> 
#include <stdlib.h> 

void create_int_1(int** pp, int init_n); 
void create_int_2(int** pp, int init_n); 

int main(void)
{
    int* ptr1 = 0; 
    int* ptr2 = 0; 

    create_int_1(&ptr1, 100); 
    create_int_2(&ptr2, 200); 

    printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2); 

    free(ptr1); 
    ptr1 = 0; 

    free(ptr2); 
    ptr2 = 0; 

    exit(0); 
}

void create_int_1(int** pp, int init_n)
{
    *pp = malloc(sizeof(int)); 
    if(*pp = 0) 
    {
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    **pp = init_n; 
}

void create_int_2(int** pp, int init_n)
{
    int* p = 0; 

    p = malloc(sizeof(int)); 
    if(p == 0)
    {
        puts("Error in allocating memory"); 
        exit(-1); 
    }

    *p = init_n; 
    *pp = p; 
}
