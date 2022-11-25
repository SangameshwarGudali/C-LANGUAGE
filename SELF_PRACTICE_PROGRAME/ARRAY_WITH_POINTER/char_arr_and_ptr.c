#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    
    char arr[7];
    char* p;

    p = &arr[0];
    
    int i;
    puts("Get values from user by using pointer (p+i):");
    for(i=0; i<7; i=i+1)
    {
        puts("Enter the element for array: ");
        scanf("%s",(p+i));
    }

    puts("Printing elements in array by using pointer *(p+i):");
    for(i=0; i<7; i=i+1)
    {
        printf("array elements are arr[%d] = :%c\n",i,*(p+i));
    }

    exit(0);
}