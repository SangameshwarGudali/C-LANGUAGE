#include <stdio.h>
#include <stdlib.h>

static int m = 100;     // Memory Allocation time - Static
                        // Section -> DATA Section
                        // Lifetime -> Program End

int n = 200;            // Memory Allocation Time -> Static
                        // section -> DATA section
                        // Lifetime -> Program End

int o;                  // Memory Allocation Time -> Static
                        // Section -> BSS section
                        // Lifetime -> Program End

const int p = 400;       // Memory Allocation Time -> Static
                        // Section -> READ ONLY DATA
                        // Lifetime -> Program End

static const int q = 500;// Memory Allocation Time -> Static
                        // Section -> READ ONLY DATA
                        // Lifetime -> Program End

int main(void)
{
    puts("Inside main function");
    test_function();

    return(0);
}

test_function()
{
    int a = 111;        // Memory Allocation Time -> Dynamic
                        // Section -> Auto Storage Class
                        // Lifetime -> function return
                        // (Memory will create evry function call)
                    
    int b;              // Memory Allocation Time -> Dynamic
                        // Section -> Auto Storage Class
                        // Lifetime -> function return
                        // (Memory will create evry function call)


    const int c = 333;  // Memory Allocation Time -> Dynamic
                        // Section -> Auto Storage Class
                        // Lifetime -> function return
                        // (Memory will create evry function call)


    static int d = 444; // Memory Allocation Time -> Static
                        // Section -> DATA
                        // Lifetime -> Program End
                        // (standalone single copy)

    static int e;       // Memory Allocation Time -> Static
                        // Section -> BSS
                        // Lifetime -> Program End
                        // (standalone single copy)
                        
    static const int f = 666;   // Memory Allocation Time -> Static
                        // Section -> READ ONLY
                        // Lifetime -> Program End
                        // (standalone single copy)

    puts("Inside test function");
}