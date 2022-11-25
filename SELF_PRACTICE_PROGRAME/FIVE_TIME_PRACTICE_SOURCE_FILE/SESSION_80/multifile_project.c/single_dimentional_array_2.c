#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 6
void print_our_array(char arr[ARRAY_SIZE]);

int main(void)
{
    char arr[ARRAY_SIZE] = {'A', 'B', 'C', 'D', 'E', 'F'};

    print_our_array(arr);
    exit(0);
}

void print_our_array(char arr[ARRAY_SIZE])
{
    for(int i = 0; i < ARRAY_SIZE; ++i)
        printf("arr[%d] = %c\n", i, arr[i]);
}