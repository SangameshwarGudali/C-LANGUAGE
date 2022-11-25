#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
    @p_arr: pointer containing base address of array
    @N: Size of array
    valid index range: 0 to N-1

    Precondition: elements from index 0 to index N-2 are sorted
    (all but last element are sorted)

    the element at last index (i.e. element at index N-1) may not
    be in sorted order.

    Postcondition: Entire array (index 0 to index N-1) should be sorte
*/

void insert_at_sorting_pos(int *p_arr, int N);
void show(int *p_arr, int N, const char *msg);

int main(void)
{
    int arr[6] = {10, 20, 30, 40, 50, 5};
    show(arr, 6, "Before sort");
    insert_at_sorting_pos(arr, 6);
    show(arr, 6, "after sort");

    return (0);
}

void insert_at_sorting_pos(int *p_arr, int N)
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

void show(int *p_arr, int N, const char *msg)
{
    int i;

    if (msg)
        puts(msg);

    for (i = 0; i < N; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
}