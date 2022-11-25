#include <stdio.h>
#include <stdlib.h>

struct BOOK
{
    char* name;
    int pages;
    float price;
};

struct BOOK book[2];

int main(void)
{

    printf("We are inside the main\n");

    int i;
    for(i=0; i<2; i++)
    {
        printf("Enter name\n");
        scanf("%s",book[i].name);
        printf("Enter Pages\n");
        scanf("%d",&book[i].pages);
        printf("Enter price\n");
        scanf("%f",&book[i].price);
    }

    return(0);
}