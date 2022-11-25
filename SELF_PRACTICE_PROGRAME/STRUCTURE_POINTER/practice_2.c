#include <stdio.h>
#include <stdlib.h>

struct ADDRESS
{
    char* name;
    int pin_code;
    unsigned long long mob_number;
};

int main(void)
{
    struct ADDRESS address;
    struct ADDRESS* p;

    p = &address;

    p -> name = "sangameshwar gudali";
    p -> pin_code = 413305;
    p -> mob_number = 9960296337;

    struct ADDRESS *np;

    np = &address;

    (*np).name = "ramkrushna paramhans";
    (*np).pin_code = 658945;
    (*np).mob_number = 9890949387;


    printf("name = %s\n",p->name);
    printf("pin code = %d\n",p->pin_code);
    printf("mob number = %llu\n\n ",p->mob_number);

    printf("name = %s\n", np->name);
    printf("pin code = %d\n",np->pin_code);
    printf("mob number %llu\n",np->mob_number);

    exit(0);
}