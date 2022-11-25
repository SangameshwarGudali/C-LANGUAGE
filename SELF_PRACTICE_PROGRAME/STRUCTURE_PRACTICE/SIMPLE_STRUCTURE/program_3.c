#include <stdio.h>
#include <stdlib.h>

struct EMPLOYEE
{
    char* name;
    unsigned long long mobile_no;
    char* qualification;
};



int main(void)
{
    struct EMPLOYEE employee;
    struct EMPLOYEE arr[2];

    int i=0; 
    while(i<2)
    {
        printf("enter the name of employee\n");
        scanf("%s",arr[i].name);
        printf("Enter the mobile no.\n");
        scanf("%llu",&arr[i].mobile_no);
        printf("Enter qualification of employee\n");
        scanf("%s",arr[i].qualification);
        i++;
    }

    puts("The Employee detials are \n");
    for(i=0; i<2; i++)
    {
        printf("%s\n",arr[i].name);
        printf("%llu\n",arr[i].mobile_no);
        printf("%s\n",arr[i].qualification);
    }


    exit(0);
}