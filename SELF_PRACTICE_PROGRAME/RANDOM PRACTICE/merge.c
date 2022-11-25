#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1

void merge(int *p_arr, int p, int q, int r);

int main(void)
{
    int a[19] = {144, 654, 684, 10, 20, 30, 40, 50, 15, 25, 28, 29, 41, 42, 45, 48, -1, -2, -3};
    //                              p                   q               r
    int p, q, r, N, i;
    p = 3, q = 8, r = 15;
    N = 15;

    printf("showing a[%d....%d] before merging\n", p, r);
    for (i = p; i <= r; ++i)
        printf("a[%d] = %d\n", i, a[i]);
    merge(a, p, q, r);
    printf("showing [a%d.....%d] after merging\n", p, r);
    for (i = p; i <= r; ++i)
        printf("a[%d] = %d\n", i, a[i]);

    return (0);
}

void merge(int *a, int p, int q, int r)
{
    int *a1 = NULL;
    int *a2 = NULL;
    int k1 = 0;
    int k2 = 0;
    int i;
    int n1;
    int n2;

    n1 = q - p + 1;
    n2 = r - q;

    a1 = (int *)malloc(n1 * sizeof(int));
    assert(a1 != NULL);

    a2 = (int *)malloc(n2 * sizeof(int));
    assert(a2 != NULL);

    for (i = 0; i < n1; ++i)
        a1[i] = a[p + i];

    for (i = 0 + 1; i < n2; ++i)
        a2[i] = a[q + 1 + i];

    puts("inside");

    k1 = 0;
    k2 = 0;
    i = 0;
    while (TRUE)
    {

        if (a1[k1] <= a2[k2])
        {

            a[p + i] = a1[k1];
            k1++;
            i++;
            if (k1 == n1)
            {
                while (k2 < n1)
                {
                    a[p + i] = a2[k2];
                    k2++;
                    i++;
                }
                break;
            }
        }
        else
        {
            a[p + i] = a2[k2];
            k2++;
            i++;
            if (k2 == n2)
            {
                while (k1 < n1)
                {
                    a[p + i] = a1[k1];
                    k1++;
                    i++;
                }
                break;
            }
        }
    }

    a1 = NULL;
    free(a1);
    a2 = NULL;
    free(a2);
}
