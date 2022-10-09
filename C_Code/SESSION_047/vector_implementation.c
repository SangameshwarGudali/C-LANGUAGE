#include <stdio.h> 
#include <stdlib.h> 

struct vector{
    int* pa; 
    size_t size; 
}; 

struct vector* create_vector()
{
    struct vector* pvec = (struct vector*)malloc(sizeof(struct vector)); 
    pvec->pa = NULL; 
    pvec->size = 0; 
    return pvec; 
}

void push_back(struct vector* pvec, int new_element)
{
    pvec->size += 1; 
    pvec->pa = (int*)realloc(pvec->pa, pvec->size * sizeof(int)); 
    pvec->pa[pvec->size - 1] = new_element; 
}

void destroy_vector(struct vector* pvec)
{
    if(pvec->pa)
        free(pvec->pa); 
    free(pvec); 
}

void show_vector(struct vector* pvec)
{
    size_t i; 
    for(i = 0; i < pvec->size; ++i)
        printf("pvec->pa[%llu]:%d\n", i, pvec->pa[i]); 
}

int main(void)
{
    int choice;
    int element;  
    struct vector* pvec = create_vector(); 
    while(1)
    {
        printf("Do you want to contnue?[1:Yes, 0:No]:"); 
        scanf("%d", &choice); 
        if(choice != 1)
            break; 
        scanf("%d", &element); 
        push_back(pvec, element); 
    }

    show_vector(pvec); 
    destroy_vector(pvec); 

    return (0); 
}