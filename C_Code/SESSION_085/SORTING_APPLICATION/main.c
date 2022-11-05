#include <stdio.h> 
#include <stdlib.h> 
#include "sort.h"

int main(void)
{
    int* p_array = NULL; 
    int size; 
    puts("With header file"); 
    p_array = get_array(&size); 
    input_array(p_array, size); 
    sort_array(p_array, size); 
    output_array(p_array, size); 
    release_array(&p_array); 

    exit(0); 
}
