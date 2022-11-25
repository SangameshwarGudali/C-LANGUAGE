#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

/* Dynamically resizable array is called as vector */ 

struct vector_of_integers
{ 
    int* p_arr; 
    long long int number_of_elements; 
}; 

struct vector_of_integers* create_vector_of_integers(void); 
int append_element_to_vector(struct vector_of_integers* p_vector, int element);
void show_vector(struct vector_of_integers* p_vector, const char* msg); 
void destroy_vector(struct vector_of_integers* p_vector); 

int main(void)
{
    /* Test Client */ 
    struct vector_of_integers* p_vec_1 = NULL; 
    struct vector_of_integers* p_vec_2 = NULL; 
    int status; 
    int element; 
    int choice; 

    p_vec_1 = create_vector_of_integers(); 
    p_vec_2 = create_vector_of_integers(); 

    status = append_element_to_vector(p_vec_1, 5); 
    assert(status == 1); 

    status = append_element_to_vector(p_vec_1, 10); 
    assert(status == 1); 

    status = append_element_to_vector(p_vec_1, 15); 
    assert(status == 1); 

    status = append_element_to_vector(p_vec_1, 20); 
    assert(status == 1); 

    while(1)
    {
        printf("Do you further want to enter an element?[1->Yes|Anything Else->No]:"); 
        scanf("%d", &choice); 
        if(choice != 1)
            break; 
        printf("Enter an element:"); 
        scanf("%d", &element); 
        status = append_element_to_vector(p_vec_2, element); 
        assert(status == 1); 
    }

    show_vector(p_vec_1, "Displaying vector 1:"); 
    show_vector(p_vec_2, "Displaying vector 2:"); 

    destroy_vector(p_vec_1); 
    p_vec_1 = NULL; 

    destroy_vector(p_vec_2); 
    p_vec_2 = NULL; 

}

/* algorithms that will allow use of vector of intgers */ 
struct vector_of_integers* create_vector_of_integers(void)
{
    struct vector_of_integers* p_vector = NULL; 

    p_vector = (struct vector_of_integers*)malloc(sizeof(struct vector_of_integers)); 
    assert(p_vector != NULL); 

    p_vector->p_arr = NULL; 
    p_vector->number_of_elements = 0; 

    return (p_vector); 
}

int append_element_to_vector(struct vector_of_integers* p_vector, int element)
{
    p_vector->number_of_elements = p_vector->number_of_elements + 1; 
    p_vector->p_arr = (int*)realloc(p_vector->p_arr, p_vector->number_of_elements * sizeof(int)); 
    assert(p_vector->p_arr != NULL); 
    p_vector->p_arr[p_vector->number_of_elements - 1] = element; 
    return (1); 
}

void show_vector(struct vector_of_integers* p_vector, const char* msg)
{
    long long int i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < p_vector->number_of_elements; ++i)
        printf("p_vector_of_integers[%lld]:%d\n", i, p_vector->p_arr[i]); 
}

void destroy_vector(struct vector_of_integers* p_vector)
{
    if(p_vector->p_arr != NULL)
        free(p_vector->p_arr); 
    free(p_vector); 
    p_vector = NULL; 
}