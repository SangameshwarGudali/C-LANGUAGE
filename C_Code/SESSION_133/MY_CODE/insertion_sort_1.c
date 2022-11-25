#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insertion_at_pos(int *p_arr, int N);
void show(int *p_arr, int N, const char *msg);
void sort(int *p_arr, int N);
void insertion_at_pos(int *p_arr, int N);
void input(int **pp_arr, int N);

int main(int argc, char *argv[])
{
    int N = 0;
    int *p_arr = NULL;

    if (argc != 2)
    {
        printf("%s number_of_elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);
    if (N <= 0)
    {
        printf("Array size could not be Negetive");
        exit(EXIT_FAILURE);
    }

    input(&p_arr, N);
    show(p_arr, N, "Before sorting list");
    sort(p_arr, N);
    show(p_arr, N, "after sorting list");

    p_arr = NULL;
    free(p_arr);

    return (0);
}

void input(int **pp_arr, int N)
{
    int i;
    int *p_arr = NULL;

    p_arr = (int *)calloc(N, sizeof(int));
    assert(p_arr != NULL);

    for (i = 0; i < N; ++i)
        p_arr[i] = rand();

    *pp_arr = p_arr;
}

void insertion_at_pos(int *p_arr, int N)
{
    int key;
    int i;

    key = p_arr[N - 1];
    i = N - 2;

    while (i > -1 && p_arr[i] > key)
    {
        p_arr[i + 1] = p_arr[i];
        i = i - 1;
    }
    p_arr[i + 1] = key;
}

void sort(int *p_arr, int N)
{
    int size;

    for (size = 2; size < N; ++size)
        insertion_at_pos(p_arr, size);
}

void show(int *p_arr, int N, const char *msg)
{
    int i;
    if (msg)
        puts(msg);

    for (i = 0; i < N; ++i)
    {
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
        puts("show");
    }
}