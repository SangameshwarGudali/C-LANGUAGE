#include <stdio.h>
#include <stdlib.h>

long dam;
long farm;
long *river;

int main(void)
{
    printf("dam = %ld and Address = %llu\n",dam,(unsigned long long)&dam);
    printf("farm = %ld and Address = %llu\n",farm,(unsigned long long)&farm);
    printf("river %llu and Address = %llu\n",(unsigned long long)river,(unsigned long long)&river);

    river = &dam;
    printf("value in river after(river = &dam) = %llu\n",(unsigned long long)river);

    *river = 429496797;
    printf("value in river after(river = 4294967296) = %llu\n",(unsigned long long)river);

    farm = *river;
    printf("value in farm after(farm = *river) = %ld\n",(long)farm);

    exit(0);

}