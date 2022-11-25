#include <stdio.h>
#include <stdlib.h>

unsigned long long icecream_in_fridge;
unsigned long long icecream_in_thermocole;
unsigned long long*icecream_in_spoon;

int main(void)
{
    printf("icecraem_in_fridge = %llu and Address = %llu\n",icecream_in_fridge,(unsigned long long)&icecream_in_fridge);
    printf("icecream_in_thermocole = %llu and Address = %llu\n",icecream_in_thermocole,(unsigned long long)&icecream_in_thermocole);
    printf("icecream_in_spoon = %llu and Address = %llu\n",(unsigned long long)icecream_in_spoon,(unsigned long long)&icecream_in_spoon);

    icecream_in_spoon = &icecream_in_fridge;
    printf("value in icecream_in_fridge after(icecream_in_spoon = &icecream_in_fridge = %llu\n",(unsigned long long)icecream_in_spoon);

    *icecream_in_spoon = 145632;
    printf("value in icecream_in_spoon after(*icecream_in_spoon = 145632) = %llu\n", (unsigned long long)icecream_in_spoon);

    icecream_in_thermocole = *icecream_in_spoon;
    printf("value in icecream_in_thermocole after(icecream_in_thermocole = *icecraem_in_spoon) = %llu\n",(unsigned long long)icecream_in_thermocole);

    exit(0);
}