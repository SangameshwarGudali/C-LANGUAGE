#include<stdio.h>
#include<stdlib.h>

int i;

int main(void)
{
    i=1;
    while(i<=8)
    {
        printf("Hi sangameshwar\n");
        i=i+1;
    }

    exit(0);
}

/* TRACK -> i = 1 
            CHECK : i <= 5 : 1 <= 5 : TRUE 
                        EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)
    TRACK -> i =2 : i <= 5 : 2 <= 5 : TRUE 
                        EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)
    TRACK -> i = 3 : i<= 5: 3 <= 5 : TRUE 
                       EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)
    TRACK -> i = 4 : i <= 5 : 4 <= 5 : TRUE 
                        EXECUTE BODY 
                            EXECUTE(puts("Hello"))
                            EXECUTE(i = i + 1)

    TRACK -> i=1
            CHECK : i <= 8 : 1 <= 8 : TRUE
                        EXECUTE BODY
                            EXECUTE (printf("Hi sangameshwar"))
                            EXECUTE (i = i + 1)
    TRACK -> i=2
            CHECK : i <= 8 : i <=8 : TRUE
                        EXECUTE BODY
                            EXECUTE (printf("Hi sangameshwar"))
                            EXECUTE (i = i + 1)
    TRACK -> i=3
            CHECK : i <=8 : i <= 8 : TRUE
                        EXECUTE BODY
                            EXECUTE(printf("Hi sangameshwar"))
                            EXECUTE( i = i +1)
    TRACK  -> i=4
            CHECK : i <=8 : i<=8 : TRUE
                        EXECUTE BODY
                            EXECUTE(printf("Hi sangameshwar"))
                            EXECUTE(i = i+1)
    TRACK -> i=5
            CHECK : i <=8 : i<=8 : TRUE
                        EXECUTE BODY
                            EXECUTE(printf("Hi sangameshwar"))
                            EXECUTE( i = i + 1)

    