#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int snail, tortoise, rabbit;

    for(snail=0; snail<2; snail++)
    {
        printf("snail step = %d\n", snail);
        for(tortoise=0; tortoise<3; tortoise++)
        {
            printf("\ttortoise step = %d\n", tortoise);
            for(rabbit=0; rabbit<4; rabbit++)
            {
                printf("\t\trabbit step = %d\n", rabbit);
            }
        }
    }

    exit(0);
}