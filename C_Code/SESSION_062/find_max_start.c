#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    int A[8] = {100, 20, 400, 23, 500, 67, -30, 1000}; 
    int N = 8; 

    int index; 
    int current_max; 

    /* Step 1 */ 
    current_max = A[0]; 
    index = 1; 
    
    /* Step 2 */ 
    while(index < N)
    {
        if(A[index] > current_max)
            current_max = A[index]; 
        index = index + 1; 
    }

    printf("Maximum in array = %d\n", current_max); 

    exit(0); 
}