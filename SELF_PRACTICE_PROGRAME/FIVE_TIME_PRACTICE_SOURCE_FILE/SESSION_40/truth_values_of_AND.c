#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
int ans;

int main(void)
{
    ans = (FALSE && FALSE);
    printf("FALSE && FALSE = %d\n",ans);
    ans = (FALSE && TRUE);
    printf("FALSE && TRUE = %d\n",ans);
    ans = (TRUE && TRUE);
    printf("TRUE && TRUE = %d\n",ans);
    ans = (TRUE && FALSE);
    printf("TRUE && FALSE = %d\n",ans);

    
    
    
    

    exit(0);
}