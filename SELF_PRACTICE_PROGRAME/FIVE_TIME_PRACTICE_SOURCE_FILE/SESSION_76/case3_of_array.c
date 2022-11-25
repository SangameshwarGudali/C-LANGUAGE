#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int i;

void set_values(int** ptr, int size);
void get_values(int* p, int size);

int main(void)
{
    int* p = 0;
    int size = 0;
    puts("Enter the size of array");
    scanf("%d", &size);
    
    set_values(&p, size);
    get_values(p, size);

    free(p);
    p = 0;

    exit(EXIT_SUCCESS);
}

void set_values(int** pp, int size)
{
    int* set_ptr = 0;
    set_ptr = malloc(size*sizeof(int));
    assert(set_ptr != 0);

    for(i=0; i<size; i++)
    {
        *(set_ptr + i) = i*200;
    }

    *pp = set_ptr;
    return;
}

void get_values(int* p, int size)
{
    for(i=0; i<size; i++)
    {
        printf("arr[%d] = %d\n", i, *(p + i));
    }
    return;
}