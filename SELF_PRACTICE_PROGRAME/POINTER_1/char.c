#include <stdio.h>
#include <stdlib.h>

char letter;
char word;
char *pen;

int main(void)
{
    printf("letter = %c and Address = %llu\n",letter,(unsigned long long)&letter);
    printf("word = %c and Address = %llu\n",word,(unsigned long long)&word);
    printf("pen = %llu and Address = %llu\n",(unsigned long long)pen,(unsigned long long)&pen);

    pen = &letter;
    printf("value in pen after (pen = &letter) = %llu\n",(unsigned long long)pen);

    *pen = 'A';
    printf("value in pen still reamain same after (*pen = 'A') = %llu\n",(unsigned long long)pen);

    word = *pen;
    printf("value in word will change after (word = *pen) =%c\n",word);

    exit(0);

}