
                    /*  PARAMETER AS RETURN VALUE */


include <stdio.h>
#include <stdlib.h>

struct SIGNATURE_STRUCT
{
    int a;
    char b;
    float c;
};

void set_struct_value(struct SIGNATURE_STRUCT* ptr);
void get_int_value(int* ptr);
void get_char_value(char* ptr);
void get_float_value(float* ptr);
void get_double_value(double* ptr);

int main(void)
{
    int int_pot = 0;
    float float_pot = 0;
    double double_pot = 0;
    char char_pot = 0;

    struct SIGNATURE_STRUCT signature;

    struct SIGNATURE_STRUCT* ptr;
    ptr = 0;
    ptr = malloc(sizeof(struct SIGNATURE_STRUCT));
    if(ptr == 0)
    {
        puts("memory allocatin failed");
        exit(-1);
    }

    set_struct_value(ptr);

    printf("int a = %d\n", (*ptr).a);
    printf("char b = %c\n", (*ptr).b);
    printf("float c = %f\n", (*ptr).c);

    

    get_int_value(&int_pot);
    printf("int_pot = %d\n", int_pot);

    get_char_value(&char_pot);
    printf("char_pot = %c\n", char_pot);

    get_float_value(&float_pot);
    printf("float_pot = %f\n", float_pot);

    get_double_value(&double_pot);
    printf("doble_pot = %lf\n", double_pot);

    free(ptr);
    ptr = 0;

    exit(0);
}

void get_int_value(int* ptr)
{
    *ptr = 777;
}

void get_float_value(float* ptr)
{
    *ptr = 56456.32;
}

void get_double_value(double* ptr)
{
    *ptr = 4164984.3215;
}
void get_char_value(char* ptr)
{
    *ptr = 'C';
}

void set_struct_value(struct SIGNATURE_STRUCT* ptr)
{
    (*ptr).a = 10;
    (*ptr).b = 'B';
    (*ptr).c = 11.22;
}

