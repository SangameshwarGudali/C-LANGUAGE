#include <stdio.h>
#include <stdlib.h>

int is_kth_bit_on(int total_number_of_bits, int kth_bit, int number);

int main(void)
{
    int number;
    int check;
    int checking_bit;
    int count = 0;

    puts("Enter the number");
    scanf("%d", &number);
    
    while(1)
    {
        if(count == 32)
            break;
        puts("which bit do you want to check it?");
        scanf("%d", &checking_bit);

        check = is_kth_bit_on(32, checking_bit, number);
        printf("check = %u\n", check);
        count++;
    }

    return(0);
}

int is_kth_bit_on(int total_number_of_bits, int kth_bit, int number)
{
    return(number & (1 << (kth_bit - 1)) == (1 << (kth_bit - 1)));
}   