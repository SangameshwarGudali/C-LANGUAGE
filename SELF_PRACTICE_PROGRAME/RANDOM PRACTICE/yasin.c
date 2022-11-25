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

struct STUDENT_INFO arr[20];
int student_records;

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
    void student_info(struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr);
    void admin_info(struct USER* usr_ptr, struct ADMIN_INFO* admin_ptr);
    void STUDENT_HOME( struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr);
    void print_student_info(struct STUDENT_INFO* sdt_ptr);
    void intitial_display_page();
    void admin_access_student_info();
    void admin_home();
    void admin_access_student_info_print();
    void remaining_fees(struct STUDENT_INFO arr[20]);
    


    struct USER user;
    struct USER* usr_ptr;
    usr_ptr = &user;

    struct STUDENT_INFO student1;
    struct STUDENT_INFO* sdt_ptr;
    sdt_ptr = &student1;

    struct ADMIN_INFO* admin_ptr;
    admin_ptr = &admin1;

    intitial_display_page();
    sign_up(usr_ptr,sdt_ptr,admin_ptr); 
    //STUDENT_HOME(sdt_ptr,admin_ptr);
    //STUDENT_HOME(sdt_ptr,admin_ptr);

    exit(0);

}

void intitial_display_page()
{
    int choice;

    puts("------------------------------------------------------------------------------------------------------------------------------------");
    puts("|                                                   WELCOME TO SOLAPUT UNIVERSITY DEPARTMENT                                       |");
    puts("------------------------------------------------------------------------------------------------------------------------------------\n");

    puts("\t\t\t\t\t\t\t\t\t\t\t\t1. SIGN UP");
    puts("\t\t\t\t\t\t\t\t\t\t\t\t2. LOG IN");
    puts("\t\t\t\t\t\t\t\t\t\t\t\t3. STUDENT_HOME MENUE");
    puts("\t\t\t\t\t\t\t\t\t\t\t\t4. EXIT");
    scanf("%d",&choice);

    if(choice == 1)
    {
        return;
    }
    else if((choice == 2) || (choice == 3))
    {
        puts("You need to sign up first");
        intitial_display_page();
    }
    else
    {
        exit(0);
    }
}

void sign_up(struct USER* usr_ptr, struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr)
{
    int value;
    puts("\n------------------------------------------------------------------ SIGN UP ---------------------------------------------------");

    printf("\t Create your username:->\t");
    scanf("%s",(*usr_ptr).username);
    printf("\t Create your Password:->\t");
    scanf("\t%s",(*usr_ptr).password);
 
    puts("\t\t\t\t\t\t\t\t\t\t\ttDONE");
   
    printf("If you are Admin Enter  : 1\n");
    printf("If you are Student Enter: 2\n");
    printf("\t\t\t\t\t\t\t\t(If you are Admin then you have to submit your detials first before log in :)\n");
   
    scanf("%d",&value);

    if(value == 1)
    {
        admin_info(usr_ptr,admin_ptr);
        
    }
    else if(value == 2)
    {
        student_log_in(usr_ptr, sdt_ptr);
    }

    

}

void student_log_in(struct USER* usr_ptr, struct STUDENT_INFO* sdt_ptr)
{
    
    int value1, value2, choice;

    char entered_username[25];
    char entered_password[25];

    puts("\n---------------------------------------------------------------LOG IN --------------------------------------------------------");
    

        printf("Enter your username:->\t");
        scanf("%s", &entered_username);
        printf("Enter your password:->\t");
        scanf("%s", &entered_password);

        value1 = strcmp((*usr_ptr).username, entered_username);
        value2 = strcmp((*usr_ptr).password, entered_password);


        if((value1 == 0) &&  (value2 == 0))
        {
            puts("\t\t\t  --------------------");
            puts("\t\t\t | Entered Sucessfully: |");
            puts("\t\t\t  --------------------");
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

    puts("\n------------------------------------------------------------------ ADMIN LOG IN --------------------------------------------------");
    
    

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
        
        }
        else
        {
            puts("Please check your user id and password:");
            exit(0);
        }
        admin_home();
}



void admin_info(struct USER* usr_ptr, struct ADMIN_INFO* admin_ptr)
{
    puts("\n------------------------------------------------------------------ ADMIN INFO ----------------------------------------------------------");
    printf("Enter your initial name :- ");
    scanf("%s",(*admin_ptr).admin_name);
    printf("Enter your Mobile No.   :-");
    scanf("%llu",&(*admin_ptr).admin_mobile_no);
    printf("Enter your Mail-id      :-");
    scanf("%s",(*admin_ptr).admin_mail_id);

    admin_log_in(usr_ptr, admin_ptr);
    
    
}


void student_info(struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr)
{
    puts("\n---------------------------------------------------- STUDENT INFORMATION ----------------------------------------------------");
    printf("Enter your initial name :- ");
    scanf("%s",(*sdt_ptr).student_name);
    printf("Enter your Roll No      :- ");
    scanf("%d",&(*sdt_ptr).student_roll_no);
    printf("Department              :- ");
    scanf("%s",(*sdt_ptr).student_department);
    printf("Enter your Mobile No.   :- ");
    scanf("%llu",&(*sdt_ptr).student_mobile_no);
    printf("Enter your Mail-id      :- ");
    scanf("%s",(*sdt_ptr).student_mail_id);
    printf("Paid Amount             :- ");
    scanf("%d",&(*sdt_ptr).student_fees_paid);
    STUDENT_HOME(sdt_ptr,admin_ptr);
}

void admin_access_student_info(struct STUDENT_INFO arr[10])
{
    int i=0;
    puts("you have to keep student records by their roll no. wise :");
    puts("Enter student roll no.");
    scanf("%d",&i);

    printf("\nstudent[%d] - Enter your initial name :- ",i);
    scanf("%s",arr[i].student_name);
    printf("student[%d] - Enter your Roll No        :- ",i);
    scanf("%d",&arr[i].student_roll_no);
    printf("student[%d] - Department                :- ",i);
    scanf("%s",arr[i].student_department);
    printf("student[%d] - Enter your Mobile No.     :- ",i);
    scanf("%llu",&arr[i].student_mobile_no);
    printf("student[%d] - Enter your Mail-id        :- ",i);
    scanf("%s",arr[i].student_mail_id);
    printf("student[%d] - Paid Amount               :- ",i);
    scanf("%d",&arr[i].student_fees_paid);
    admin_home();
}

void admin_access_student_info_print(struct STUDENT_INFO arr[20])
{
    int i=0, value=0;
    puts("How many student records you want to see?");
    scanf("%d",&value);

    
    for(i=1; i<=value; i++)
    {
        printf("%d]%s\t\t%d\t%s\t%llu\t%s\t%d\n",i,arr[i].student_name,
                            arr[i].student_roll_no,
                            arr[i].student_department,
                            arr[i].student_mobile_no,
                            arr[i].student_mail_id,
                            arr[i].student_fees_paid);
    }
    admin_home();
}

void print_student_info(struct STUDENT_INFO* sdt_ptr)
{
    printf("|%s\n|%d\n|%s\n|%llu\n|%s\n|%d\n",(*sdt_ptr).student_name,
                                (*sdt_ptr).student_roll_no,
                                (*sdt_ptr).student_department,
                                (*sdt_ptr).student_mobile_no,
                                (*sdt_ptr).student_mail_id,
                                (*sdt_ptr).student_fees_paid);
}

void remaining_fees(struct STUDENT_INFO arr[20])
{
    int remaining_fees[20];
    int i, value;
    puts("How many students records you want to check?");
    scanf("%d",&value);

    for(i=0; i<=value; i++)
    {
        if (arr[i].student_fees_paid < 22000)
        {
            remaining_fees[i] = (22000-(arr[i].student_fees_paid));
        }
    }

    for(i=1; i<=value; i++)
    {
        printf("%d]%s\t\t%d\t%s\t%llu\t%s\t%d\t(22000-%d=%d)\n",i,arr[i].student_name,
                            arr[i].student_roll_no,
                            arr[i].student_department,
                            arr[i].student_mobile_no,
                            arr[i].student_mail_id,
                            arr[i].student_fees_paid,
                            arr[i].student_fees_paid,
                            remaining_fees[i]);
    }
    admin_home();

   
}

void STUDENT_HOME( struct STUDENT_INFO* sdt_ptr, struct ADMIN_INFO* admin_ptr)
{
    int value;

    puts("\n------------------------------------------------------ STUDENT_HOME --------------------------------------------------------");
    puts("Enter 1: Enter your Detials");
    puts("Enter 2: Show my detials");
    puts("Enter 3: Edit my detials");

    scanf("%d",&value);

    if(value == 1)
    {
        student_info(sdt_ptr,admin_ptr);
    }
    else if(value == 2)
    {
        print_student_info(sdt_ptr);
    }
    else if(value == 3)
    {
        puts("if you already record your detials then only you can edit it ");
        student_info(sdt_ptr,admin_ptr);
    }
  

}

void admin_home()
{
    puts("\n----------------------------------------------------------------- ADMIN HOME ------------------------------------------------");
    int choice=0;

    puts("Enter 1: Add student Detials");
    puts("Enter 2: See student Rocords");
    puts("Enter 3: Check how many students remains to pay fess:");
    puts("Enter 3: Close The Application");  

    scanf("%d",&choice);

    if (choice == 1)
    {
        admin_access_student_info(arr);
    }
    else if(choice == 2)
    {
        admin_access_student_info_print(arr);
    }
    else if(choice == 3)
    {
        remaining_fees(arr);
    }
    
}