#include <stdio.h> 
#include <stdlib.h> 

void (*cpa_function(int, void(*)(int)))(int); 

void handler_1(int n); 
void handler_2(int n); 
void handler_3(int n); 
void handler_4(int n); 

int main(void)
{
    void (*pfn_prev_handler)(int); 

    pfn_prev_handler = cpa_function(10, handler_1); 
    if(pfn_prev_handler != NULL)
        pfn_prev_handler(100); 
    pfn_prev_handler = cpa_function(20, handler_2); 
    if(pfn_prev_handler != NULL)
        pfn_prev_handler(100); // handler 1 
    pfn_prev_handler = cpa_function(20, handler_3); 
    if(pfn_prev_handler != NULL)
        pfn_prev_handler(100); // handler 2 
    pfn_prev_handler = cpa_function(20, handler_4); 
    if(pfn_prev_handler != NULL)
        pfn_prev_handler(100); // handler 3 
    pfn_prev_handler = cpa_function(20, NULL); 
    if(pfn_prev_handler != NULL)
        pfn_prev_handler(100); // handler 4 

    return (0); 
}


void (*cpa_function(int n, void (*pfn)(int)))(int)
{
    static  void (*pfn_curr)(int) = NULL; 
    void (*pfn_prev)(int); 
    puts("New handler registered, returning the previous one"); 
    pfn_prev = pfn_curr; 
    pfn_curr = pfn; 
    return (pfn_prev); 
}

void handler_1(int n)
{
    puts("In handler 1"); 
}

void handler_2(int n)
{
    puts("In handler 2"); 
}

void handler_3(int n)
{
    puts("In handler3"); 
}

void handler_4(int n)
{
    puts("In handler 4"); 
}