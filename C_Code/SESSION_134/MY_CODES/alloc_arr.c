#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1

typedef int status_t;

status_t create_arry(int **pp_arr, int N);
void show_array(int *p_arr, int N, const char *msg);

int main(int argc, char *argv[])
{
    int number_of_elements = 0;
    int status;
    int *p_arr = NULL;
    int i = 0;

    if (argc != 2)
    {
        printf("usage Error : correct usage-> %s number_of_elements", argv[0]);
        return (EXIT_FAILURE);
    }

    number_of_elements = atoi(argv[1]);
    printf("number of element %d\n", number_of_elements);
    if (number_of_elements <= 0)
    {
        printf("array size not be 0 and negetive");
        return (EXIT_FAILURE);
    }

    status = create_array(&p_arr, number_of_elements);
    for (i = 0; i < number_of_elements; ++i)
        p_arr[i] = rand();
    show_array(p_arr, number_of_elements, "array elemets");

    free(p_arr);
    p_arr = NULL;

    return (p_arr);
}

status_t create_array(int **pp_arr, int N)
{
    int *p_arr = NULL;

    p_arr = (int *)calloc(N, sizeof(int));
    assert(p_arr != NULL);

    *pp_arr = p_arr;

    return (SUCCESS);
}

void show_array(int *p_arr, int N, const char *msg)
{
    int i;
    if (msg)
        puts(msg);

    for (i = 0; i < N; ++i)
        printf("arr[%d] = %d\n", i, p_arr[i]);
}