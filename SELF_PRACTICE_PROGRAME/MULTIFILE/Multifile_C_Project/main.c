#include "header.h"

int main(void)
{
    int dd, mm, yy;
    struct Date* ptr = NULL;

    ptr = create_date(2, 6 , 2015);
    printf("date = %d-%d-%d\n", ptr -> day, ptr -> month, ptr -> year);

    free(ptr);
    ptr = NULL;

    return(0);
}