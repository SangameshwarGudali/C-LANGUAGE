#include <stdio.h>
#include <stdlib.h>

struct STUDENT
{
    char* name;
    int roll_no;
    char division;
    struct MARK
    {
        int physics;
        int chemistry;
        int maths;
    }mark;
    int coins[8];
}student = {
                "sangameshwar",
                17,
                'A',
                {
                    75,
                    89,
                    70
                },
                {5,10,20,50,100,200,500,2000}
           };

int main(void)
{
    printf("name = %s\n",student.name);
    printf("Roll No. = %d\n",student.roll_no);
    printf("Division = %c",student.division);
    printf("Marks in physics = %d\n",student.mark.physics);
    printf("Maarks in chemistry = %d\n",student.mark.chemistry);
    printf("Marks in maths = %d\n",student.mark.maths);
    printf("Types of notes student have\t");
    int i;
    for(i=0; i<8; i++)
        printf("%d\t",student.coins[i]);

    return(0);
}