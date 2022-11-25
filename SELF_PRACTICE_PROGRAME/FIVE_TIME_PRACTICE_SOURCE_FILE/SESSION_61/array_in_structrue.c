#include <stdio.h>
#include <stdlib.h>

struct DEMO
{
    char m;
    int num;
    int arr[5];
    short s;
    float f;
    double drr[5];
};

int main(void)
{
    struct DEMO demo;
    struct DEMO array[3];
    struct DEMO* ptr;

    int i, j, k;
    
    ptr = &array[1];

    for(i=0; i<3; i++)
    {
        array[i].m = i+65;
        array[i].num = i*100;

        for(j=0; j<5; j++)
            array[i].arr[j] = j;
        
        array[i].s = i*2;
        array[i].f = i*4.5;

        for(k=0; k<5; k++)
            array[i].drr[k] = k*555;    

    }

    for(i=0; i<3; i++)
    {
        printf("\n\n\n array[%d].m = %c\n", i, array[i].m);
        printf("array[%d].num = %d\n", i, array[i].num);

        for(j=0; j<5; j++)
            printf("array[%d].arr[%d] = %d\t", i, j, array[i].arr[j]);

        printf("array[%d].s = %hu\n", i, array[i].s);
        printf("array[%d].f = %f\n", i, array[i].f);

        for(k=0; k<5; k++)
            printf("array[%d].drr[%d] =%llu\t", i, k, (unsigned long long)array[i].drr[k]);
    }

    //printf("arr[0].m = %c\n", (*ptr).m);


    //printf("sizeof structr DEMO = %d\n", sizeof(struct DEMO));

    exit(0);
                                         
}