#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    puts("Pre Increment");
    int i=10;
    int m=0;
    printf("m=%d,i=%d\n",m,i);
    m=i;
    printf("After (m=i)---> m=%d,i=%d\n",m,i);
    m=++i;
    printf("After (m=++i) ---> m=%d, i=%d\n\n",m,i);

    puts("Post Increment");
    int j=20;
    int n=0;
    printf("n=%d,j=%d\n",n,j);
    n=j;
    printf("After (n=j)---> n=%d,j=%d\n", n,j);
    n=j++;
    printf("After (n=j++)---> n=%d,j=%d\n",n,j);


    exit(0);
}