#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    puts("Pre Decrement");
    int cand=5;
    int kitely=0;
    printf("kitely=%d,cand=%d\n",kitely,cand);
    kitely=cand;
    printf("After (kitely=cand)--->kitely=%d,cand=%d\n",kitely,cand);
    kitely=--cand;
    printf("After (kitely=--cand)--->kitely=%d,cand=%d\n\n",kitely,cand);

    puts("Post Decrement");
    cand=5;
    kitely=0;
    printf("kitely=%d,cand=%d\n",kitely,cand);
    kitely=cand;
    printf("After (kitely=cand)--->kitely=%d,cand=%d\n",kitely,cand);
    kitely=cand--;
    printf("After (kitely=cand--)--->kitely=%d,cand=%d\n\n",kitely,cand);

    exit(0);

}