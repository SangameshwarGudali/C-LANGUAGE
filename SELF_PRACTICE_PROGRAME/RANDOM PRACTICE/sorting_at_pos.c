#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void input(int **pp_arr, size_t N);
void sort(int *p_arr, size_t N);
void sorting_at_pos(int *p_arr, size_t);
void xrealloc(int **pp_arr, size_t N);
void fill_last_element(int *p_arr, size_t N);
void show(int *p_arr, size_t N, const char *msg);

int main(int argc, char *argv[])
{
    int i;
    int N;
    int *arr = NULL;
    int last_element = 0;

    if (argc != 2)
    {
        printf("%s numbe_of_elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);
    if (N <= 0)
    {
        printf("Array element size could not be negetive");
        exit(EXIT_FAILURE);
    }

    input(&arr, N);
    show(arr, N, "Before sorting array");

    int new_size = 0;
    puts("Increase array index by 1");
    scanf("%d", &new_size);

    arr = (int *)realloc(arr, new_size);
    assert(arr != NULL);

    fill_last_element(arr, new_size);
    show(arr, new_size, "New total array");

    sort(arr, new_size);
    show(arr, new_size, "After sorting last element");

    arr = NULL;
    free(arr);

    return (0);
}

void input(int **pp_arr, size_t N)
{
    int i;
    int *p_arr = NULL;

    p_arr = (int *)calloc(N, sizeof(int));
    assert(p_arr != 0);

    for (i = 0; i < N; ++i)
        p_arr[i] = (i + 1) * 10;
    *pp_arr = p_arr;
}

void sort(int *p_arr, size_t N)
{
    int size = 0;

    for (size = 2; size <= N; ++size)
        sorting_at_pos(p_arr, size);
}

void sorting_at_pos(int *p_arr, size_t N)
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

void fill_last_element(int *p_arr, size_t N)
{
    int last_value;

    puts("Enter last index value");
    scanf("%d", &last_value);
    p_arr[N - 1] = last_value;
}

void show(int *p_arr, size_t N, const char *msg)
{
    int i;

    if (msg)
        puts(msg);
    for (i = 0; i < N; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
}