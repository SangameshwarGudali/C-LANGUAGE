#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int* ptr1 = 0; 
    int* ptr2 = 0; 
    int nr_of_elements = 20; 
    int i; 

    ptr1 = malloc(nr_of_elements * sizeof(int)); 
    for(i = 0; i < nr_of_elements; ++i)
        printf("*(ptr1 + %d):%d\n", i, *(ptr1 + i)); 
    free(ptr1); 
    ptr1 = 0; 

    ptr2 = calloc(nr_of_elements, sizeof(int)); 
    for(i = 0; i < nr_of_elements; ++i)
        printf("*(ptr2 + %d) = %d\n", i, *(ptr2 + i)); 
    free(ptr1); 
    ptr1 = 0; 

    exit(0); 
}
