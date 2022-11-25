#define _CRT_RAND_S

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void input(int **pp_arr, int N);
void insert_at_pos(int *p_arr, int N);
void sort(int *p_arr, int N);
void show(int *p_arr, int N, const char *msg);

int main(int argc, char *argv[])
{
    int N;
    int *p_arr = NULL;

    if (argc != 2)
    {
        printf("%s number_of_elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);
    if (N <= 0)
    {
        printf("array value cannot be less than 0");
        return (EXIT_FAILURE);
    }

    input(&p_arr, N);
    show(p_arr, N, "insertion before sort");
    sort(p_arr, N);
    show(p_arr, N, "insertion after sort");

    p_arr = NULL;
    free(p_arr);

    return (0);
}

void input(int **pp_arr, int N)
{
    int i = 0;
    int *p_arr = NULL;
    int num = 0;

    p_arr = (int *)calloc(N, sizeof(int));
    assert(p_arr != 0);

    for (i = 0; i < N; ++i)
    {
        p_arr[i] = rand();
    }
    *pp_arr = p_arr;
}

void insert_at_pos(int *p_arr, int N)
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
    int size = 0;
    puts("sort");
    for (size = 2; size <= N; ++size)
        insert_at_pos(p_arr, size);
}

void show(int *p_arr, int N, const char *msg)
{
    if (msg)
        puts(msg);

    int i;
    for (i = 0; i < N; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
}