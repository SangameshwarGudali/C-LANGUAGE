#include <stdio.h> 
#include <stdlib.h> 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

void for_builtin(void); 
void for_user_defiend(void); 

int main(void)
{
    for_builtin(); 
    for_user_defiend(); 

    return (0); 
}

void for_builtin(void)
{
    int* p = NULL;  // S1: Define pointer and initialize to NULL 
    int n; 

    p = malloc(sizeof(int)); // S2: allocate memory dynamically and store 
                             // the base addr in ptr 

    // In Debug code: assert(p != NULL); 
    // S3: Validating dynamic memory allocation 
    if(NULL == p)
    {
        fprintf(stderr, "malloc:fatal:out of virtual address space\n"); 
        exit(EXIT_FAILURE); 
    }

    // S4 : Initializing dynamic memory allocation 
    memset(p, 0, sizeof(int));  // initialize to 0 
                                // alternatively, calloc() can be used. 

    // S5-A): write 
    *p = 100; 
    // S5-B): read 
    n = *p; 

    // S6: release 
    free(p); 
    // S7: 
    p = NULL;
}

void for_user_defiend(void)
{
    struct Date* pDate = NULL; // S1 

    pDate = (struct Date*)malloc(sizeof(struct Date)); // S2 
    // S3 
    if(NULL == pDate)
    {
        fprintf(stderr, "malloc:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    // S4 
    memset(pDate, 0, sizeof(struct Date)); 

    // S5-A
    pDate->day = 10; 
    pDate->month = 2; 
    pDate->year = 2021; 

    // S5-B
    printf("%d-%d-%d\n", pDate->day, pDate->month, pDate->year); 

    // S6: release, return or store in g_ptr 
    free(pDate); 
    // S7 
    pDate = NULL;
}

 // S6: release 
 // If you have defined a local pointer variable in some function 
 // and have stored the address of dynamically allocated data element 
 // to it then while returning from function, you must do one of the 
 // following three things 

 // Option 1 : release 
 // free (p); 
 // p = NULL; 

 // Option 2: return 
 // return (p); 
 // Make caller catch the return value (mention in documentaiton)

 // Option 3: store it in global pointer 
 // g_ptr = ptr; 

