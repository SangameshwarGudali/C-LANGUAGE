#include <stdio.h>
#include <stdlib.h>

struct Notebook
{
    char name[20];  // 20
    int pages;      // 4
    int mrp;        // 4
};                      

int main(void)
{
    struct Notebook note;
    printf("Enter the Notebook information\n");
    printf("Enter the name of notebook\n");
    scanf("%s",note.name);
    printf("Enter how many pages are in notebook\n");
    scanf("%d",&note.pages);
    printf("Enter the price of notebook\n");
    scanf("%d",&note.mrp);

    printf("The detials of notebook are %s,%d,%d",note.name,note.pages,note.mrp);
    exit(0);
}

