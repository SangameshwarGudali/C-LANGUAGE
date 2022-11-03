#include <stdio.h> 
#include <stdlib.h> 

struct A
{
    int a;      /* offset a = 0 */ 
    char b;     /* offset b = 4 */ 
    int arr[5]; /* offset arr = 8 */ 
}; 

int main(void)
{
    struct A instance_of_A; 
    int i; 
    instance_of_A.a = 100; 
    instance_of_A.b = 'A'; 
    instance_of_A.arr[0] = 1000; 
    instance_of_A.arr[1] = 2000; 
    instance_of_A.arr[2] = 3000; 
    instance_of_A.arr[3] = 4000; 
    instance_of_A.arr[4] = 5000; 

    /* 
        instance_of_structure.arr_name[index]; 

        instance of structure + offset(arr_name) + sizeof(data type) * index
    */ 

    printf("instance_of_a.a = %d\n", instance_of_A.a); 
    printf("instance_of_a.b = %c\n", instance_of_A.b); 
    for(i = 0; i < 5; ++i)
        printf("instance_of_A.arr[%d]:%d\n", i, instance_of_A.arr[i]);    

    exit(0); 
}
/* 
    offset (distance in bytes) of element at index 'i' in array of 
    data type T 

    T arr[N]; 

    arr[i]

    Base address of array = arr 
    Offset = i * sizeof(typeof(array_element))

    arr + i * sizeof(type_of(array_element))

    int a[5]; 
    i = 0, 1, 2, 3, 4 

    base_addr(a) + i * sizeof(typeof(array_element))

    &a[0] + i * sizeof(int)

    &a[0] + i * 4 

    i = 0 
    &a[0] + 0 * 4 

    i = 1 
    &a[0] + 1 * 4

    i = 2 
    &a[0] + 2 * 4 

    i = 3 
    &a[0] + 3 * 4 

    i = 4 
    &a[0] + 4 * 4 

    int a[5]; 

    a[i]; 

    inA.arr[i];

    base addr of inA + offset(arr in struct A) + i * sizeof(typeof(array_element))

    &inA + 8 + i * sizeof(int)

    &inA + 8 + i * 4 
*/ 

