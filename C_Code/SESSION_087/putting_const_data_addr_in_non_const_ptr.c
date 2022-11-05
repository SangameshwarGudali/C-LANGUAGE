#include <stdio.h> 
#include <stdlib.h> 

const int gc_num = 700; 

int main(void)
{
    int* ptr;   /* ptr is a read write pointer to read write integer */ 
    const int lc_num = 300; 

    // lc_num = 400;    // compile time error
                        // lvalue cannot be a const expr 
    ptr = &lc_num;  
    /*  
    Compile time warning: 
    discarding const qualifier 
    What is the issue? 

    type(lc_num) = const int
    type(&lc_num) = const int* 
    type(ptr) = int* 

    Type mismatch. 

    This type mismatch was also present in 
    int n; 
    const int* p; 
    p = &n; 

    But in this mismatch we couldn't perform any operation 
    on 'n' through p which data type of 'n' did not support 
    Therefore, compiler does the IMPLICIT CONVERSION 
    of int*(type of RHS) to const int*(type of LHS)
    */ 

    printf("lc_num = %d\n", lc_num); 
    *ptr = 500; 
    printf("lc_num = %d\n", lc_num); 

    printf("gc_num = %d\n", gc_num); 
    ptr = &gc_num; 
    *ptr = 7000; 
    printf("gc_num = %d\n", gc_num); 
    puts("End of program"); 
    
    exit(0); 
}