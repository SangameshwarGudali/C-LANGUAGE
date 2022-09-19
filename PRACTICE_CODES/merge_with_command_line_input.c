#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1
#define TRUE    1

int input(int** pp_arr, int total_size, int p, int q, int r);
void show(int* p_arr, int total_size, char* msg);
int merge_proc(int* p_arr, int p, int q, int r);

int main(int argc, char* argv[])
{
    int total_size, ret;
    int p, q, r;

    if(argc != 5)
    {
        printf("please enter the command in following sequence\n");
        printf("%s, total_size, p, q, r\n", argv[0]);
        puts("try again");
        exit(EXIT_FAILURE);
    }

    total_size = atoi(argv[1]);
   
    if(total_size <= 0)
    {
        printf("nr of elements could not be less and equal to 0\n");
        exit(EXIT_FAILURE);
    }

    p = atoi(argv[2]);
    q = atoi(argv[3]);
    r = atoi(argv[4]);
    
    int* p_arr = NULL;

    ret = input(&p_arr, total_size, p, q, r);
    assert(ret == SUCCESS);

    show(p_arr, total_size, "showing array before merge proc");
    ret = merge_proc(p_arr, p, q, r);
    show(p_arr, total_size, "Showing array After merge sorted subarray");

    free(p_arr);
    p_arr = NULL;
    
    return(0);

}

int input(int** pp_arr, int total_size, int p, int q, int r)
{
    int* p_arr = NULL;

    p_arr = (int*)calloc(total_size , sizeof(int));
    assert(p_arr != NULL);

    int i;
    for(i = 0; i < total_size; ++i)
    {
        if(i == p)
        {
            for(i = p; i < q; ++i)
            {
                p_arr[i] = (i+1)*4;
                //printf("p_arr[%d] = %d\n", i, p_arr[i]);

            }
        }
        if(i == q)
        {
            for(i = q; i <= r; ++i)
            {
                p_arr[i] = (i+1)*3;
                //printf("p_arr[%d] = %d\n", i, p_arr[i]);
                //puts("check");
            }
        }

        p_arr[i] = rand();
        ///printf("p_arr[%d] = %d\n", i, p_arr[i]);
    }
    *pp_arr = p_arr;
    return(SUCCESS);
}

void show(int* p_arr, int total_size, char* msg)
{
    if(msg)
        puts(msg);
        
    int i;
    for(i = 0; i < total_size; ++i)
    {
        printf("arr[%d] = %d\n", i, p_arr[i]);
    }
}

int merge_proc(int* p_arr, int p, int q, int r)
{
    int* a1 = NULL;
    int* a2 = NULL;
    int N1 = 0;
    int N2 = 0;

    N1 = (q - p + 1);
    N2 = (r - q);

    a1 = (int*)calloc(N1, sizeof(int));
    assert(a1 != NULL);

    a2 = (int*)calloc(N2, sizeof(int));
    assert(a2 != NULL);

    int i;
    for(i = 0; i < N1; ++i)
        a1[i] = p_arr[p+i];
    for(i = 0; i < N2; ++i)
        a2[i] = p_arr[q+1+i];

    i = 0;
    int k1 = 0;
    int k2 = 0;
    while(TRUE)
    {
        if(a1[k1] < a2[k2])
        {
            p_arr[p+i] = a1[k1];
            k1++;
            i++;
            if(a1[k1] == a1[N1])
            {
                while(a2[k2] == a2[N2])
                {
                    p_arr[p+i] = a2[k2];
                    k2++;
                    i++;
                }
                break;
            }
        }
        else
        {
            p_arr[p+i] = a2[k2];
            k2++;
            i++;
            if(a2[k2] == a2[N2])
            {
                while(a1[k1] == a1[N1])
                {
                    p_arr[p+i] = a1[k1];
                    k1++;
                    i++;
                }
                break;
            }
        }
    }
    return(SUCCESS);
}