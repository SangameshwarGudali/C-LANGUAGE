#include <stdio.h>
#include <stdlib.h>

void test_function(int n);
int main(void)
{
    test_function(8);
    return (0);
}

void test_function(int n)
{
    if (n == 0)
        return;
    printf("n = %d\n", n);
    test_function(n - 1);
    printf("returning from function with n = %d\n", n);
}

pf1(8)<-pf1(7) < -pf1(6) < -pf1(5) < -pf1(4) < -pf1(3) < -pf1(2) < -pf1(1) < -pf(1) < -pf(2) < -pf(3) < -pf(4) < -pf(5) < -pf(6) < -pf(7) < -pf(8) < -

                                                                                                                                                     main(void)
                                                                                                                                                         test_function(8)
                                                                                                                                                             printf exicuted ==
       => n = 8 test_function(7)
                  printf exicuted
              == = > n = 7 test_function(6)
                             printf exicuted
                         == = > n = 6 test_function(5)
                                        printf exicuted
                                    == = > n = 5 test_function(4)
                                                   printf exicuted
                                               == = > n = 4 test_function(3)
                                                              printf exicuted
                                                          == = > n = 3 test_function(2)
                                                                         printf exicuted
                                                                     == = > n = 2 test_function(1)
                                                                                    printf exicuted
                                                                                == = > n = 1 test_function(0) if (n == 0) : (0 == 0) : TRUE
                                                                                                                                       return;
printf exicuted == = > returning form n = 1 printf exicuted == = > returning form n = 2 printf exicuted == = > returning form n
