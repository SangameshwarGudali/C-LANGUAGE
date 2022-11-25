#include <stdio.h>
#include <stdlib.h>

long tank;
long drum;
long *tap;

int main(void)
{   
    printf("tank = %ld and Address = %llu\n",tank,(unsigned long long)&tank);
    printf("drum = %ld and Address = %llu\n",drum,(unsigned long long)&drum);
    printf("tap = %ld and Address = %llu\n",(long)tap,(unsigned long long)&tap);

    tap = &tank;
    printf("value in tap after (tap = &tank) = %llu\n",(unsigned long long)tap);

    *tap = 100;
    printf("value in tap still remain same after(*tap = 100) =%llu\n",(unsigned long long)tap);

    drum = *tap;
    printf("value in drum after (drum = *tap)= %ld\n",drum);

    exit(0);
}