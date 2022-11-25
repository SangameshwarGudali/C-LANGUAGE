#include <stdio.h>
#include <stdlib.h>

unsigned short cup;
unsigned short saucer;
unsigned short *kitely;

int main(void)
{
    printf("cup = %hu and Address = %llu\n",cup,(unsigned long long)&cup);
    printf("saucer = %hu and Address = %llu\n",saucer,(unsigned long long)&saucer);
    printf("kitely = %llu and Address = %llu\n",(unsigned long long)kitely,(unsigned long long)&kitely);

    kitely = &cup;
    printf("Value in kitely after(kitely = &cup) = %llu\n",(unsigned long long)kitely);

    *kitely = 1432;
    printf("value in kitely still same after(*kitely = 1432) = %llu\n",(unsigned long long)kitely);

    saucer = *kitely;
    printf("value in saucer after(saucer = *ketely) = %hu\n",saucer);

    exit(0);
}