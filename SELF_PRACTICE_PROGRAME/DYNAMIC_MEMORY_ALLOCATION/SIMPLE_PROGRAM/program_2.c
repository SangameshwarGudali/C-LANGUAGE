#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* arr = 0;

    arr = malloc(5 * sizeof(int));

    if(arr == 0)
    {
        puts("memory allocation failed");
        exit(-1);
    }

    

    int i=0;
    for(i=1; i<5; i++)
    {
        *(arr + i) = i*100;
    }

    for(i=1; i<5; i++)
    {
        printf("%d\n",*(arr+i));
    }

    free(arr);
    exit(0);
}