#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char bucket[5];
    char* mug;

    mug = &bucket[0];
    int i;
    for(i=0; i<5; i=i+1)
    {
        puts("Enter the characters for filling bucket");
        scanf("%s",(mug+i));
    }

    for(i=0; i<5; i=i+1)
    {
        printf("Characters in bucket[%d] = %c \n", i,*(mug+i));
    }

    exit(0);
}