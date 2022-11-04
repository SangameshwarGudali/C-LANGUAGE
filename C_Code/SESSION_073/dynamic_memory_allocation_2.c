#include <stdio.h> 
#include <stdlib.h> 

void ptr_to_char(void);
void ptr_to_short(void) ; 
void ptr_to_int(void); 
void ptr_to_long_int(void); 
void ptr_to_long_long_int(void); 
void ptr_to_float(void); 
void ptr_to_double(void); 

int main(void)
{
    ptr_to_char(); 
    ptr_to_short(); 
    ptr_to_int(); 
    ptr_to_long_int(); 
    ptr_to_long_long_int(); 
    ptr_to_float(); 
    ptr_to_double(); 
    exit(0); 
}


void ptr_to_char(void)
{
    char* cp = 0; 
    unsigned char* u_cp = 0; 

    char c; 
    unsigned char uc; 

    cp = &c; 
    u_cp = &uc; 

    cp = malloc(sizeof(char));              /* allocate 1 byte on heap */ 
    u_cp = malloc(sizeof(unsigned char));    /* allocate 1 byte on heap */ 
    if(cp == 0 || u_cp == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    *cp = '$'; 
    *u_cp = 201; 

    printf("*cp = %c, *u_cp = %hhu\n", *cp, *u_cp); 

    free(cp); 
    cp = 0; 

    free(u_cp); 
    u_cp = 0; 
}

void ptr_to_short(void)
{
    short* p1 = 0; 
    unsigned short* p2 = 0; 

    p1 = malloc(sizeof(short));              /* allocate 2 bytes on heap */ 
    p2 = malloc(sizeof(unsigned short));     /* allocate 2 bytes on heap */ 
    if(p1 == 0 || p2 == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    *p1 = -4574; 
    *p2 = 37534; 

    printf("*p1 = %hd, *p2 = %hu\n", *p1, *p2); 

    free(p1); 
    p1 = 0; 

    free(p2); 
    p2 = 0; 
}

void ptr_to_int(void)
{
    int* p1 = 0; 
    unsigned int* p2 = 0; 

    p1 = malloc(sizeof(int));           /* allocate 4 bytes on heap */ 
    p2 = malloc(sizeof(unsigned int));  /* allocate 4 bytes on heap */ 

    if(p1 == 0 || p2 == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    *p1 = -46535; 
    *p2 = 634535; 

    printf("*p1 = %d, *p2 = %u\n", *p1, *p2); 

    free(p1); 
    p1 = 0; 

    free(p2); 
    p2 = 0; 
}

void ptr_to_long_int(void)
{
    long int* p1 = 0; 
    unsigned long int* p2 = 0; 

    p1 = malloc(sizeof(long int)); 
    p2 = malloc(sizeof(unsigned long int)); 

    if(p1 == 0 || p2 == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    *p1 = -34653525; 
    *p2 = 35345345; 

    printf("*p1 = %ld, *p2 = %lu\n", *p1, *p2); 

    free(p1); 
    p1 = 0; 

    free(p2); 
    p2 = 0; 
}

void ptr_to_long_long_int(void)
{
    long long int* p1 = 0; 
    unsigned long long int* p2 = 0; 

    p1 = malloc(sizeof(long long int)); 
    p2 = malloc(sizeof(unsigned long long int)); 

    if(p1 == 0 || p2 == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    *p1 = -354324536; 
    *p2 = 632534635; 

    printf("*p1 = %lld, *p2 = %llu\n", *p1, *p2); 

    free(p1); 
    p1 = 0; 

    free(p2); 
    p2 = 0; 
}

void ptr_to_float(void)
{
    float* pf = 0; 

    pf = malloc(sizeof(float)); 
    if(pf == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }
    
    *pf = 45.643; 
    printf("*pf = %f\n", *pf); 

    free(pf); 
    pf = 0; 
}

void ptr_to_double(void)
{
    double* p_double = 0; 

    p_double = malloc(sizeof(double)); 
    if(p_double == 0)
    {
        puts("Memory allocation failed"); 
        exit(-1); 
    }

    *p_double = 4563465.32532; 
    printf("*p_double = %lf\n", *p_double); 

    free(p_double); 
    p_double = 0; 
}

/* 
    void f(void)
    {
        T* p = 0; 

        p = malloc(sizeof(T)); 
        if(p == 0)
        {
            puts("Memor allocation failed"); 
            exit(-1); 
        }

        *p ON LHS to write on allocated memory 
        *p ON RHS to read from allocated memory 

        free(p); 
        p = 0; 
    }
*/ 