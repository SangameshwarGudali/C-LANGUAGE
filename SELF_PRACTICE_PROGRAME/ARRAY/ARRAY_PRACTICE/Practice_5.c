#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float fa[11];

    int index;

    index = 0;
    while(index < 11)
    {
        puts("Enter the value of array");
        scanf("%f",&fa[index]);
        index = index + 1;
    }


    for(index =0; index <11; index = index + 1)
    {
        printf("elemrnt : %f\n",fa[index]);
    }

exit(0);


   

}