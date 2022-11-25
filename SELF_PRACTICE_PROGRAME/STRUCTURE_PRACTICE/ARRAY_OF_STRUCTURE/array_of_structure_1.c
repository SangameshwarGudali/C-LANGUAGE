#include <stdio.h>
#include <stdlib.h>

 int i;

struct DATE
{
    int day;
    int month;
    int year;
}date;

struct DATE arr[4];
/*struct DATE arr[4]= {
    {
        5,
        "JANUARY",
        2018
    },
    {
        15,
        "FEBRUARY",
        2019
    },
    {
        19,
        "FEBRUARY",
        2022
    }
};
*/
int main(void)
{
    for(i=0; i<4; ++i)
    {
        puts("Enter day:");
        scanf("%d",&arr[i].day);
        puts("Enter month");
        scanf("%d",&arr[i].month);
        puts("Emter year");
        scanf("%d",&arr[i].year);
    }

   
    for(i=0; i<4; ++i)
    {
        printf("arr[%d] = %d\n",i, arr[i].day);
        printf("arr[%d] = %d\n", i, arr[i].month);
        printf("arr[%d] = %d\n", i, arr[i].year);
    }

    for(i=0; i<4; i++)
    {
        printf("%d - %d - %d\n",arr[i].day,arr[i].month,arr[i].year);
    }

    exit(0);
}
