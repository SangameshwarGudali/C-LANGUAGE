#include <stdio.h> 
#include <stdlib.h> 

void test(void); 

int main(void)
{
    int i; 
    for(i = 0; i < 5; ++i)
        test(); 
    exit(0); 
}

void test(void)
{
    static int n = 1; 
    int i = 1; 
    int cnt; 
    cnt = 0; 
    n = 1; 
    while(cnt < 10)
    {
        i = i + 1; 
        n = n + 1; 
        cnt = cnt + 1; 
    }

    printf("Good-bye values:i=%d, n=%d, cnt=%d\n", i, n, cnt); 
}

/* 
    1.  Storage location Change 
    2.  Life-time 
    3.  allocation strategy 

Local variable without static keyword / qualifier 
1.  Auto storage section of the function! 
2.  Life-time = life-time of function call! 
3.  allocation strategy 
    allocation : at the start of function call 
    deallocation/freeing : at the return of function 
    call 
    Allocated PER FUNCTION CALL! 
    -> Every new function call will result into FRESH 
    ALLOCATION OF SUCH VARIABLE! 
    (there are as many different copies of local variable 
    as number of function calls!)

Local variable with static qualifier 
1.  Storage location = one of the static sections! 
    Sections which are allocated at the time of 
    building the program and are present on exe file! 
    Possibilities 
    Data section (if initialized)
    BSS (if uninitialized)
    OR Specialized section of local static 
    as in GCC (Local common memory area = lcomm)
2.  Life-time 
    As life-time of static section is equal to life-time 
    of programs.
    the local variable which is static is allocated memory 
    at the time of building the program (not at the time of 
    function call to which it is local!)
    and the variable is dealloacted at the end of the application 
    (not at the return of the function call!)
3.  Allocation strategy 
    Allocation time: Building program (.c -> .exe)
    Deallocation time: Termination of application 
    ONLY SINGLE COPY IS CREATED IRRESPECTIVE OF NUMBER OF TIME 
    THE FUNCTION IS CALLED! 

CONSEQUENCE OF 3: 
    Local variable cannot retain its value across successive calls 
    but local static variable can. 
*/ 

