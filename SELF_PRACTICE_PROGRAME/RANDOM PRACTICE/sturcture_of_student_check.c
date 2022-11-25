#include <stdio.h>
#include <stdlib.h>
int main(void)
{ 
struct STUDENT
{
    char name[15];
    char address[30];
    int roll_no;
    char email[20];
    int mobile_no;
};

struct STUDENT std;
    struct STUDENT *ptr;
     ptr= &std; 
    int i;
    int rl_no;
    
    void display_all_records(void);

    printf("\t Enter the student information");

    for(i=0; i<3; i++)
    {
        printf("\nEnter the name :");
        scanf("%s",&ptr->name);
        printf("\n Enter Address  :");
        scanf("%s",&ptr->address);
        printf("\n Enter roll no. :");
        scanf("%d",&ptr->roll_no);
        printf("\n Enter Mobile No:");
        scanf("%d",&ptr->mobile_no);
    }


        printf("%s\n",ptr->name);
        printf("%s\n",ptr->address);
        printf("%d\n",ptr->mobile_no);
    return 0;
}