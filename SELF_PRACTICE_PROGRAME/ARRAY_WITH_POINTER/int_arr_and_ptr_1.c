#include <stdio.h>
#include <stdlib.h>

int i;
int j;

int main(void)
{
    int arr[]={10,20,30,40,50};
    int* p;

    puts("Printing the address of all elements in array arr[]");
    
    for(i=0; i<5; ++i)
    {
        printf("Address of elenemt at %d index of arr = %llu\n", i,(unsigned long long)&arr[i]);
    }

    p = &arr[0];
    puts("Print the addresses: p+0, p+1, p+2, p+3, p+4");
    
    for(i=0; i<5; ++i)
    {
        printf("Address of element at %d index of arr = %llu\n", i,(unsigned long long)(p+i));
    }

    puts("Accessing array elements by dereferencing:p+0, p+1, p+2, p+3, p+4"); 
    int tmp;
    for(i=0; i<5; i++)
    {
        tmp = *(p+i);
        printf("value in arr[%d] = %d\n", i,tmp);
    }

    puts("Modifying array elements by dereferencing:p+0, p+1, p+2, p+3, p+4:");
    for(i=0; i<5; i++)
    {
        *(p+i) = i+1*5000;
    }
    
    puts("Accessing array elements by dereferencing:p+0, p+1, p+2, p+3, p+4"); 
    for(i=0; i<5; i++)
    {
        tmp = *(p+i);
        printf("Element at arr[%d] = %d\n", i, tmp);
    }

    exit(0);


}