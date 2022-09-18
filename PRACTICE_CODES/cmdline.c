#include <stdio.h>
#include <stdlib.h>

/* argv[last_element] = NULL;*/
// argv last index is always set to NULL 

int main(int argc, char* argv[])
{
    int i;
    for(i = 0; i < argc; ++i)
        printf("argv[%d] = %s\n", i, argv[i]);
    return(0);
}