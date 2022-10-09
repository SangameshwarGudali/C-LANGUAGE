#include <stdio.h> 
#include <stdlib.h> 

int date; 
int day_of_the_week; 

int main()
{
    printf("Enter today's date:[1-31]:"); 
    scanf("%d", &date); 

    printf("Enter day of the week:[1:Mon,2:Tue,3:Wed,4:Thrus,5:Fri,6:Sat,7:Sun]:"); 
    scanf("%d", &day_of_the_week); 

    printf("Date entered is %d\n", date); 
    
    switch(day_of_the_week)
    {
        case 1: 
            puts("Monday selected"); 
            break;

        case 2: 
            puts("Tuesday selected"); 
            break;

        case 3: 
            puts("Wednesday selected"); 
            break;

        case 4: 
            puts("Thursday selected"); 
            break;

        case 5: 
            puts("Friday selected"); 
            break;

        case 6: 
            puts("Saturday selected"); 
            break;

        case 7: 
            puts("Sunday selected"); 
            break;
    }

    exit(0); 
}

/* 
    Monday      -> 1
    Tuesday     -> 2 
    Wednesday   -> 3 
    Thursday    -> 4 
    Friday      -> 5 
    Saturday    -> 6 
    Sunday      -> 7 
*/ 

