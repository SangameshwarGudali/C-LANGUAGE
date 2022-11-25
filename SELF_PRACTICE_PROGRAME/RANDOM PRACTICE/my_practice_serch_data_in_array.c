#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY 3
#define TRUE 1
#define FALSE 0
#define DATA_FOUND 1
#define DATA_NOT_FOUND 0

struct STUDENT
{
    char name[10];
    int roll_no;
};

void array_demo();
int serch_array(struct STUDENT* ptr, int size_of_array, char* search_data);

int main(void)
{
    puts("Start the program");
    array_demo();

    puts("End the program");

    exit(0);
}

void array_demo()
{
    struct STUDENT arr[SIZE_OF_ARRAY];
    int i;
    int ret;
    char search_data[15];

    puts("Enter the arry element");

    for(i=0; i<SIZE_OF_ARRAY; i++)
    {
        printf("Enter the name : \n");
        scanf("%s", arr[i].name);
        printf("Enter the roll no :\n");
        scanf("%d", &arr[i].roll_no);
    }

    for(i=0; i<SIZE_OF_ARRAY; i++)
    {
        printf("name = %s\n", arr[i].name);
        printf("Roll No. = %d\n", arr[i].roll_no);
    }

    puts("serch data in array");
    scanf("%s", search_data);

    ret = serch_array(&arr[0], SIZE_OF_ARRAY, &search_data[0]);
    if(ret == DATA_FOUND)
    {
        printf("%s is present in array\n", search_data); 
    }
    else
    {
        printf("%s is not present in array\n", search_data); 
    }
    

}

int serch_array(struct STUDENT* ptr, int size_of_array, char* search_data)
{
    int i;
    for(i=0; i<size_of_array; i++)
    {
        if(*(ptr+i)->name == *search_data)
        {
            return DATA_FOUND;
        }
    }
    return DATA_NOT_FOUND;
}