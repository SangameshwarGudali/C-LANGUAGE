#include <stdio.h>
#include <stdlib.h>

int main()
{
    int time;
    char string_result[20];
    printf("Enter the value of time ");
    scanf("%d",&time);
    if (time==20)
    {
        printf("good monrning");
    }
    else
    {
        printf("Good evening");
    }
    exit(0);
}