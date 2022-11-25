#include <stdio.h>
#include <stdlib.h>

void insert_at_sort(int *p_arr, int N);
void show_arr(int *p_arr, int N, const char *msg);

int main(void)
{
    int arr[10] = {10, 20, 30, 40, 54, 60, 7, 80, 90, 5};
    show_arr(arr, 10, "Before sort array");
    insert_at_sort(arr, 10);
    show_arr(arr, 10, "after sort array");

    return (0);
}

void insert_at_sort(int *p_arr, int N)
{
    int i;
    int key;

    key = p_arr[N - 1];
    i = N - 2;

    while (i > -1 && p_arr[i] > key)
    {
        p_arr[i + 1] = p_arr[i];
        i = i - 1;
    }

    p_arr[i + 1] = key;
}

void show_arr(int *p_arr, int N, const char *msg)
{
    int i;

    if (msg)
        puts(msg);

    for (i = 0; i < N; ++i)
    {
        printf("arr[%d] = %d\n", i, p_arr[i]);
    }
}
