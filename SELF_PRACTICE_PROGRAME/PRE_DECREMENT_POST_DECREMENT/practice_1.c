#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    puts("Pre Decrement");
    int right=100;
    int left=0;
    printf("left=%d,right=%d\n",left,right);
    left=right;
    printf("After (left=right)-->left=%d,right=%d\n",left,right);
    left=--right;
    printf("After (left=--right)-->left=%d,right=%d\n\n",left,right);

    puts("Post Decrement");
    right=100;
    left=0;
    printf("left=%d,right=%d\n",left,right);
    left=right;
    printf("After (left=right)--->left=%d,right=%d\n",left,right);
    left=right--;
    printf("After (left=right--)---> left=%d,right=%d\n",left,right);
    exit(0);
}