#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct STUDENT
{
    char* name;
    unsigned long long int mobile_no;
    int roll_no;
}student;

struct STUDENT* set_values(void);

int main(void)
{
    struct STUDENT* ptr = 0;
    ptr = set_values();

    printf("%s\n", ptr->name);
    printf("%llu\n", (unsigned long long int)ptr->mobile_no);
    printf("%d\n", ptr->roll_no);

    free(ptr);
    ptr = 0;

    exit(0);
}

struct STUDENT* set_values()
{
    struct STUDENT* set_ptr = 0;
    set_ptr = malloc(sizeof(struct STUDENT));
    assert(set_ptr != 0);
    set_ptr ->name = "sangamesh";
    set_ptr -> mobile_no = 9960296337;
    set_ptr -> roll_no = 17;

    return(set_ptr);

}

