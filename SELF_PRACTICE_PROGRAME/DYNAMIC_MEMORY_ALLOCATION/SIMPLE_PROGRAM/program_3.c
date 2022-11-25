#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int* p = 0;
    int size;

    puts("Enter the array size");
    scanf("%d",&size);

    p = malloc(size * sizeof(int));

    if(p == 0)
    {
        puts("memory not allocated");
        exit(-1);
    }

    int i, ans=0, temp=0;
    for(i=0; i<size; i++)
    {
        printf("Enter the value for index[%d]",i);
        scanf("%d",&(*(p+i)));
    }

    for(i=0; i<size; i++)
    {
        printf("%d\n",*(p+i));
        temp = *(p+i);
        ans = ans + temp;
    }
    printf("final value = %d",ans);

    free(p);
    exit(0);
}