#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int i = 0; 
    while(i < 5){
        printf("arr[%d] = %d\n", i, arr[i]);
        i = i + 1;
    }
        

    return(0);
}