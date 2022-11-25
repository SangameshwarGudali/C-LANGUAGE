#include "revarray.h"

void test_get_reversed_array_1()
{
    size_t N = 5;
    int* p_arr = NULL;
    int* rev_arr = NULL;
    int rev_arr_size = 0;

    p_arr = get_input_array(N);
    show(p_arr, N, "ORIGINAL ARRAY 1");
    rev_arr = get_reversed_array_1(p_arr, N, &rev_arr_size);
    show(rev_arr, N, "SHOW REVERSED ARRAY 1\n");

    free(p_arr);
    p_arr = NULL;

    free(rev_arr);
    rev_arr = NULL;
}

void test_get_reversed_array_2()
{
    
    size_t N = 5;
    int* p_arr = NULL;
    int* rev_arr = NULL;
    int rev_arr_size = 0;
    int status = 0;

    p_arr = get_input_array(N);
    show(p_arr, N, "ORIGINAL ARRAY 2 \n");
    status = get_revesed_array_2(p_arr, N, &rev_arr, &rev_arr_size);
    show(rev_arr, N, "SHOW REVERSED ARRAY 2\n");

    free(p_arr);
    p_arr = NULL;

    free(rev_arr);
    rev_arr = NULL;
}

void test_get_reversed_array_3()
{
    struct array_int* p_input_arr = NULL;
    struct array_int* p_output_arr = NULL;
    int i;

    p_input_arr = (struct array_int*)xmalloc(sizeof(struct array_int));
    p_input_arr->N = 5;
    p_input_arr->p_arr = get_input_array(p_input_arr->N);

    show(p_input_arr->p_arr, p_input_arr->N, "SHOW ORIGINAL ARRAY 3\n");
    p_output_arr = get_reversed_array_3(p_input_arr);
    show(p_output_arr->p_arr, p_output_arr->N, "SHOW REVERSED ARRAY 3\n");

    free(p_input_arr);
    p_input_arr = NULL;

    free(p_output_arr);
    p_output_arr = NULL;
}

void test_get_reversed_array_4()
{
    status_t status = 0;
    struct array_int* p_input_arr = NULL;
    struct array_int* p_output_arr = NULL;
    
    p_input_arr = (struct array_int*)xmalloc(sizeof(struct array_int));
    p_input_arr->N = 5;
    p_input_arr->p_arr = get_input_array(p_input_arr->N);

    show(p_input_arr->p_arr, p_input_arr->N, "SHOW ORIGINAL ARRAY 4\n");
    status = get_reversed_array_4(p_input_arr, &p_output_arr);
    
    show(p_input_arr->p_arr, p_input_arr->N, "SHOW REVERSED ARRAY 4");

    free(p_input_arr);
    p_input_arr = NULL;

    free(p_output_arr);
    p_output_arr = NULL;
}

