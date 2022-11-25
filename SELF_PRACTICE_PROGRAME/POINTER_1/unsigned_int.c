#include <stdio.h>
#include <stdlib.h>

unsigned dhig;
unsigned khadda;
unsigned *jcb;

int main(void)
{
    printf("dhig = %u and Address = %llu\n",dhig,(unsigned long long)&dhig);
    printf("khadda = %u and Address = %llu\n",khadda,(unsigned long long)&khadda);
    printf("jcb = %llu and Address = %llu\n",(unsigned long long)jcb,(unsigned long long)&jcb);

    jcb = &dhig;
    printf("value in jcb after(jcb = &dhig) = %llu\n",(unsigned long long)jcb);

    *jcb = 852456;
    printf("value in jcb after(*jcb = 852456) = %llu\n",(unsigned long long)jcb);

    khadda = *jcb;
    printf("value in khadda after (khadda = *jcb) = %lu\n", khadda);

    exit(0);

}