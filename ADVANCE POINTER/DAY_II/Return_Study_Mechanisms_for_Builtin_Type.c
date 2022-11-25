#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h>

int get_num_1(void);        // return by value 
void get_num_2(int* p);     // parameter as return value 
int* get_num_3(void); 
void get_num_4(int** pp); 

int main(void)
{
    // caller of get_num_1(); 
    puts("Method_1:"); 
    int ret_1; 
    ret_1 = get_num_1(); 
    printf("ret=%d\n", ret_1); 

    // caller of get_num_2(); 
    puts("Method_2:"); 
    int ret_2; 
    get_num_2(&ret_2); 
    printf("ret_2 = %d\n", ret_2); 
    int* p_ret = malloc(sizeof(int)); 
    assert(p_ret != NULL); 
    get_num_2(p_ret); 
    printf("*p_ret_2 = %d\n", *p_ret); 
    free(p_ret); 
    p_ret = NULL; 

    // caller of get_num_3()
    int* p_ret_1 = NULL; 
    p_ret_1 = get_num_3(); 
    printf("*p_ret_3 = %d\n", *p_ret_1); 
    free(p_ret_1); 
    p_ret_1 = NULL; 

    // caller of get_num_4() 
    int* p_ret_2 = NULL; 
    get_num_4(&p_ret_2); 
    printf("*p_ret_2 = %d\n", *p_ret_2); 
    free(p_ret_2); 
    p_ret_2 = NULL; 

    return (0); 
}

int get_num_1(void)
{
    return (10); 
}

void get_num_2(int* p)
{
    *p = 10; 
}

int* get_num_3(void)
{
    int* p = NULL; 

    p = (int*)malloc(sizeof(int)); 
    assert(p != NULL); 
    *p = 10; 

    return (p); 
}

void get_num_4(int** pp)
{
    int* p_local = NULL; 

    p_local = (int*)malloc(sizeof(int)); 
    assert(p_local != NULL); 
    *p_local = 10; 
    *pp = p_local; 
}

