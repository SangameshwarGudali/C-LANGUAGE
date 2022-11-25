#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int is_kth_bit_on(unsigned int number, unsigned int i, unsigned int total_number_of_bits);

int main(void)
{
    unsigned int number;
    unsigned int result_bit;
    unsigned int total_number_of_bits = 32;

    printf("Enter the number : \n");
    scanf("%d", &number);

    for(int i=1; i<32; ++i)
    {
        result_bit = is_kth_bit_on(number, i, total_number_of_bits);
        printf("bit(%u) = %d\n", i,result_bit);
    }
    exit(0);
}

int is_kth_bit_on(unsigned int number, unsigned int i, unsigned int total_number_of_bits)
{
    assert(1 <= i && i <= total_number_of_bits);
    return(number & (1 << (i - 1)) == (1 << (i - 1)));
}