#include <stdio.h>
#include <stdlib.h>

struct STUDENT
{
    char* name;
    int roll_no;
    char division;
}student;

int main(void)
{
    struct STUDENT* ptr;

    struct STUDENT student[5];

    int i;
    for(i=0; i<5; i++)
    {
        printf("Enter name of student\n");
        scanf("%s",student[i].name);
        printf("Enter roll no.\n");
        scanf("%d",&student[i].roll_no);
        printf("Enter student divsion\n");
        scanf("%c",&student[i].division);
    }

    return(0);
}