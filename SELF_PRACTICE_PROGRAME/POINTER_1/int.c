#include <stdio.h>
#include <stdlib.h>

int book;
int notes;
int *pen;

int main(void)
{
    printf("book = %d and Address of book = %llu\n",book,(unsigned long long)&book);
    printf("notes = %d and Address of notes = %llu\n",notes,(unsigned long long)&notes);
    printf("pen = %d and Address of pen = %llu\n",(int)pen,(unsigned long long)&pen);

    pen = &book;
    printf("value in pen after(pen = &book) = %llu\n",(unsigned long long)pen);

    *pen = 123456;
    printf("value in pen after(*pen = 123456) = %llu\n",(unsigned long long)pen);

    printf("value in notes before(notes = *pen) = %d\n",notes);
    notes = *pen;
    printf("value in notes after(notes = *pen) = %d\n",notes);

    exit(0);

}