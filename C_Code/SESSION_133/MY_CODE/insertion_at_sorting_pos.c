#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

int insert_at_sorting_pos(int* p_arr, int N);
void show_arr(int* p_arr, int N);
void input(int* p_arr, int N);
void test_suite(void);
int insert_at_sort(int* p_arr, int N);

int main(void)
{
    test_suite();

    return(0);
}


void test_suite(void)
{
    int* p_arr = NULL;
    int N = 5;

    p_arr = input(&p_arr);
    show_arr(p_arr, N, "Before sort");
    insert_at_sort(p_arr, N);
    show_arr(p_arr, N, "After sort");

    free(p_arr);
    p_arr = NULL;
}

int insert_at_sorting_pos(int* p_arr, int N)
{
    int key;
    int i;

    key = p_arr[N - 1];
    i = (N - 2);

    while(i > (-1) && p_arr[i] > key)
    {
        p_arr[N - 1] = p_arr[N - 2];
        i = i - 1;
    }
    p_arr[N + 1] = key;
    return(SUCESS);

}

int insert_at_sort(int* p_arr, int N)
{
    int i;
    for(i = 1; i < N; ++i)
        insert_at_sorting_pos(p_arr, i+1);
    return(SUCCESS);
}

void show_arr(int* p_arr, int N, char* msg)
{
    int i;

    if(msg)
        puts(msg);
    for(i = 0; i < N; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
}

void input(int** pp_arr, int N)
{
    int i;
    int* p_arr = NULL;

    p_arr = (int*)calloc(N, sizeof(int));
    assert(p_arr != NULL);

    for(i = 0; i < N; ++i)
        p_arr[i] = rand();
}