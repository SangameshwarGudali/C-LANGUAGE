#include <stdio.h>
#include <stdlib.h>

short post;
short office;
short *postman;

int main(void)
{
    printf("post = %u and Address = %llu\n",post,(unsigned long long)&post);
    printf("office =%u and Address = %llu\n",(unsigned)office,(unsigned long long)&office);
    printf("postman = %u and Address = %llu\n",(unsigned)postman,(unsigned long long)&postman);

    postman = &post;
    printf("value in postman after(postman = &post)= %llu\n",(unsigned long long)postman);

    *postman = 600;
    printf("value in postman remain still same after (*postman = 600)= %llu\n",(unsigned long long)postman);

    office = *postman;
    printf("value in office after(office = *postman)= %u",(unsigned)office);

    exit(0);
}