#include <stdio.h>
#include <stdlib.h>

unsigned long rack;
unsigned long table;
unsigned long *worker;

int main(void)
{
    printf("rack = %lu and Address = %llu\n",rack,(unsigned long long)&rack);
    printf("table = %lu and Address = %llu\n",table,(unsigned long long)&table);
    printf("worker = %llu and Address = %llu\n",(unsigned long long)worker,(unsigned long long)&worker);

    worker = &rack;
    printf("value in worker after(worker = &track) = %llu\n",(unsigned long long)worker);
    
    *worker = 8888;
    printf("value inf worker after(*worker = 8888) =%llu\n",(unsigned long long)worker);

    table = *worker;
    printf("value in table after(table = *worker) = %lu\n",table);

    exit(0);


}