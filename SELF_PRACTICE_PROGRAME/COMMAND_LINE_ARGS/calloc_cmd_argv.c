#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    int numberOfElements = 0;
    size_t N = 0;
    int *arr = NULL;
    int i = 0;

    if (argc != 2)
    {
        printf("UsageError: Correct Usage: %s numberOfElements \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    numberOfElements = atoi(argv[1]);
    printf("you are entering %d size for allocate memory\n", numberOfElements);

    if(numberOfElements <= 0)
    {
        puts("invalid input, array size could not be 0 and negetive");
        exit(EXIT_FAILURE);
    }

    arr = (int *)calloc(numberOfElements, sizeof(int));
    assert(arr != 0);

    N = numberOfElements;
    for (i = 0; i < N; ++i)
        *(arr + i) = 10 * (i + 1);

    for (i = 0; i < N; ++i)
        printf("arr[%d] = %d\n", i, *(arr + i));

    free(arr);
    arr = NULL;

    return (0);
}