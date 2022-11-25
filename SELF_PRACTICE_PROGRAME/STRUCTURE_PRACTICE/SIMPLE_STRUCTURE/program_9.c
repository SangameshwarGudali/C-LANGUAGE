#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct USER
{
    char* username;
    char* password;
}person1;



struct STUDENT_INFO
{
    char* name;
    int roll_no[25];
}student1;


int main(void)
{
    void sign_up(struct USER* ptr);
    void log_in(struct USER* ptr);
    void student_info();
    void home();

    struct USER* ptr;
    ptr = &person1;

    puts("Welcome to solapur university");
    sign_up(ptr);
    log_in(ptr);
    return(0);
}

void sign_up(struct USER* ptr)
{
    puts("Create usename");
    scanf("%s",(*ptr).username);
    puts("Create Password in numbers only");
    scanf("%s",(*ptr).password);

    return;
}

void log_in(struct USER* ptr)
{
    int value1;
    int value2;
    
    char entered_username[25];
    char entered_password[25];

    puts("\n\nEnter log in username");
    scanf("%s",&entered_username);
    puts("Enter log in Password");
    scanf("%s",&entered_password);

    value1 = strcmp(entered_username, (*ptr).username);
    value2 = strcmp(entered_password, (*ptr).password);
    printf("value1 = %d\n",value1);     
    printf("value2 = %d\n",value2);

    if(value1==0 && value2==0)
    {
        student_info();
    }
    else
    {
        puts("You entered wrong info");
    }
    

    
}

void student_info()
{
    puts("Enter your initial name");
    scanf("%s",student1.name);
    puts("Enter your Roll No");
    scanf("%d",student1.roll_no);
    return;
}

void home()
{
    int value=0;
    puts("1. Enter student Information");
    puts("2. close the application");
    scanf("%d",&value);

    if(value == 1)
    {
        student_info();
    }
}






