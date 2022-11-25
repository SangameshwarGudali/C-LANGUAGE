/*
#include<stdio.h>
#include<stdlib.h>

int male_dancer;
int female_dancer;
int team;

int main(void)
{
    male_dancer=0;
    female_dancer=0;
    team=male_dancer && female_dancer;
    printf("male_dancer=%d,female_dancer=%d,team=%d\n",male_dancer,female_dancer,team);

    male_dancer=1;
    female_dancer=0;
    team=male_dancer && female_dancer;
    printf("male_dancer=%d,female_dancer=%d,team=%d\n",male_dancer,female_dancer,team);

    male_dancer=0;
    female_dancer=1;
    team=male_dancer && female_dancer;
    printf("male_dancer=%d,female_dancer=%d,team=%d\n",male_dancer,female_dancer,team);

    male_dancer=1;
    female_dancer=1;
    team=male_dancer && female_dancer;
    printf("male_dancer=%d, female_dancer=%d, taem=%d\n",male_dancer,female_dancer,team);
}


#include<stdio.h>
#include<stdlib.h>

int on;
int off;
int result;

int main(void)
{
    on=0;
    off=1;
    result=on && off;
    printf("on=%d,of=%d,result=%d\n",on,off,result);

    on=1;
    off=0;
    result=on && off;
    printf("on=%d,off=%d,result=%d\n",on,off,result);

    on=0;
    off=0;
    result=on && off;
    printf("on=%d,off=%d,result=%d\n",on,off,result);

    on=1;
    off=1;
    result=on && off;
    printf("on=%d,off=%d,result=%d\n",on,off,result);

    exit(0);
}


#include<stdio.h>
#include<stdlib.h>

int tea;
int bread;
int breakfast;

int main(void)
{
    tea=0;
    bread=1;
    breakfast=tea && bread;
    printf("tea=%d,bread=%d,breakfast=%d\n",tea,bread,breakfast);


    tea=1;
    bread=0;
    breakfast=tea && bread;
    printf("tea=%d,bread=%d,breakfast=%d\n",tea,bread,breakfast);


    tea=0;
    bread=0;
    breakfast=tea && bread;
    printf("tea=%d,bread=%d,breakfast=%d\n", tea,bread,breakfast);


    tea=1;
    bread=1;
    breakfast=tea && bread;
    printf("tea=%d,bread=%d,breakfast=%d\n",tea,bread,breakfast);
    

    exit(0);
}

#include<stdio.h>
#include<stdlib.h>

int cpu;
int main_memory;
int computer;

int main(void)
{
    cpu=0;
    main_memory=0;
    computer=cpu && main_memory;
    printf("cpu=%d,main_memory=%d,computer=%d\n",cpu,main_memory,computer);

    cpu=0;
    main_memory=1;
    computer=cpu && main_memory;
    printf("cpu=%d, main_memory=%d, computer=%d\n",cpu,main_memory,computer);

    cpu=1;
    main_memory=0;
    computer=cpu && main_memory;
    printf("cpu=%d,main_memory=%d,computer=%d\n",cpu,main_memory,computer);

    cpu=1;
    main_memory=1;
    computer=cpu && main_memory;
    printf("cpu=%d,main_memory=%d,computer=%d\n",cpu,main_memory,computer);

    exit(0);
}

*/

#include<stdio.h>
#include<stdlib.h>

int ide;
int library;
int sdk;

int main(void)
{
    ide= 0;
    library=1;
    sdk=ide && library;
    printf("lde=%d,library=%d,sdk=%d\n",ide,library,sdk);

    ide=1;
    library=0;
    sdk=ide && library;
    printf("ide=%d,library=%d,sdk=%d\n",ide,library,sdk);

    ide=1;
    library=1;
    sdk=ide && library;
    printf("ide=%d,library=%d,sdk=%d\n",ide,library,sdk);

    ide= 0; 
    library=0;
    sdk=ide && library;
    printf("ide=%d,library=%d,sdk=%d\n",ide,library,sdk);

    exit(0);
}









































































