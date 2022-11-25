#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void ptr_to_built_in(void);
void ptr_to_struct(void);
void ptr_to_arr(void);
void ptr_to_ptr(void);
void ptr_to_function(void);

int main(void)
{
    ptr_to_built_in();
    ptr_to_arr();
    ptr_to_struct();
    ptr_to_function();
    ptr_to_ptr();
    
    exit(0); 
}
void ptr_to_built_in(void)
{
    int m = 10;
    int n = 200;

    int* ptr = 0;
    ptr = &m;
    *ptr = 300;
    printf("*ptr = %d\n", m);

    ptr = &n;
    *ptr = 600;
    printf("*ptr = %d\n", n);

}

void ptr_to_arr(void)
{
    int arr[5] = {1,2,3,4,5};
    int* p = 0;
    p = arr;

    printf("Address of arr = %llu\n",(unsigned long long int)&arr);
    printf("Address in p = %llu\n", (unsigned long long int)p);
}


void ptr_to_struct(void)
{
    struct Date d;
    struct Date* p = 0;

    p = &d;
    printf("Adderess of struct d = %llu\n",(unsigned long long int)&d);
    printf("Address in p (of struct d) = %llu\n", (unsigned long long int)p);
}

void ptr_to_function(void)
{
    void(*ptr)(void) = 0;
    ptr = ptr_to_arr;
    ptr();
}

void ptr_to_ptr(void)
{
    int* p = 0;
    int** pp = 0;
    int m = 100;
    int n;

    p = &m;
    printf("p = &m (Address in p = %llu\n)", (unsigned long long int)p);

    pp = &p;
    printf("pp = &p (Address in pp = %llu\n)", (unsigned long long int)*pp);
}