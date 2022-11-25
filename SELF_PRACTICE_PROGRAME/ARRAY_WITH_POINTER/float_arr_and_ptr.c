#include <stdio.h>
#include <stdlib.h>

int i;

int main(void)
{
    float arr[5];
    float* p;

    p = &arr[0];

    for(i=0; i<5; i=i+1)
    {
        printf("Enter [%d]th index value for arr\n", i);
        scanf("%f",(p+i));
    }

    for(i=0; i<5; i++)
    {
        printf("Address of the arr[%d] = %llu\n" , i,(unsigned long long)(p+i));
    }
    printf("\n\n");

    for(i=0; i<5; ++i)
    {
        printf("Elements in array are %f\n",*(p+i));
    }

    exit(0);

}