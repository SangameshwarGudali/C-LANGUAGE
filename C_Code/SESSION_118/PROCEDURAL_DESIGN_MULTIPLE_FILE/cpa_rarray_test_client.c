#include "cpa_rarray_test_suite.h"

#ifndef EXIT_SUCCESS 
#define EXIT_SUCCESS 0
#endif 

int main(void)
{
    test_get_reversed_array_1(); 
    test_get_reversed_array_2(); 
    test_get_reversed_array_3(); 
    test_get_reversed_array_4(); 

    return (EXIT_SUCCESS); 
}