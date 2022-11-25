#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int my_array[7]={10,20,30,40};
    int i;
    int k=7;

    for(i=0; i<=k-1; i=i+1)
    {
        
        if(my_array[i]-4==36)
        {
            puts("Here it gone");
            continue;
        }
        printf("value of a[%d]=%d\n",i,my_array[i]);
    }
    exit(0);
}