#include <stdio.h> 
#include <stdlib.h> 

int main(void) 
{
    int snail; 
    int tortoise; 
    int rabbit; 

    for(snail = 0; snail <= 2; snail = snail + 1)
    {
        printf("snail step = %d\n", snail); 
        for(tortoise = 0; tortoise <= 3; tortoise = tortoise + 1)
        {   
            printf("\ttortoise step = %d\n", tortoise); 
            for(rabbit = 0; rabbit <= 4; rabbit = rabbit + 1)
            {
                printf("\t\trabbit step = %d\n", rabbit); 
            }
        }
    }

    exit(0); 
}

/* 
    int i, j, k; 
    Outermost loop : N1
    Middle loop : N2 
    Innernmost loop : N3 

    for(i = 0; i <= N1-1; i = i + 1)
    {
        // N1 
        for(j = 0; j <= N2-1; j = j + 1)
        {
            // N1 * N2 
            for(k = 0; k <= N3 - 1; k = k + 1)
            {
                // N1 * N2 * N3 
            }
        }
    }
--------------------------------------------------
    for(i = 0; i < N1; i = i + 1)
    {
        // N1 
        for(j = 0; j < N2; j = j + 1)
        {
            // N1 * N2
            for(k = 0; k < N3; k = k + 1)
            {
                // N1 * N2 * N3
            }
        }
    }

*/ 

/*  
    for(i = 1; i <= 5; i = i+1)

    for(i = 0; i <= 4; i = i + 1)

    for(i = 0; i < 5; i = i + 1)
*/ 
