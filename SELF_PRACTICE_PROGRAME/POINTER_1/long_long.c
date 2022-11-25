#include <stdio.h>
#include <stdlib.h>

long long warehouse;
long long room;
long long *forklift;

int main(void)
{
    printf("warehouse = %lld and Address = %llu\n",warehouse,(unsigned long long)&warehouse);
    printf("room = %lld and Address = %llu\n",room,(unsigned long long)&room);
    printf("forklift = %llu and Address = %llu\n",(unsigned long long)forklift,(unsigned long long)&forklift);

    forklift = &warehouse;
    printf("value in forklift after (forklift = &warehouse) = %llu\n",(unsigned long long)forklift);

    *forklift = 778899;
    printf("value in forklift after (*forklift = 778899) = %llu\n",(unsigned long long)forklift);

    room = *forklift;
    printf("value in room after(room = *forklift) = %lld\n",room);

    exit(0);

}