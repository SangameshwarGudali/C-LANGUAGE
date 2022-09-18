#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1

int input(int** pp_arr, int N);
int sort(int* p_arr, int N);
int insert_at_sort(int* p_arr, int N);
void show(int* p_arr, int N, char* msg);

int main(int argc, char* argv[])
{
    int N, ret;
    int* p_arr = NULL;

    if(argc != 2)
    {
        puts("please enter the commands in following sequence");
        printf("%s  nr_of_elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);
    if(N <= 0)
    {
        printf("array element size couldd not be 0 and Negative\n");
        exit(EXIT_FAILURE);
    }

    ret = input(&p_arr, N);
    assert(ret == SUCCESS);

    show(p_arr, N, "Array element before sort");

    sort(p_arr, N);

    show(p_arr, N, "Array element After sort");

    free(p_arr);
    p_arr = NULL;

    return(0);

}

int input(int** pp_arr, int N)
{
    int i;
    int* p_arr = NULL;

    p_arr = (int*)calloc(N, sizeof(int));
    assert(p_arr != NULL);

    for(i = 0; i < N; ++i)
        p_arr[i] = rand();
    *pp_arr = p_arr;

    return(SUCCESS);
}

int sort(int* p_arr, int N)
{
    int size, ret;
    for(size = 2; size <= N; ++size)
    {
        ret = insert_at_sort(p_arr, size);
        assert(ret == SUCCESS);
    }
    return(SUCCESS);
}
        

int insert_at_sort(int* p_arr, int N)
{
    int key, i;
    
    key = p_arr[N - 1];
    i = N - 2;
    while(i >= -1 && p_arr[i] > key)
    {
        p_arr[i + 1] = p_arr[i];
        i = i - 1;
    }
    p_arr[i + 1] = key;
    return(SUCCESS);
}

void show(int* p_arr, int N, char* msg)
{
    int i;
    if(msg)
        puts(msg);
    for(i = 0; i < N; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
}
