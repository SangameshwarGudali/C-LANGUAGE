#include <stdio.h> 
#include <stdlib.h> 

short s_arr[5] = {100, 200, 300, 400, 500}; 
short* p; 
short tmp; 
int i; 


int main(void)
{
    puts("Printing the addresses of all elements of array s_arr:"); 
    for(i = 0; i < 5; ++i)
        printf("Address of element at %d index of s_arr = %llu\n", 
                i, (unsigned long long int)&s_arr[i]); 

    /* assign address of element at index 0 to p */ 
    p = &s_arr[0]; 

    puts("Print the addresses:p+0, p+1, p+2, p+3, p+4:"); 
    for(i = 0; i < 5; ++i)
        printf("p + %d = %llu\n", i, (unsigned long long int)(p+i)); 

    puts("Accessing array elements by dereferencing:p+0, p+1, p+2, p+3, p+4"); 
    for(i = 0; i < 5; ++i)
    {
        tmp = *(p+i); /* tmp = s_arr[i]; */ 
        printf("Element at index %d = %hd\n", i, tmp); 
    }

    puts("Modifying array elements by dereferencing:p+0, p+1, p+2, p+3, p+4:"); 
    for(i = 0; i < 5; ++i)
    {
        *(p+i) = (i+1) * 1000; 
    }

    puts("Accessing array elements by dereferencing:p+0, p+1, p+2, p+3, p+4"); 
    for(i = 0; i < 5; ++i)
    {
        tmp = *(p+i); 
        printf("Element at index %d = %hd\n", i, tmp); 
    }
    
    exit(0); 

}