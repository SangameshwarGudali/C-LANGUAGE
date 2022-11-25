#include <stdio.h>
#include <stdlib.h>

#ifdef SWIGGY
void swiggy_order(void);
#endif

#ifdef ZOMATO
void zomato_order(void);
#endif

int main(void)
{
    #ifdef SWIGGY
    swiggy_order();
    #endif

    #ifdef ZOMATO
    zomato_order();
    #endif

    return(0);
}

#ifdef SWIGGY
void swiggy_order(void)
{
    puts("swiggy order");
}
#endif

#ifdef ZOMATO
void zomato_order()
{
    puts("zomato order");
}
#endif