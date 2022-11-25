#include <stdio.h> 
#include <stdlib.h> 

#ifndef CPA 
void print_cpa_msg(void);
#endif 

int main(void)
{
    #ifndef CPA 
    print_cpa_msg(); 
    #endif 

    return (0); 
}

#ifndef CPA 
void print_cpa_msg(void)
{
    puts("Hello, from CPA"); 
}
#endif 
