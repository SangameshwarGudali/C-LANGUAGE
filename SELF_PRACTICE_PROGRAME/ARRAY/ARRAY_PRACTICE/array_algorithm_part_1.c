#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1

void input(int *p_arr, int N);
void *xcalloc(size_t nr_of_elements, size_t size_in_bytes);
int get_reversed_array(int *src_arr, int **dest_arrr, int N);
void show_array(int *p_arr, int N, const char *msg);
void reversed_array(int *p_arr, int N);

int main(int argc, char *argv[])
{
    int N = 0;
    int *p_arr = NULL;
    int *p_rev_arr = NULL;

    if (argc != 2)
    {
        printf("usageError : correctUsage : %s numberOfElements\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    N = atoi(argv[1]);
    if (N <= 0)
    {
        printf("array size could not be 0 and negetive");
        exit(EXIT_FAILURE);
    }
    printf("number of elements in array = %d\n", N);

    p_arr = (int *)xcalloc(N, sizeof(int));
    assert(p_arr != NULL);
    input(p_arr, N);
    show_array(p_arr, N, "after filled array");

    get_reversed_array(p_arr, &p_rev_arr, N);
    show_array(p_rev_arr, N, "get reversed array");

    reversed_array(p_arr, N);
    show_array(p_arr, N, "reversed array");

    free(p_arr);
    p_arr = NULL;

    return (0);
}

void input(int *p_arr, int N)
{
    int i;

    for (i = 0; i < N; ++i)
        p_arr[i] = 10 + (i + 1);
}

void *xcalloc(size_t nr_of_elements, size_t size_in_bytes)
{
    void *p = NULL;

    p = calloc(nr_of_elements, size_in_bytes);
    assert(p != NULL);

    return (p);
}

int get_reversed_array(int *src_arr, int **pp_arrr, int N)
{
    int i = 0;
    int j = 0;
    int *p_arr = NULL;

    p_arr = (int *)xcalloc(N, sizeof(int));
    assert(p_arr != NULL);

    for (i = 0; i < N; ++i)
    {
        p_arr[i] = src_arr[N - i - 1];
    }
    *pp_arrr = p_arr;

    return (SUCCESS);
}

void reversed_array(int *p_arr, int N)
{
    int i = 0;
    int temp = 0;
    for (i = 0; i < N / 2; i++)
    {
        temp = p_arr[i];
        p_arr[i] = p_arr[N - i - 1];
        p_arr[N - i - 1] = temp;
    }
}

void show_array(int *p_arr, int N, const char *msg)
{
    int i;

    if (msg != NULL)
        puts(msg);

    for (i = 0; i < N; ++i)
        printf("arr[%d] = %d\n", i, p_arr[i]);
}