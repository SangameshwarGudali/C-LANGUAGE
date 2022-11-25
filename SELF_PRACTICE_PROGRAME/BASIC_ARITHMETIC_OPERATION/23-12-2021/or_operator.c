/*
#include<stdio.h>
#include<stdlib.h>

int mavshicha_chaha;
int mavshicha_coffe;
int mazi_pasant;

int main(void)
{
    mavshicha_chaha=1;
    mavshicha_coffe=0;
    mazi_pasant=mavshicha_chaha || mavshicha_coffe;
    printf("mavshicha_chaha=%d,mavshicha_coffe=%d,mazi_pasant=%d\n",mavshicha_chaha,mavshicha_coffe,mazi_pasant);

    mavshicha_chaha=0;
    mavshicha_coffe=1;
    mazi_pasant=mavshicha_chaha || mavshicha_coffe;
    printf("mavshicha_chaha=%d,mavshicha_coffe=%d,mazi_pasant=%d\n",mavshicha_chaha,mavshicha_coffe,mazi_pasant);


    mavshicha_chaha=0;
    mavshicha_coffe=0;
    mazi_pasant=mavshicha_chaha || mavshicha_coffe;
    printf("mavshicha_chaha=%d,mavshicha_coffe=%d,mazi_pasant=%d\n",mavshicha_chaha,mavshicha_coffe,mazi_pasant);

    mavshicha_chaha=1;
    mavshicha_coffe=1;
    mazi_pasant=mavshicha_chaha || mavshicha_coffe;
    printf("mavshicha_chaha=%d,mavshicha_coffe=%d,mazi_pasant=%d\n",mavshicha_chaha,mavshicha_coffe,mazi_pasant);

    exit(0);
}
*/

#include<stdio.h>
#include<stdlib.h>

int policy;
int mechanism;
int behaviour;

int main(void)
{
    policy=1;
    mechanism=0;
    behaviour=policy || mechanism;
    printf("policy=%d, mechanism=%d,behaviour=%d",policy,mechanism,behaviour);

    policy=0;
    mechanism=1;
    behaviour=policy || mechanism;
    printf("policy=%d,mechanism=%d,behaviour=%d",policy,mechanism,behaviour);

    policy=0;
    mechanism=0;
    behaviour=policy || mechanism;
    printf("polciy=%d,mechanishm=%d,behaviour=%d",policy,mechanism,behaviour);

    policy=1;
    mechanism=1;
    behaviour=policy || mechanism;
    printf("policy=%d, mechanism=%d, behaviour=%d",policy,mechanism,behaviour);

    exit(0);
}


























