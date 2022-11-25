#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void input(int **pp_arr, int N);
void show(int *p_arr, int N, const char *msg);
void sort(int *p_arr, int N);

int main(int argc, char *argv[])
{
    int N; // numberOfElements
    int *p_arr = NULL;

    if (argc != 2)
    {
        printf("usageError : correctUsage : %s numberOfElements\n", argv[0]);
        exit(-1);
    }

    N = atoi(argv[1]);
    printf("numberOfElements = %d\n", N);

    if (N <= 0)
    {
        printf("array size cannot be 0 and negetive\n");
        exit(EXIT_FAILURE);
    }

    input(&p_arr, N);
    show(p_arr, N, "before sort");
    sort(p_arr, N);
    show(p_arr, N, "after sort");

    free(p_arr);
    p_arr = NULL;

    return (0);
}

void sort(int *p_arr, int N)
{
    return;
}

void input(int **pp_arr, int N)
{
    int *p_arr = NULL;
    int i;

    p_arr = (int *)calloc(N, sizeof(int));
    assert(p_arr != NULL);

    for (i = 0; i < N; ++i)
        p_arr[i] = rand();

    *pp_arr = p_arr;
}

void show(int *p_arr, int N, const char *msg)
{
    int i = 0;

    if (msg)
        puts(msg);

    for (i = 0; i < N; ++i)
        printf("arr[%d] = %d\n", i, p_arr[i]);
}