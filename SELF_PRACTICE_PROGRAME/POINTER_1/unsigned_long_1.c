#include <stdio.h>
#include <stdlib.h>

unsigned long barrel;
unsigned long bucket;
unsigned long *mug;

int main(void)
{
    printf("barrel = %lu and Address = %llu\n",barrel,(unsigned long long)&barrel);
    printf("bucket = %lu and Address = %llu\n", bucket,(unsigned long long)&bucket);
    printf("mug = %llu and Address = %llu\n",(unsigned long long)mug,(unsigned long long)&mug);

    mug = &barrel;
    printf("value in mug after (mug = &barrel) = %llu\n",(unsigned long long)mug);

    *mug = 999;
    printf("value in mug will remain same after (*mug = 999) = %llu\n",(unsigned long long)mug);

    bucket = *mug;
    printf("value in bucket will change after (bucket = *mug) = %lu\n",bucket);

    exit(0);

}