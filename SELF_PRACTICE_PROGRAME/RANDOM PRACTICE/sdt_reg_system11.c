#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ARRAY 10
#define TRUE 1
#define FALSE 0
#define DATA_FOUND 1
#define DATA_NOT_FOUND 0
#define STUDENT_HOME 11
#define ADMIN_HOME 12
#define LOG_OUT 22
#define DISPLAY_PAGE 33

struct USER
{
    char username[25];
    char password[25];
};
struct USER user_arr[SIZE_OF_ARRAY];

struct STUDENT
{
    char student_first_name[15];
    char student_last_name[15];
    char student_gender[6];
    unsigned short student_roll_no;
    unsigned long long student_mobile_no;
    char student_district[15];
    char student_taluka[15];
    char student_mailid[20];
    int student_fees_paid;
}student;

struct STUDENT student_arr[SIZE_OF_ARRAY];

void display_page(int value);
void student_sign_up(void);
void student_log_in(struct USER* sdt_usr_sign_up_ptr);
int create_usenname_password_array();
void home(int home_code , int student_code);
void course_details(void);
void get_admission(void);
void student_personal_info(void);
void admin_log_in(void);
void admin_access_student_info(void);
void print_all_student_records(void);
void check_how_many_students_fess_remains(void);

int main(void)
{
    int choice;

    display_page(DISPLAY_PAGE);
    exit(0);

}


void display_page(int value)
{
    if(value != LOG_OUT)
    {
        int choice = 0;
        puts("__________________________________WELCOME TO SOLAPUR UNIVERSITY DEPARTMENT________________________________________");
        puts("                                                                                              1: student sign up ");
        puts("                                                                                              2: Admin log in");
        puts("                                                                                              4: Exit");

        puts("Enter your choice ");
        scanf("%d",&choice);

        if(choice == 1)
            student_sign_up();
        else if(choice == 2)
        {
            admin_log_in();
            puts("end");
        }
        else if(choice == 3)
            exit(0);
        else
        {
            puts("Please enter a valid input");
            display_page(DISPLAY_PAGE);
    }
        }
            
    
    
}

void student_sign_up(void)
{
    struct USER* sdt_usr_sign_up_ptr;
    sdt_usr_sign_up_ptr = 0;

    sdt_usr_sign_up_ptr = malloc(sizeof(struct USER));
    if(sdt_usr_sign_up_ptr == 0)
    {
        puts("memory allocatin failed");
        exit(-1);
    }

    printf("\tcreate your username  :");
    scanf("%s", sdt_usr_sign_up_ptr -> username );
    printf("\tcreate your password  :");
    scanf("%s", sdt_usr_sign_up_ptr -> password);

    puts("\t\t\t\tpassword created successfully done");

    student_log_in(sdt_usr_sign_up_ptr);
    
}

void  student_log_in(struct USER* sdt_usr_sign_up_ptr)
{
    int value1, value2, code;
    struct USER* sdt_usr_log_in_ptr;
    sdt_usr_log_in_ptr = 0;
    sdt_usr_log_in_ptr = malloc(sizeof(struct USER));
    if(sdt_usr_log_in_ptr == 0)
    {
        puts("\t\t\t\tmemory allocation failed in sdt log in");
        exit(-1);
    }

    puts("----------------------------------------------STUDENT LOG IN -------------------------------------------------------");
    printf("\tEnter Your Name:");
    scanf("\t%s",sdt_usr_log_in_ptr -> username);
    printf("\tEnter Your Password:");
    scanf("\t%s",sdt_usr_log_in_ptr -> password);


    value1 = strcmp(sdt_usr_sign_up_ptr->username, sdt_usr_log_in_ptr->username);
    value2 = strcmp(sdt_usr_sign_up_ptr->password, sdt_usr_log_in_ptr->password);

    if((value1 == 0) &&  (value2 == 0))
    {
        puts("\t\t\t                                        --------------------");
        puts("\t\t\t                                        | Entered Sucessfully: |");
        puts("\t\t\t                                        --------------------");

        free(sdt_usr_sign_up_ptr);
        sdt_usr_sign_up_ptr = 0;

        free(sdt_usr_log_in_ptr);
        sdt_usr_log_in_ptr = 0;

        code = create_usenname_password_array();
        home(STUDENT_HOME, code);
    }
    else
    {
        puts("\t\t\t\t\t\t\tPassword dosen't Match: please Enter a correct userid and password");
        display_page(DISPLAY_PAGE);
    }

}

int create_usenname_password_array( )
{
    puts("Save your Password");
    int i, code = 0;
    
    printf("\tPlease Enter your CODE :");
    scanf("%d", &code);
    for(i=1; i<=code; i++)
    {
        if(i == code)
        {
            printf("\t\tEnter your username for save : ");
            scanf("%s",user_arr[i].username);
            printf("\t\tEnter your password for save : ");
            scanf("%s",user_arr[i].password);
        }
        
    }
    return code;
}

void home(int home_code , int student_code)
{

    if(home_code == STUDENT_HOME)
    {
        int choice = 0;
        puts("\n------------------------------------------------------STUDENT HOME --------------------------------------------------------\n");

        puts("                                                                                             1. Course detils:");
        puts("                                                                                             2. Get Admission");
        puts("                                                                                             3. Log Out:");

        printf("Enter your choice  :  ");
        scanf("%d", &choice);
    
        switch(choice)
        {
            case 1:
                course_details();
                home(11, student_code);
                break;
            case 2:
                get_admission();
                home(11, student_code);
                break;
            case 3:
                display_page(DISPLAY_PAGE);
                break;
            default:
                puts("invalid choice");
                puts("Please Enter the valid choice");
                home(11, student_code);
                break;
        }
    }
    
    
    else if(home_code == ADMIN_HOME)
    {
        int size = 0;
        int choice = 0;
        

        puts("\n------------------------------------------------------ADMIN HOME --------------------------------------------------------\n");

        puts("                                                                                  1. Update student record");
        puts("                                                                                  2. Check Student Records");
        puts("                                                                                  3. Check how many students fees remains");
        puts("                                                                                  4. Exit");

    
        puts("Enter your choice :");
        scanf("%d", &choice);
        if(choice == 1)
        {
            admin_access_student_info();
            home(ADMIN_HOME ,FALSE);
        }
        else if(choice == 2)
        {
            print_all_student_records();
            home(ADMIN_HOME, FALSE);
        }
        else if(choice == 3)
        {
            check_how_many_students_fess_remains();
            home(ADMIN_HOME, FALSE);
        }

    }    
    
    
}

void course_details(void)
{
    puts("\n------------------------------------------------------ COURSE DETIALS --------------------------------------------------------\n");
    printf("Computer Architecture from programmer's perspective - The C Programming Language - The assembly language -Data Structure and Algorithms -Windows System Programming (Fundamentals) - Linux System Programming (Fundamentals) - GUI programming using Win 32 GDI.\n");
    puts("Course Name : MCA");
    puts("Duration of the course : 2 year");
    printf("Subects:\n");
    puts("       1.DURATION:        2Year");
    puts("       2.CODE             SUS02");                
    puts("       3.Prerequisite     Bachlor Degree"); 
    puts("       4.Language         English"); 
    puts("       5.Fees             22000"); 
    puts("       6.Level            Advance");                
    puts("Fees : 22,000");
    puts("                Note: If you belong to category then you will eligible for govt. scholership\n\n");
}


void get_admission()
{
    puts("Befor get Admission you have to fill up your personal detials");
    student_personal_info();
    puts("Admission will confirm by our side");
    return;
}

void student_personal_info()
{   

    
    int id = 0;
    int i = 0;
    int choice = 0;
    puts("\n---------------------------------------------------- STUDENT PERSONAL INFORMATION ----------------------------------------------------");
    printf("Enter the id which is given by our admin : ->");
    scanf("%d", &id);

    for(i=id; i<=id; i++)
    {
        printf("Enter your initial name :- \n");
        scanf("%s", student_arr[id]. student_first_name);
        printf("Enter your last name :- \n");
        scanf("%s",  student_arr[id].student_last_name);
        printf("Gender :\n");
        scanf("%s",  student_arr[id].student_gender);
        printf("Enter your Roll No      :- \n");
        scanf("%hu", &student_arr[id].student_roll_no);
        printf("Enter your Mobile No.   :- \n");
        scanf("%llu", &student_arr[id].student_mobile_no);
        printf("Entr your district :\n");
        scanf("%s",  student_arr[id].student_district);
        printf("Enter your taluka : \n");
        scanf("%s",  student_arr[id].student_taluka);
        printf("Enter your Mail-id      :- \n");
        scanf("%s",  student_arr[id].student_mailid);
        printf("Enter the Amt. of rupees you paid to our Admin");
        scanf("%d", &student_arr[id].student_fees_paid);

    }
}

void admin_log_in()
{
    int value1, value2;
    int home_code = 12;

    struct USER* admin_user_ptr;
    struct USER* already_set_user_info_ptr;

    
    admin_user_ptr = 0;
    admin_user_ptr = malloc(sizeof(struct USER));
    if(admin_user_ptr == 0)
    {
        puts("memory allocation failed in admin log in");
        exit(-1);
    }

    struct USER admin_user;
    char pre_set_admin_username1[15] = "sangamesh";
    char pre_set_admin_password1[15] = "sang@123";

    puts("Enter your username ");
    scanf("%s", admin_user_ptr -> username);
    puts("Enter your Password");
    scanf("%s", admin_user_ptr -> password);

    value1 = strcmp(pre_set_admin_username1 , admin_user_ptr -> username);
    value2 = strcmp(pre_set_admin_password1 , admin_user_ptr -> password );

    if((value1 == 0) && (value2 == 0))
    {
        puts("\t\t\t                                        --------------------");
        puts("\t\t\t                                        | Entered Sucessfully: |");
        puts("\t\t\t                                        --------------------");
        home(ADMIN_HOME , 0);
    }
    else
    {
        puts("Please check your user id and password:");
    
    }    
}

void admin_access_student_info()
{
    int code = 0;
    puts("Enter the student code");
    scanf("%d", &code);
    int i = 0;

    for(i=0; i<=code; i++)
    {
        if( i == code)
        {
            printf("[%d]Enter student initial name          :- \n", i);
            scanf("%s", student_arr[i].student_first_name);
            printf("[%d]Enter student last name             :- \n" , i);
            scanf("%s", student_arr[i].student_last_name);
            printf("[%d]Gender :\n", i);
            scanf("%s", student_arr[i].student_gender);
            printf("[%d]Enter student Roll No               :- \n" , i);
            scanf("%hu", &student_arr[i].student_roll_no);
            printf("[%d]Enter student Mobile No.            :- \n", i);
            scanf("%llu", &student_arr[i].student_mobile_no);
            printf("[%d]Entr student district               :\n", i);
            scanf("%s", student_arr[i].student_district);
            printf("[%d]Enter student taluka                : \n", i);
            scanf("%s", student_arr[i].student_taluka);
            printf("[%d]Enter student Mail-id               :- \n" , i);
            scanf("%s", student_arr[i].student_mailid);
            printf("[%d]Enter How many Rupees Amt student paid:- \n" , i);
            scanf("%d", &student_arr[i].student_fees_paid);
            
        }
        
    }

}

void print_all_student_records()
{
    int size = 0;
    int i = 0;
    int value = 0;
    puts("How many student records do you want to see?");
    scanf("%d", &size);
    for(i=1; i<=size; i++)
    {
        printf("[%d]%s, %s, %s, %hu, %llu, %s, %s, %s\n", i, student_arr[i].student_first_name,
                                                student_arr[i].student_last_name,
                                                student_arr[i].student_gender,
                                                student_arr[i].student_roll_no,
                                                student_arr[i].student_mobile_no,
                                                student_arr[i].student_district,
                                                student_arr[i].student_taluka,
                                                student_arr[i].student_mailid);

    }


}

void check_how_many_students_fess_remains()
{
    int remaining_fees[SIZE_OF_ARRAY];
    int i, value;
    puts("How many students records you want to check?");
    scanf("%d",&value);

    for(i=0; i<=value; i++)
    {
        if (student_arr[i].student_fees_paid < 22000)
        {
            remaining_fees[i] = (22000-(student_arr[i].student_fees_paid));
        }
    }

    for(i=1; i<=value; i++)
    {
        printf("[%d]first name =%s\n", i,student_arr[i].student_first_name);
        printf("[%d]last name = %s\n", i, student_arr[i].student_last_name );
        printf("[%d]Gender = %s\n" , i, student_arr[i].student_gender);
        printf("[%d]Gender = %hu\n" , i, student_arr[i].student_roll_no);
        printf("[%d]Mobile No. = %llu\n", i, (unsigned long long int)student_arr[i].student_mobile_no);
        printf("[%d]District = %s\n", i, student_arr[i].student_district);
        printf("[%d]Taluka = %s\n", i, student_arr[i].student_taluka);
        printf("[%d]Mail Id = %s\n", i, student_arr[i].student_mailid);
        printf("[%d]Remaining Fees = %d\n", i, remaining_fees[i]);
    }

   
}























