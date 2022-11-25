#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1

void merge_proc(int *p_arr, int p, int q, int r);

int main(void)
{
    int i = 0;
    int arr[] = {50, 70, 650, 400, 10, 54, 32, 88, 51, 12, 265, 85, 9, 41, 72, 65, 78, 39, 22, 11,
                 -55, -65, -75, -89};
    int p = 5, q = 12, r = 20;

    puts("before sort");
    for (i = p; i <= r; ++i)
        printf("arr[%d] = %d\n", i, arr[i]);

    merge_proc(arr, p, q, r);

    puts("after sorted merge sub arrays");
    for (i = p; i <= r; ++i)
        printf("arr[%d] = %d\n", i, arr[i]);

    return (0);
}

void merge_proc(int *p_arr, int p, int q, int r)
{
    int i = 0;
    int *sub1 = NULL; // subarray 1
    int *sub2 = NULL; // subarray 2
    size_t n1;        // length of sub1
    size_t n2;        // length of sub2
    int k1;           // for subarray sub1
    int k2;           // for subarray sub2
    n1 = q - p + 1;
    n2 = r - q;

    sub1 = (int *)calloc(n1, sizeof(int));
    assert(sub1 != NULL);

    sub2 = (int *)calloc(n2, sizeof(int));
    assert(sub2 != NULL);

    for (i = 0; i < n1; ++i)
        sub1[i] = p_arr[p + i];

    for (i = 0; i < n2; ++i)
        sub2[i] = p_arr[q + 1 + i];

    k1 = 0;
    k2 = 0;
    i = 0;

    while (TRUE)
    {
        if (sub1[k1] <= sub2[k2])
        {
            p_arr[p + i] = sub1[k1];
            k1++;
            i++;
            if (k1 == n1)
            {
                while (k2 < n2)
                {
                    p_arr[p + i] = sub2[k2];
                    k2++;
                    i++;
                }
                break;
            }
        }

        else
        {
            p_arr[p + i] = sub2[k2];
            k2++;
            i++;
            if (k2 == n2)
            {
                while (k1 < n1)
                {
                    p_arr[p + i] = sub1[k1];
                    k1++;
                    i++;
                }
                break;
            }
        }
    }

    free(sub1);
    sub1 = NULL;

    free(sub2);
    sub2 = NULL;
}