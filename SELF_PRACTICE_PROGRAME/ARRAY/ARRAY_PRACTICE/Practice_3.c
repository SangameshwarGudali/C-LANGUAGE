#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int marks[5];
    marks[0]=45;
    marks[1]=54;
    marks[2]=56;
    marks[3]=66;
    marks[4]=87;

    printf("%d\n",marks[0]);
    printf("%d\n",marks[1]);
    printf("%d\n",marks[2]);
    printf("%d\n",marks[3]);
    printf("%d\n",marks[4]);

    int score[6];

    int index;

    for(index=0; index <= 5; index = index +1)
    {   
        printf("Enter value of score : ");
        scanf("%d",&score[index]);
    }
    
    for(index = 0; index <= 5; index = index +1)
    {
        printf("score=%d\n",score[index]);
    }

    exit(0);
}