/* 
    Problem: English: Get the reversed version of the given array 

    Design:
        1) Name the procedure 
            get_reversed_array(); 

        2) How to input the given array? 
            Two parameters are enough to input an array to a function 
            address of first element of array 
            size of array 

            Callee must catch address of first element of array in 
            pointer to array element type 

            array element type -> int 
            pointer to array element type -> int* 

            As it is a pointer to array, we are naming it as 
            p_arr. 

            Therefore, the first formal parameter becomes 
            int* p_arr 

            Callee can catch the size of array in unsigned long long int i.e. size_t 
            Let N be the variable name.
            Therefore, the second parameter becomes 
            size_t N

            get_reversed_array(int* p_arr, size_t N); 

        3)  Plan the output. 
            You are going to allocate a new array of size N dynamically (on heap)
            That array will be filled with the reversed version of input array 
            
            How will you return that array? 

            In order to return array, you must return, two values, 
            address of the first element of reversed array 
            size of the reversed array. 

            You can return only one value using return value mechanism 
            Therefore, the other value must be a parameter as return value. 

            Option 1: 

            int* get_reversed_array(int* p_arr, size_t N, size_t* p_size); 

            address of first element of reversed array -> return value 
            array is of integer 
            therefore, type of variable which will hold the address of first 
            element of array is int* 
            therefore, the return value int* 

            A caller must define an instance of size_t and send its address 
            so that get_reversed_array and write size of reversed array on that addr. 

            Therefore, 

            // def 
            int* get_reversed_array(int* p_arr, size_t N, size_t* p_reversed_size)
            {

            }


            int main()
            {
                int* p_arr = some array; 
                size_t N = some size 

                int* p_reversed_array = NULL; 
                size_t reversed_N; 

                p_reversed_array = get_reversed_array(p_array, N, &reversed_N); 

                for(i = 0; i < reversed_N; ++i)
                    p_reversed_array[i] // read write 

                free(p_reversed_array); 
                p_reversed_array = NULL;    
            }

            Option 2: all return values are parameters as return value 

            status_t get_reversed_array(int* p_arr, size_t N, int** pp_reversed_arr, size_t* p_size); 
            
            int main(void)
            {
                int* p_arr = some array; 
                size_t N = some size; 
                status_t ret; 

                int* p_reversed_array = NULL; 
                size_t reversed_N = 0; 

                ret = get_reversed_array(p_arr, N, &p_reversed_array, &reversed_N); 
                assert(ret); 
            }

            Option: 

            struct array_int
            {
                int* p_arr; 
                size_t N; 
            }; 

            struct array_int* get_reversed_array(struct array_int* p_array); 

            int main(void)
            {
                struct array_int* p_input = NULL; 
                struct array_int* p_op = NULL; 
                p_input = xmalloc(sizeof(struct array_int))' 
                p_input->N = 8; 
                p_input->p_arr = (int*)xcalloc(p_input->N, sizeof(int)); 
                for(i = 0; i < p_input->N; ++i)
                    p_input->p_arr[i] = (i+1) * 100; 

                p_op = get_reversed_array(p_input); 
                print p_op->p_arr

                free(p_input->p_arr); 
                free(p_input); 
                p_input = NULL; 

                free(p_op->p_arr); 
                free(p_op); 
                p_op = NULL; 
            }

            struct array_int* get_reversed_array(struct array_int* p_array)
            {
                struct array_int* p_op = NULL; 

                p_op = (struct array_int*)malloc(sizeof(struct array_int)); 
                p_op->N = p_array->N; 
                p_op->p_arr = (int*)xcalloc(p_op->N, sizeof(int)); 

                put reversed of p_array->p_arr into p_op->p_arr 

                return p_op; 
            }

            status_t get_reversed_array(struct array_int* p_input, struct array_int** pp_output); 
*/ 


#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define SUCCESS 1 

typedef int status_t; 

void* xmalloc(size_t nr_bytes);
void* xcalloc(size_t nr_elements, size_t size_per_element); 
void* xrealloc(void* old_ptr, size_t new_size); 

// option 1 
int* get_reversed_array_1(int* p_arr, size_t N, size_t* p_size); 

// option 2 
status_t get_reversed_array_2(  int* p_arr, 
                                size_t N, 
                                int** pp_reversed_array, 
                                size_t* p_reversed_size
                            ); 

// option 3 
struct array_int
{
    int* p_arr; 
    size_t N; 
}; 

struct array_int* get_reversed_array_3(struct array_int* p_input_arr); 

// option 4 
status_t get_reversed_array_4(struct array_int* p_input_arr, struct array_int** pp_output_array); 

int* get_input_array(size_t N); 
void show(int* p_arr, size_t N, const char* msg); 

void test_get_reversed_array_1(void); 
void test_get_reversed_array_2(void); 
void test_get_reversed_array_3(void); 
void test_get_reversed_array_4(void); 

int main(void)
{
    test_get_reversed_array_1(); 
    test_get_reversed_array_2(); 
    test_get_reversed_array_3(); 
    test_get_reversed_array_4(); 

    return (EXIT_SUCCESS); 
}

int* get_reversed_array_1(int* p_arr, size_t N, size_t* p_size)
{
    int* p_arr_r = NULL; 
    size_t rN = 0; 
    size_t i; 

    rN = N; 
    p_arr_r = (int*)xmalloc(rN * sizeof(int)); 

    for(i = 0; i < rN; ++i)
        p_arr_r[i] = p_arr[rN-i-1]; 

    *p_size = rN; 
    return (p_arr_r); 
}

status_t get_reversed_array_2(  int* p_arr, 
                                size_t N, 
                                int** pp_reversed_array, 
                                size_t* p_reversed_size
                            )
{
    int* p_arr_r = NULL; 
    size_t rN = 0; 
    size_t i; 

    rN = N; 
    p_arr_r = (int*)xmalloc(rN * sizeof(int)); 

    for(i = 0; i < rN; ++i)
        p_arr_r[i] = p_arr[rN-i-1];    

    *pp_reversed_array = p_arr_r; 
    *p_reversed_size = rN;   

    return (SUCCESS); 
}

struct array_int* get_reversed_array_3(struct array_int* p_input_arr)
{
    struct array_int* p_op = NULL; 
    size_t i; 

    p_op = (struct array_int*)xmalloc(sizeof(struct array_int)); 
    p_op->N = p_input_arr->N; 
    p_op->p_arr = (int*)xcalloc(p_op->N, sizeof(int)); 

    for(i = 0; i < p_op->N; ++i)
        p_op->p_arr[i] = p_input_arr->p_arr[p_op->N - i - 1]; 

    return (p_op); 
}

status_t get_reversed_array_4(struct array_int* p_input_arr, struct array_int** pp_output_array)
{
     struct array_int* p_op = NULL; 
    size_t i; 

    p_op = (struct array_int*)xmalloc(sizeof(struct array_int)); 
    p_op->N = p_input_arr->N; 
    p_op->p_arr = (int*)xcalloc(p_op->N, sizeof(int)); 

    for(i = 0; i < p_op->N; ++i)
        p_op->p_arr[i] = p_input_arr->p_arr[p_op->N - i - 1]; 

    *pp_output_array = p_op; 

    return (SUCCESS); 
}

void test_get_reversed_array_1(void)
{
    int* p_arr = NULL; 
    size_t N = 8; 

    int* p_arr_r = NULL; 
    size_t rN = 0; 

    p_arr = get_input_array(N); 
    p_arr_r = get_reversed_array_1(p_arr, N, &rN); 
    show(p_arr, N, "Original array:"); 
    show(p_arr_r, rN, "Reversed array:"); 

    free(p_arr); 
    p_arr = NULL; 

    free(p_arr_r); 
    p_arr_r = NULL; 
}

void test_get_reversed_array_2(void)
{
    int* p_arr = NULL; 
    size_t N = 8; 
    
    int* p_arr_r = NULL; 
    size_t rN = 0; 

    status_t ret; 

    p_arr = get_input_array(N); 

    ret = get_reversed_array_2(p_arr, N, &p_arr_r, &rN); 
    assert(ret == SUCCESS); 

    show(p_arr, N, "Original array:"); 
    show(p_arr_r, rN, "Reversed array:"); 

    free(p_arr); 
    p_arr = NULL; 

    free(p_arr_r); 
    p_arr_r = NULL; 
}

void test_get_reversed_array_3(void)
{
    struct array_int* p_input = NULL; 
    struct array_int* p_output = NULL; 

    p_input = (struct array_int*)xmalloc(sizeof(struct array_int)); 
    p_input->N = 8; 
    p_input->p_arr = get_input_array(p_input->N); 

    p_output = get_reversed_array_3(p_input); 

    show(p_input->p_arr, p_input->N, "Original array:"); 
    show(p_output->p_arr, p_output->N, "Reversed array:"); 

    free(p_input->p_arr); 
    free(p_input); 
    p_input = NULL; 

    free(p_output->p_arr); 
    free(p_output); 
    p_output = NULL; 
}

void test_get_reversed_array_4(void)
{
    struct array_int* p_input = NULL; 
    struct array_int* p_output = NULL; 
    status_t ret; 

    p_input = (struct array_int*)xmalloc(sizeof(struct array_int)); 
    p_input->N = 8; 
    p_input->p_arr = get_input_array(p_input->N); 

    ret = get_reversed_array_4(p_input, &p_output); 
    assert(ret == SUCCESS); 

    show(p_input->p_arr, p_input->N, "Original array:"); 
    show(p_output->p_arr, p_output->N, "Reversed array:"); 

    free(p_input->p_arr); 
    free(p_input); 
    p_input = NULL; 

    free(p_output->p_arr); 
    free(p_output); 
    p_output = NULL; 
}

int* get_input_array(size_t N)
{
    int* p_arr = NULL; 
    size_t i; 

    p_arr = (int*)xmalloc(N * sizeof(int)); 
    for(i = 0; i < N; ++i)
        p_arr[i] = (i+1) * 10; 

    return (p_arr); 
}

void show(int* p_arr, size_t N, const char* msg)
{
    size_t i; 

    if(msg)
        puts(msg); 

    for(i = 0; i < N; ++i)
        printf("A[%llu]:%d\n", i, p_arr[i]); 

}

/* 
    @param1:    nr_bytes:size_t: size in bytes to be allocated on heap 
    @return:    void*: Base address of newly allocated block of memory allocated
                on heap
*/ 
void* xmalloc(size_t nr_bytes)
{
    void* p = NULL; 

    p = malloc(nr_bytes); 
    assert(p != NULL); 

    return (p); 
}

/* 
    @param1:    nr_elements: size_t: number of memory blocks of a type to be allocated 
                on heap 
    @param2:    size_per_element: size_t: size of each memory block 
    @return:    void*: base address of zeroed out block of contiguous bytes of size 
                nr_elements * size_per_element
*/ 
void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p = NULL; 

    p = calloc(nr_elements, size_per_element); 
    assert(p); 
    return (p); 
}

/*
    @param1:    old_ptr: void*: address of memory block to be resized. If NULL then 
                memory is allocated freshly 

    @param2:    new_size: size_t: desired size in bytes of memory block whose address 
                is in @param1 

    @return:    Base address of resized memory block. 
*/ 
void* xrealloc(void* old_ptr, size_t new_size)
{
    void* new_ptr = NULL; 

    new_ptr = realloc(old_ptr, new_size); 
    assert(new_ptr != NULL); 
    return (new_ptr); 
}