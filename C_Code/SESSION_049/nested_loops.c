#include <stdio.h> 
#include <stdlib.h> 

/* Example 1 */ 
int main(void)
{
    int i; 
    int j; 

    for(i = 0; i <= 3; i = i + 1)
    {
        for(j = 0; j <= 2; j = j + 1)
        {
            printf("i = %d, j = %d\n", i, j); 
        }
    }

    exit(0); 
}

/* 
for to while conversion 
int main(void)
{
    int i; 
    int j; 

    i = 0; 
    while(i <= 3)  
    {
        j = 0; 
        while(j <= 2) 
        {
            j = j + 1; 
        }

        i = i + 1; 
    }
}
--------------------------------------

/* 
    i = 0; -> i == 0 
    COND: i <= 3: 0 <= 3: TRUE  
            j = 0; j == 0  
            COND: j <= 2: 0 <= 2: TRUE
                printf("i = %d, j = %d\n", i, j); OP i = 0, j = 0
                j = j + 1
            j == 1 
            COND: j <= 2: 1 <= 2: TRUE
                printf("i = %d, j = %d\n", i, j); OP i = 0, j = 1 
                j = j + 1 
            j == 2
            COND: j <= 2: 2 <= 2: TRUE 
                printf("i = %d, j = %d\n", i, j); OP i = 0, j = 2 
                j = j + 1
            j == 3
            COND: j <= 2:  3 <= 2: FALSE
        i = i + 1 
    i == 1: i <= 3: 1 <= 3: TRUE 
            j = 0; j == 0 
            COND: j <= 2: 0 <= 2: TRUE 
                printf("i = %d, j = %d\n", i, j); OP i = 1, j = 0
                j = j + 1 
            j == 1: j <= 2: 1 <= 2: TRUE 
                printf("i = %d, j = %d\n", i, j); OP i = 1, j = 1
                j = j + 1 
            j == 2: j <= 2: 2 <= 2: TRUE 
                printf("i = %d, j = %d\n", i, j); OP i = 1, j = 2
                j = j + 1 
            j == 3: j <= 2: 3 <= 2: FALSE
        i = i + 1
    i == 2: i <= 3: 2 <= 3: TRUE 
            j = 0: j == 0
            COND: j <= 2: 0 <= 2: TRUE: 
                printf("i = %d, j = %d\n", i, j); OP i = 2, j = 0 
                j = j + 1
            j == 1: j <= 2: 1 <= 2: TRUE 
                printf("i = %d, j = %d\n", i, j); OP i = 2, j = 1
                j = j + 1
            j == 2: j <= 2: 2 <= 2: TRUE 
                printf("i = %d, j = %d\n", i, j); OP i = 2, j = 2 
                j = j + 1
            j == 3: j <= 2: 3 <= 2: FALSE 
        i = i + 1 
    i == 3: i <= 3: 3 <= 3 TRUE 
            j = 0: j == 0
            COND: j <= 2: 0 <= 2: TRUE
                printf("i = %d, j = %d\n", i, j); OP i = 3, j = 0 
                j = j + 1 
            j == 1: j <= 2: 1 <= 2: TRUE 
                printf("i = %d, j = %d\n", i, j); OP i = 3, j = 1 
                j = j + 1 
            j == 2: j <= 2: 2 <= 2: TRUE 
                printf("i = %d, j = %d\n", i, j); OP i = 3, j = 2 
                j = j + 1
            j == 3: j <= 2: 3 <= 2: FALSE 
        i = i + 1
    i == 4: i <= 3: 4 <= 3: FALSE 
exit(0); 
*/ 


