#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct vector_of_integer
{
    int* p_arr;
    long long int number_of_elements;
};

struct vector_of_integer* create_vector(void);
int append_int_in_vector(struct vector_of_integer* p_vector, int element);
void show_vector(struct vector_of_integer* p_vector);


int main(void)
{
    struct vector_of_integer* p_vec_1 = NULL;
    struct vector_of_integer* p_vec_2 = NULL;

    int status;
    int choice;
    int element;

    p_vec_1 = create_vector();
    p_vec_2 = create_vector();

    status = append_int_in_vector(p_vec_1, 10);
    assert(status == 1);

    status = append_int_in_vector(p_vec_1, 20);
    assert(status == 1);
    

    while(1)
    {
        puts("do you wnat to append element? 1]YES 0]NO :");
        scanf("%d", &choice);
        if(choice == 0)
            break;
        else
        {
            puts("Enter the element : ");
            scanf("%d", &element);
            status = append_int_in_vector(p_vec_2, element);
            assert(status == 1);
        }
            
    }

    show_vector(p_vec_1);
    show_vector(p_vec_2);

    return(0);
}

struct vector_of_integer* create_vector(void)
{
    struct vector_of_integer* p_vector = NULL;

    p_vector = (struct vector_of_integer*)malloc(sizeof(struct vector_of_integer));
    assert(p_vector != NULL);

    p_vector -> p_arr = NULL;
    p_vector -> number_of_elements = 0;

    return(p_vector);
}

int append_int_in_vector(struct vector_of_integer* p_vector, int element)
{
    int choice;

    p_vector -> number_of_elements = p_vector -> number_of_elements + 1;
    p_vector -> p_arr = (int*)realloc(p_vector -> p_arr, p_vector -> number_of_elements * sizeof(int));
    assert(p_vector -> p_arr != NULL);
    p_vector -> p_arr[p_vector -> number_of_elements -1] = element;

    return(1);
}

void show_vector(struct vector_of_integer* p_vector)
{
    int i;
    for(i = 0; i < p_vector->number_of_elements; ++i)
        printf("p_vector_of_integers[%lld]: %d\n", (long long int)i, p_vector->p_arr[i]);
}