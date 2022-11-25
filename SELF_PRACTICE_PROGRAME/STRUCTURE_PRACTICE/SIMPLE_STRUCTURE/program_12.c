#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct USER
{
    char username[25];
    char password[25];
};

struct STUDENT_INFO
{
    char student_name[30];
    int student_roll_no;
    char student_department[20];
    unsigned long long student_mobile_no;
    char student_mail_id[30];
    int student_fees_paid;

};

struct ADMIN_INFO
{
    char admin_name[25];
    unsigned long long int admin_mobile_no;
    char admin_mail_id[25];
}admin1;

int main(void)
{
    void sign_up(struct USER* usr_ptr, struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr);
    void student_log_in(struct USER* usr_ptr, struct STUDENT_INFO* sdt_ptr);
    void admin_log_in(struct USER* usr_ptr, struct ADMIN_INFO* admin_ptr);
    void student_info(struct STUDENT_INFO* sdt_ptr);
    void admin_info(struct ADMIN_INFO* admin_ptr);
    void home( struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr);
    void print_student_info(struct STUDENT_INFO* sdt_ptr);

    struct USER user;
    struct USER* usr_ptr;
    usr_ptr = &user;

    struct STUDENT_INFO student1;
    struct STUDENT_INFO* sdt_ptr;
    sdt_ptr = &student1;

    struct ADMIN_INFO* admin_ptr;
    admin_ptr = &admin1;

    sign_up(usr_ptr,sdt_ptr,admin_ptr); 

    exit(0);

}

void sign_up(struct USER* usr_ptr, struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr)
{
    int value;

    puts("------------------------------------------ SIGN UP -----------------------------------------");
    printf("If you are Student Enter 1:\n");
    printf("If you are Admin Enter 2:\n");
    scanf("%d",&value);

    if(value == 1)
    {
        student_log_in(usr_ptr, sdt_ptr);
    }
    else if(value == 2)
    {
        admin_info(admin_ptr);
    }

    printf("\t Create your username:->\t");
    scanf("%s",(*usr_ptr).username);
    printf("\t Create your Password:->\t");
    scanf("\t%s",(*usr_ptr).password);

}

void student_log_in(struct USER* usr_ptr, struct STUDENT_INFO* sdt_ptr)
{
    
    int value1, value2, choice;

    char entered_username[25];
    char entered_password[25];

    puts("------------------------------------------ LOG IN ------------------------------------------");
    
    scanf("%d",&choice);

    printf("Enter username:->\t");
        scanf("%s", &entered_username);
        printf("Enter password:->\t");
        scanf("%s", &entered_password);

        value1 = strcmp((*usr_ptr).username, entered_username);
        value2 = strcmp((*usr_ptr).password, entered_password);


        if((value1 == 0) &&  (value2 == 0))
        {
            puts("\t\t\t  ----------------------");
            puts("\t\t\t | Entered Sucessfully: |");
            puts("\t\t\t  ----------------------");
            student_info(sdt_ptr);
        }
        else
        {
            puts("Please check your user id and password:");
        }


}
void admin_log_in(struct USER* usr_ptr, struct ADMIN_INFO* admin_ptr)
{
    int value1, value2, choice;

    char entered_username[25];
    char entered_password[25];

    puts("------------------------------------------ LOG IN ------------------------------------------");
    
    scanf("%d",&choice);

    printf("Enter username:->\t");
        scanf("%s", &entered_username);
        printf("Enter password:->\t");
        scanf("%s", &entered_password);

        value1 = strcmp((*usr_ptr).username, entered_username);
        value2 = strcmp((*usr_ptr).password, entered_password);


        if((value1 == 0) &&  (value2 == 0))
        {
            puts("\t\t\t  ----------------------");
            puts("\t\t\t | Entered Sucessfully: |");
            puts("\t\t\t  ----------------------");
            admin_info(admin_ptr);
        }
        else
        {
            puts("Please check your user id and password:");
        }
}



void admin_info(struct ADMIN_INFO* admin_ptr)
{
    puts("----------------------------------------- ADMIN INFO ----------------------------------------------");
    printf("Enter your initial name :- ");
    scanf("%s",(*admin_ptr).admin_name);
    printf("Enter your Mobile No.   :");
    scanf("%llu",&(*admin_ptr).admin_mobile_no);
    printf("Enter your Mail-id      :");
    scanf("%s",(*admin_ptr).admin_mail_id);
    
    
}


void student_info(struct STUDENT_INFO* sdt_ptr)
{
    puts("------------------------------------ STUDENT INFORMATION -----------------------------------------");
    printf("Enter your initial name :- ");
    scanf("%s",(*sdt_ptr).student_name);
    printf("Enter your Roll No      :- ");
    scanf("%d",&(*sdt_ptr).student_roll_no);
    printf("Department              :");
    scanf("%s",(*sdt_ptr).student_department);
    printf("Enter your Mobile No.   :");
    scanf("%llu",&(*sdt_ptr).student_mobile_no);
    printf("Enter your Mail-id      :");
    scanf("%s",(*sdt_ptr).student_mail_id);
    printf("Paid Amount             :");
    scanf("%d",&(*sdt_ptr).student_fees_paid);
    return;
}

void print_student_info(struct STUDENT_INFO* sdt_ptr)
{
    printf("%s\n,%d\n,%s\n,%llu\n,%s\n,%d\n",(*sdt_ptr).student_name,
                                (*sdt_ptr).student_roll_no,
                                (*sdt_ptr).student_department,
                                (*sdt_ptr).student_mobile_no,
                                (*sdt_ptr).student_mail_id,
                                (*sdt_ptr).student_fees_paid);
}

void home( struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr)
{
    int value;

    puts("------------------------------------------- HOME ----------------------------------------");
    puts("Enter 1: See student Rocords");
    puts("Enter 2: Edit student Detials");
    puts("Enter 3: Login page");

    scanf("%d",&value);

    /*switch(value)
    {
        case 1:
            print_student_info(struct STUDENT_INFO* sdt_ptr);
            break;
        case 2:
            student_info();
            break;
        default :
            printf("You not entered any valid input");

    }
    */

    if (value == 1)
    {
        print_student_info(sdt_ptr);
    }
    else if(value == 2)
    {
        student_info(sdt_ptr);
    }
}





