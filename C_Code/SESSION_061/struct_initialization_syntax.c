#include <stdio.h> 
#include <stdlib.h> 

struct A
{
    int a; 
    char b; 
    float c; 
}inA = {100, 'A', 3.14}; 

/*  struct A {int a; char b; float c;} inA; 
    struct A inA1; 
    struct A X; 
    struct A {int a; char b; float c;}; 
    struct A inA; 
*/ 

struct B
{
    int m; 
    char c;
    int arr[5]; 
    float farr[5];  
}inB = {    
            1000, 
            'd', 
            {-1, -2, -3, -4, -5}, 
            {1.1,2.2,3.3,4.4,5.5}
        }; 

struct Outer
{
    int num; 
    float f_num; 
    struct Inner
    {
        char c1; 
        char c2; 
        int arr[5]; 
    }inC; 
    float f_arr[4]; 
    double d_num; 
}instance_of_outer = {
                        1000, 
                        3.14, 
                        {
                            'A', 
                            'B', 
                            {-1, -2, -3, -4, -5}
                        }, 
                        {1.1, 2.2, 3.3, 4.4}, 
                        4567.987654
                    };  
/*  
    print all members of instance_of_outer.
    Use loops for printing arrays 
    instance_of_outer.num 
    instance_of_outer.f_num 
    instance_of_outer.inC.c1
    instance_of_outer.inC.c2 
    instance_of_outer.inC.arr[i] // i from 0 to 4 
    instance_of_outer.farr[i] // i from 0 to 4 
    instance_of_outer.d_num 
*/ 
int main(void)
{
    int i; 

    struct A X = {200, 'B', 6.28}; 

    printf("inA.a == %d, inA.b == %c, inA.c == %f\n", 
        inA.a, inA.b, inA.c); 
    printf("X.a == %d, X.b == %c, X.c == %f\n", X.a, X.b, X.c); 

    printf("inB.m == %d, inB.c == %c\n", inB.m, inB.c); 
    puts("Showing inB.arr using for loop"); 
    for(i = 0; i < 5; ++i)
        printf("inB.arr[%d] == %d\n", i, inB.arr[i]); 
    puts("Showing inB.farr using for loop"); 
    for(i = 0; i < 5; ++i)
        printf("inB.arr[%d]:%.1f\n", i, inB.farr[i]); 
    
    printf("sizeof(struct Outer)=%llu\n", 
            sizeof(struct Outer)); 

    exit(0); 
}

/* 
// real life applications of nested structure 

struct ipad
{
    struct physical_properties
    {
        float weight; 
        struct dimensions
        {
            float length; 
            float breadth; 
            float depth; 
        }ipad_dimensions; 
    }ipad_phys; 
}my_ipad = {
                {
                    250.5, 
                    {
                        28.4, 
                        18.2, 
                        0.8
                    }, 
                }
            
            }; 

my_ipad.ipad_phys.weight
my_ipad.ipad_phys.ipad_dimensions.lenth; 
my_ipad.ipad_phys.ipad_dimensions.breadth; 
my_ipad.ipad_phys.ipad_dimensions.depth 
*/ 