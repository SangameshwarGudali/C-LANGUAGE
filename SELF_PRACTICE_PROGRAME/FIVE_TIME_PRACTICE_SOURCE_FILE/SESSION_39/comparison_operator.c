#include <stdio.h>
#include <stdlib.h>

int num_1;
int num_2;
int ans;

int main(void)
{
    printf("Enter the value for num_1\n");
    scanf("%d",&num_1);

    printf("Enter the value for num_2\n");
    scanf("%d",&num_2);

    ans = (num_1 > num_2);
    printf("num_1 > num_2 = %d\n", ans);

    ans = (num_1 >= num_2);
    printf("num_1 >= num2 = %d\n", ans);

    ans = (num_1 < num_2);
    printf("num_1 < num_2 = %d\n", ans);

    ans = (num_1 <= num_2);
    printf("num_1 <= num2 = %d\n",ans);

    ans = (num_1 == num_2);
    printf("num_1 == num_2 = %d\n", ans);

    ans = (num_1 != num_2);
    printf("num_1 != num_2 = %d\n",ans);


    exit(0);
}