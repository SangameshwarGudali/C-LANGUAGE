// # alloc_size.exe 50 

#include <stdio.h> 
#include <stdlib.h>
#include <assert.h> 

int main(int argc, char* argv[])
{
    int number_of_elements; 
    int* p_arr = NULL; 
    int i; 

    if(argc != 2)
    {
        printf("UsageError:Correct Usage:%s numberOfElements\n", argv[0]); 
        exit(-1); 
    }

    number_of_elements = atoi(argv[1]); 
    printf("Number of elements = %d\n", number_of_elements); 

    if(number_of_elements <= 0)
    {
        puts("Size cannot be zero or negative"); 
        exit(-1); 
    }

    p_arr = (int*)calloc(number_of_elements, sizeof(int)); 
    assert(p_arr != NULL); 

    // input 
    for(i = 0; i < number_of_elements; ++i)
        p_arr[i] = (i+1) * 10; 

    for(i = 0; i < number_of_elements; ++i)
        printf("arr[%d]:%d\n", i, p_arr[i]); 

    free(p_arr); 
    p_arr = NULL; 

    return (EXIT_SUCCESS); 
}
