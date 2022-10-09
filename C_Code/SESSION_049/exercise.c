#include <stdio.h> 
#include <stdlib.h> 

int i, j; 

int main(void)
{
    for(i = 1; i < 65; i = i * 2)
    {
        for(j = 100; j > 0; j = j / 2)
        {
            printf("i = %d, j = %d\n", i, j); 
        }
    }

    exit(0); 
}