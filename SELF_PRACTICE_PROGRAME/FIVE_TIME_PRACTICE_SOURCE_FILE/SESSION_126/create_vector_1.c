#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct vector_of_integers
{
    int* p_arr;
    int number_of_elements_in_vector;
};

struct vector_of_integers* create_vector(void);
int append_element_in_vector(struct vector_of_integers* p_vector, int element);
void show_vector(struct vector_of_integers* p_vector);
void destroy_vector(struct vector_of_integers* p_vector);

int main(void)
{
    struct vector_of_integers* p_vector = NULL;
    int choice;
    int element;
    int status;

    p_vector = create_vector();
    while(1)
    {
        puts("do you want to add element?  1] YES :");
        scanf("%d",&choice);
        if(choice == 1)
        {
            puts("Enter element");
            scanf("%d", &element);
            status = append_element_in_vector(p_vector, element);
            assert(status == 1);
        }
        else
            break;
            
    }

    show_vector(p_vector);
    destroy_vector(p_vector);
    p_vector = NULL;
    

    return(0);
}

struct vector_of_integers* create_vector(void)
{
    struct vector_of_integers* vector_1 = NULL;
    vector_1 = (struct vector_of_integers*)malloc(sizeof(struct vector_of_integers));
    assert(vector_1 != 0);
    vector_1 -> p_arr = NULL;
    vector_1 -> number_of_elements_in_vector = 0;
    return(vector_1);
}

int append_element_in_vector(struct vector_of_integers* p_vector, int element)
{
    p_vector->number_of_elements_in_vector = p_vector->number_of_elements_in_vector + 1;
    p_vector->p_arr = (int*)realloc(p_vector->p_arr, p_vector->number_of_elements_in_vector*sizeof(int));
    assert(p_vector->p_arr != NULL);
    p_vector->p_arr[p_vector ->number_of_elements_in_vector - 1] = element;
    return(1);
}

void show_vector(struct vector_of_integers* p_vector)
{
    int i;
    for(i = 0; i < p_vector->number_of_elements_in_vector; ++i)
        printf("element in vector = %d\n", p_vector->p_arr[i]);
}

void destroy_vector(struct vector_of_integers* p_vector)
{
    if(p_vector->p_arr != NULL)
        free(p_vector -> p_arr);
    free(p_vector);
    p_vector = NULL;
}