#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int j;
    int return_value;
    printf("Enter the value\n");
    scanf("%d",&j);

    return_value = (j == 555) ? (100) : (200);

    printf("%d",return_value);

    exit(0);
}