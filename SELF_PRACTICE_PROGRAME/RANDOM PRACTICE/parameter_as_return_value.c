#include <stdio.h>
#include <stdlib.h>

void fill_box(int* fetch_box);

int main(void)
{                                                                                 

    int empty_box = 0;
    fill_box(&empty_box);

    printf("empty box = %d\n", empty_box);

    return(0);
}

void fill_box(int* fetch_box)
{
    *fetch_box = 100;
}