#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[10] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int i;
    int N = 10;

    puts("Using While loop");
    i = 0;
    while(i < 10)
    {
        if((arr[i] % 7) == 0)
        {
            i = i + 1;
            continue;
        }
        printf("arr[%d]: %d\n", i, arr[i]);
        i = i + 1;
    }

    puts("uaing for loop");
    for(i=0; i<10; i=i+1)
    {
        if((arr[i] % 7) == 0)
        {
            continue;
        }
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    exit(0);
}