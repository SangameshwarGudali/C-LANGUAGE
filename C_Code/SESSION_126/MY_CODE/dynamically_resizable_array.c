#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

struct vector_of_integers
{
    int* p_arr;
    long long int nr_of_elements;
};

struct vector_of_integers* create_vector(void);
int append_element_to_vector(struct vector_of_integers* p_vector, int element);
void show_vector(struct vector_of_integers* p_vector, char* msg);
void destroy_vector(struct vector_of_integers* p_vector);
int input_to_vector(struct vector_of_integers* p_vector, int nr_of_element);

int main(void)
{
    int choice = 0;
    int element = 0;
    int status = 0;
    struct vector_of_integers* p_vector1 = NULL;

    p_vector1 = create_vector();
    assert(p_vector1 != NULL);

    while(1)
    {
        puts("If you want to add element in vector press 1] otherwise press anything");
        scanf("%d", &choice);
        puts("Enter the element");
        scanf("%d", &element);

        if(choice == 1)
        {
            status = append_element_to_vector(p_vector1, element);
            assert(status == 1);
        }
        else
            break;
    }

    show_vector(p_vector1, "vector 1");
    destroy_vector(p_vector1);

    return(0);
}

struct vector_of_integers* create_vector(void)
{
    struct vector_of_integers* p_vector = NULL;

    p_vector = (struct vector_of_integers*)malloc(sizeof(struct vector_of_integers));
    assert(p_vector != NULL);

    p_vector->p_arr = NULL;
    p_vector->nr_of_elements = 0;

    return(p_vector);
}

int append_element_to_vector(struct vector_of_integers* p_vector, int element)
{
    p_vector->nr_of_elements = p_vector->nr_of_elements + 1;
    p_vector->p_arr = realloc(p_vector->p_arr, sizeof(p_vector->nr_of_elements * sizeof(int)));
    assert(p_vector != NULL);

    p_vector->p_arr[p_vector->nr_of_elements - 1] = element;
    return(SUCCESS);
}

void show_vector(struct vector_of_integers* p_vector, char* msg)
{
    if(msg)
        puts(msg);
    int i;
    for(i = 0; i < p_vector->nr_of_elements; ++i)
        printf("p_arr[%d] = %d\n", i, p_vector->p_arr[i]);
}

void destroy_vector(struct vector_of_integers* p_vector)
{
    if(p_vector->p_arr != NULL)
        free(p_vector->p_arr);
    free(p_vector);
}