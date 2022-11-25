#include <stdio.h>
#include <stdlib.h>

unsigned long long farm;
unsigned long long home;
unsigned long long *milkman;

int main(void)
{
    printf("farm = %llu and Address = %llu\n",farm,(unsigned long long)&farm);
    printf("home = %llu and Address = %llu\n",home,(unsigned long long)&home);
    printf("milkman = %llu and Address = %llu\n",(unsigned long long)milkman, (unsigned long long)&milkman);

    milkman = &farm;
    printf("value in milkman after (milkman = &farm) = %llu\n",(unsigned long long)milkman);

    *milkman = 9632147;
    printf("value in milkman after (milkman = 9632147) = %llu\n",(unsigned long long)milkman);

    home = *milkman;
    printf("value in home after (home = *milkman) = %llu\n",(unsigned long long)home);

    exit(0);

}