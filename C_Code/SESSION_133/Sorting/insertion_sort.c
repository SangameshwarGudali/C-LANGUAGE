#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

int input(int** p_arr, int size);
void show(int* p_arr, int size, char* msg);
int insert_at_sorting_pos(int* p_arr, int size);
int insert_at_sort(int* p_arr, int size);

int main(int argc, char*argv[])
{
    int size = 0;
    int ret;
    int* p_arr = NULL;

    if(argc != 2)
    {
        printf("%s number_of_elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    size = atoi(argv[1]);
    if(size <= 0)
    {
        printf("array element size could not be negetive\n");
        exit(EXIT_FAILURE);
    }

    printf("size = %d\n", size);
    ret = input(&p_arr, size);
    assert(ret == SUCCESS);

    show(p_arr, size, "original array before sort");

    ret = insert_at_sort(p_arr, size);
    assert(ret == SUCCESS);

    show(p_arr, size, "sorted array");

    free(p_arr);
    p_arr = NULL;

    return(0);

}


int input(int** pp_arr, int size)
{
    int i;
    unsigned long long int n = 0;
    int* p_arr = NULL;

    p_arr = (int*)calloc(size, sizeof(int));
    assert(p_arr != NULL);

    for(i = 0; i < size; ++i)
    {
        n = rand();
        p_arr[i] = n;
    }
    *pp_arr = p_arr;
    return(SUCCESS);
}

void show(int* p_arr, int size, char* msg)
{
    int i;

    if(msg)
        puts(msg);

    for(i = 0; i < size; ++i)
    {
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
    }
}

int insert_at_sorting_pos(int* p_arr, int size)
{
    int key;
    int i;

    key = p_arr[size - 1];
    i = size - 2;

    while(i > -1 && p_arr[i] > key)
    {
        p_arr[i + 1] = p_arr[i];
        i = i - 1;
    }
    p_arr[i + 1] = key;
    return(SUCCESS);
}

int insert_at_sort(int* p_arr, int N)
{
    int size, ret, i;
    for(size = 2; size <= N; ++size)
    {
        ret = insert_at_sorting_pos(p_arr, size);
        assert(ret == SUCCESS);
    }
    
    return(SUCCESS);
}