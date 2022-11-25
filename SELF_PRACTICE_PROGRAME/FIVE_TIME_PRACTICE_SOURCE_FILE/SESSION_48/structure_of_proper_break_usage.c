#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    puts("continue use in for loop");
    for(i=0; i<10; i++)
    {
        if(i == 6)
        {
            puts("here we are going to skip");
            break;
            puts("check here");
        }
        printf("down value = %d\n", i);
        
    }

    puts("\n\n continue use in while loop");

    i = 0;
    while(i < 10)
    {
        printf("hello %d\n",i);
        if(i % 5 == 0)
        {
            i = i +1;
            continue;
        }
        printf("down %d\n", i);
        i = i +1;
        
    }

    exit(0);
    
}