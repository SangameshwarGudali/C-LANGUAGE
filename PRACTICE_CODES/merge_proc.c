#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE    1
#define SUCCESS 1

int merge_sort_proc(int* arr, int p, int q, int r);

int main(void)
{
    int arr[] = {100, 45, 77, 65, 11, 10, 20, 30, 40, 50, 60, 70, 35, 42, 45, 48, 55, 65, 66, 780, -84, 97, 100};
    int p = 5, q = 11, r = 18;
    int i, ret;
    printf("array range is arr[%d.......%d]\n", p, r);
    printf("Before merge array\n");
    for(i = 0; i < (r - p); ++i)
        printf("arr[%d] = %d\n", p+i, arr[p+i]);
    
    ret = merge_sort_proc(arr, p, q, r);
    assert(ret == SUCCESS);
    
    printf("After merge array\n");
    
    for(i = 0; i < (r - p); ++i)
        printf("arr[%d] = %d\n", p+i, arr[p+i]);

    return(0);
}

int merge_sort_proc(int* arr, int p, int q, int r)
{
    int* a1 = NULL;
    int* a2 = NULL;
    int N1 , N2;
    int k1, k2;
    int i;

    N1 = (q - p + 1);
    N2 = (r - q);

    a1 = (int*)calloc(N1, sizeof(int));
    assert(a1 != NULL);

    a2 = (int*)calloc(N2, sizeof(int));
    assert(a2 != NULL);

    for(i = 0; i < N1; ++i)
        a1[i] = arr[p+i];
    for(i = 0; i < N2; ++i)
        a2[i] = arr[q+1+i];

    i = 0;
    k1 = 0;
    k2 = 0;
    while(TRUE)
    {
        if(a1[k1] < a2[k2])
        {
            arr[p+i] = a1[k1];
            i++;
            k1++;
            if(a1[k1] == a1[N1])
            {
                while(a2[k2] == a2[N2])
                {
                    arr[p+i] = a2[k2];
                    i++;
                    k2++;
                }
                break;
            }
        }
        
        else
        {
            arr[p+i] = a2[k2];
            i++;
            k2++;
            if(a2[k2] == a2[N2])
            {
                while(a1[k1] == a1[N1])
                {
                    arr[p+i] = a1[k1];
                    i++;
                    k1++;
                }
                break;
            }
        }
    }

    return(SUCCESS);
}