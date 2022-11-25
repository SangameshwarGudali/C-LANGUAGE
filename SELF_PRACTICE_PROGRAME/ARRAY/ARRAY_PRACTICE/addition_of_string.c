#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char name[]={"s,a,n,g,a,m,e,s,h,w,a,r"};
    char surname[]={"g,u,d,a,l,i"};
    
    char full_name[44];
    int index;
    index=0;
    while(index <= 44)
    {
        full_name[index]= name[index] + surname[index];
        index = index + 1;
    }

    for(index=0; index <= 44; index = index +1)
    {
        printf("full_name %s",full_name);
    }
   

    exit(0);
}