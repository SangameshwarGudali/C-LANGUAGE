#include <stdio.h> 
#include <stdlib.h> 

void test_1(void); 
void test_2(void); 
void test_3(void); 

int main(void)
{
    test_1(); 
    test_2(); 
    test_3(); 
    exit(0); 
}

void test_1(void)
{
    int n1=10, n2=20, n3=30, n4=40, n5=50; 
    int* arr[5]; // 40 bytes 
    puts("test1"); 
    printf("Before:n1=%d, n2=%d, n3=%d, n4=%d, n5=%d\n", 
    n1, n2, n3, n4, n5); 
    arr[0] = &n1; 
    arr[1] = &n2; 
    arr[2] = &n3; 
    arr[3] = &n4; 
    arr[4] = &n5; 

    *arr[0] = 100; 
    *arr[1] = 200; 
    *arr[2] = 300; 
    *arr[3] = 400; 
    *arr[4] = 500; 

    printf("After:n1=%d, n2=%d, n3=%d, n4=%d, n5=%d\n", 
        n1, n2, n3, n4, n5); 
}

void test_2(void)
{
    int arr[5] = {10, 20, 30, 40, 50}; 
    int i; 
    int (*p)[5]; // 8 byte 

    puts("test2"); 
    for(i = 0; i < 5; ++i)
        printf("Before:arr[%d]:%d\n", i, arr[i]); 

    p = &arr; 
    
    for(i = 0; i < 5; ++i)
        (*p)[i] = (i+1) * 100; 

    for(i = 0; i < 5; ++i)
        printf("After:arr[%d]:%d\n", i, arr[i]); 
}

void test_3(void)
{
    int* p1 = 1000;
    int (*p2)[1000] = 1000; 
    puts("test_3"); 
    printf("p1 + 1 = %llu\n", (unsigned long long int)(p1+1)); // 1004 
    printf("p2 + 1 = %llu\n", (unsigned long long int)(p2+1)); // 1020 
}

/* 
    int arr[5]; 
    int* p1 = arr; // &arr[0] | int* 
    int (*p2)[5]= &arr; // &arr[0] | int(*)[];
*/ 


