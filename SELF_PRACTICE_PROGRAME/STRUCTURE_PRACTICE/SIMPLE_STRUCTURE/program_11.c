#include <stdio.h>
#include <stdlib.h>

struct USER
{
    char* username;
    char* password;
};

int main(void)
{
    struct USER user;
    struct USER* ptr;

    ptr = &user;

    (*ptr).username = "sngameshwar";
    (*ptr).password = "sang123";

    printf("%s\n",(*ptr).username);
    printf("%s\n",(*ptr).password);

    exit(0);


}