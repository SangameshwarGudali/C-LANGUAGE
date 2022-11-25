#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float ch[5];

    float index;
    index = 0;
    while(index <= 4)
    {
        printf("Enter the value of ch : \n");
        scanf("%f", &ch[index]);
        index = index + 1;
    }

    for(index = 0; index <5; index = index + 1)
    {
        printf("Entered values are %f\n", ch[index]);
    }


    exit(0);
}