#include <stdio.h>
#include <stdlib.h>

char* test_function(void);

int main(void)
{
    char* output;

    puts("Start of the program");
    output = test_function();
    printf("character return by test function = %c\n", *output);
    puts("End of the program");

    free(output);
    output = 0;


    exit(0);
}

char* test_function()
{
    char* character;
    char test_character;

    character = &test_character;
    printf("Address of character before dynamic memory allocation = %llu\n", (unsigned long long int)character);

    character = malloc(sizeof(char));
    if(character == 0)
    {
        puts("memory allocation filed");
        exit(-1);
    }
    printf("Address in character after dynamic memory allocation = %llu\n", (unsigned long long int)character);

    *character = 'A';
    printf("character = %c\n", *character);

    
    return character;
}