#include <stdio.h>
#include <stdio.h>

typedef int status_t;

int min_element_of_array_1(int* p_ip_arr, size_t ip_N);
status_t min_element_of_array_2(int* p_arr, size_t N, int* min_element);

int* get_input_array(size_t N);
void show(int* p_arr, size_t N, char* msg);
void* xcalloc(size_t nr_of_elements, size_t nr_of_bytes);


int main(void)
{
    size_t N = 5;
    status_t status;
    int min_element;
    int* p_arr = NULL;

    p_arr = get_input_array(N);
    show(p_arr, N, "original array");
    min_element = min_element_of_array_1(p_arr, N);
    printf("min element in array = %d\n", min_element);
    //status = min_element_of_array_2(p_arr, N, &min_element);
    //printf("min element of array = %d\n", min_element);

    return(0);
}

int min_element_of_array_1(int* p_arr, size_t N)
{
    int i;
    int temp = p_arr[0];

    i = 0;
    while(i < N)
    {
        if(temp > p_arr[i])
            temp = p_arr[i];
    }
    
    for(i = 0; i < N; ++i)
    {
        if(temp > p_arr[i])
        {
            temp = p_arr[i];
        }
    }
    return(temp);
}

int* get_input_array(size_t N)
{
    int* p_arr = NULL;
    int i;

    p_arr = (int*)calloc(N, sizeof(int));
    for(i = 0; i < N; ++i)
        p_arr[i] = rand();
    return(p_arr);
}

void show(int* p_arr, size_t N, char* msg)
{
    if(msg)
        puts(msg);
    int i;
    for(i = 0; i < N; ++i)
        printf("arr[%d] = %d\n", i, p_arr[i]);
}



int min_max(int* p_arr, size_t N, int* p_min);
int min_max(int* p_arr, size_t N, int* p_max);

struct output
{
    int max;
    int min;
};

struct output* min_max(int* p_arr, size_t N);
status_t min_max(int* p_arr, size_t N, struct output** pp_output);

status_t min_max(int* p_arr, size_t N, int* p_min, int* p_max);