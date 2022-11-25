#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //Declare a pointer to array of 5 int 
    int arr[5] = {10, 20, 30, 40, 50};

    int (*ptr)[5] = &arr;

    int i = 0; 
    while(i < 5){
        printf("(*ptr)[%d] = %d\n", i, (*ptr)[i]);
        i = i + 1;
    }

    return(0);
}