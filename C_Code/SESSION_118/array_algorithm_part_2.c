Problem 1: 
    min element of array of integer
    max element of array of integer 
#----------------------------------------
Problem 2: Subarray return 
        Array from index i to index j-1 
        duplicate and return 

        i to j -> range of array 
        i to j - 1
#----------------------------------------

Min/Max 

int min_max(int* p_arr, size_t N, int* p_min); 
int min_max(int* p_arr, size_t N, int* p_max); 

status_t min_max(int* p_arr, size_t N, int* p_min, int* p_max); 

struct output
{
    int max; 
    int min; 
}; 

struct output* min_max(int* p_arr, size_t N); 
status_t min_max(int* p_arr, size_t N, struct output** pp_output); 



int* subarray(int* p_arr, size_t N, size_t i, size_t j, size_t* p_subarray_length); 
status_t subarray(int* p_arr, size_t N, size_t i, size_t j, int** pp_arr, size_t* p_subarray_length); 

struct array_int
{ 
    int* p_arr; 
    size_t N; 
}; 

struct array_int* subarray(struct array_int* p_input_arr, size_t i, size_t j); 
status_t subarray(struct array_int* p_arr, size_t i, size_t j, struct array_int** pp_out); 

T1 op1, T2 op2, ... Tk opk 

status_t function_name(INPUT PARAM, T1* p1, ... , Tk* pk); 

struct output
{
    T1 op1; 
    T2 op2; 

    Tk opk; 
}; 

status_t function_name(INPUT PARAMS, struct output** pp_output); 