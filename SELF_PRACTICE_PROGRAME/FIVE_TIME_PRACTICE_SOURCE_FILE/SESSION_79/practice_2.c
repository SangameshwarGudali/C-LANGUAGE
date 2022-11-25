#include <stdio.h>
#include <stdlib.h>

#define BITS_PER_BYTE 8

int is_kth_bit_on(unsigned int n, unsigned int k, unsigned int nr_total_bits);

int main(void)
{
    unsigned n;
    unsigned i;

    printf("Enter n = ");
    scanf ("%u", &n);

    for(i = 1; i<BITS_PER_BYTE*sizeof(unsigned int); ++i)
    {
        printf("bit (%u) = %u\n", i, is_kth_bit_on( n, i, BITS_PER_BYTE*sizeof(unsigned int)));
    }

    exit(0);
}

int is_kth_bit_on(unsigned int n, unsigned int k, unsigned int nr_total_bits)
{
    assert(1 <= k && k <= nr_total_bits );
    return(n & (1 << (k - 1)) == (1 << (k - 1)));
}