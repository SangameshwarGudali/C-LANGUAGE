/* 
    allocate array of integers using malloc() 
    function. 

    Write, 
    100 on index 0 element 
    200 on index 1 element 
    300 on index 2 element 
    400 on index 3 element 
    500 on index 4 element 

    Show the array in indexwise fashion     
    on standard output device 

    free  the array. 
*/ 

#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int* p_arr = 0; /*  p_arr is a pointer to integer 
                        But we are not going to store the 
                        address of isolated integer in it. 
                        We are going to store address of first 
                        integer of array in it. 
                        Therefore, though this is a pointer to 
                        integer, it works as pointer to array 
                        for us! 
                    */ 
    int size_of_array = 5; 
    int i; 
    /* The following line will allocate 20 bytes of 
        contiguous memory in the heap section of the 
        process and return the address of the first 
        byte (which is address of first byte of 
        first integer in the array i.e. base address 
        of array) 
    */
    p_arr = malloc(size_of_array * sizeof(int)); 
    if(p_arr == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    /*  At this point we are sure that malloc() has     
        succeeded in allocating memory to array. 
        And the p_arr contanins the base address of 
        array. 

        p_arr + i = address of element at index i in array 
        *(p_arr + i) can be used to read / write element 
        at index i in array. 

        It is OUR (= PROGRAMMER'S) responsibility to make sure 
        that the value of 'i' remains between 0 to size_of_array - 1
        Because that is the valid index range of array of ANY given size! 
    */ 

    for(i = 0; i < size_of_array; ++i)
        *(p_arr+i) = (i+1) * 100; 

    for(i = 0; i < size_of_array; ++i)
        printf("*(p_arr + %d) = %d\n", i, *(p_arr + i)); 

    free(p_arr);    /*  Note that the free() accesses the table 
                        maintained by malloc() and therefore
                        it comes to know that the block of 20 bytes 
                        is pointed by p_arr, we need not send 20 
                        as a parameter to free() 
                    */ 
    p_arr = 0; 

    exit(0); 
}
 
