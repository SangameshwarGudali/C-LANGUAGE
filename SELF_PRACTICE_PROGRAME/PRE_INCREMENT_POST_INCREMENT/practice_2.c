#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    puts("Pre Increment");
    int denara=100;
    int ghenara=0;
    printf("ghenara=%d,denara=%d\n",ghenara,denara);
    ghenara=denara;
    printf("After (ghenara=denara)-->ghenara=%d,denara=%d\n",ghenara,denara);
    ghenara=++denara;
    printf("After (ghenara=++denara)-->ghenara=%d,denara=%d\n\n",ghenara,denara);


    puts("Post Increment");
    int right=100;
    int left=0;
    printf("left=%d,right=%d\n",left,right);
    left=right;
    printf("After (left=right)--> left=%d,right=%d\n",left,right);
    left=right++;
    printf("After (left=right++)--> left=%d,right=%d\n",left,right);
    exit(0);

}