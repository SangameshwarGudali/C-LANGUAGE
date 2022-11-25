#include <stdio.h>
#include <stdlib.h>

long long treasure;
long long wallet;
long long *hand;

int main(void)
{
    printf("treasure = %lld and Address = %llu\n",treasure,(unsigned long long )&treasure);
    printf("wallet = %lld and Address = %llu\n",wallet,(unsigned long long)&wallet);
    printf("hand = %llu and Address = %llu\n",(unsigned long long)hand,(unsigned long long)&hand);

    hand = &treasure;
    printf("value in hand after (hand = &treasure) = %llu\n",(unsigned long long)hand);

    *hand = 500;
    printf("Address of hand still remain same after (*hand = 500) =%llu\n",(unsigned long long)&hand);

    wallet = *hand;
    printf("value in wallet will change after (wallet = *hand) = %lld\n",wallet);

    exit(0);

}