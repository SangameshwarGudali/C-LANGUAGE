#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

int* built_in_data_type_function();
int* array_of_bulit_int_data_type(int* p_arr, int size);
int structure_function();
struct DATE* array_of_structure_function();

int main(void)
{
    struct Date d;
    struct DATE* date = 0;
    int arr[5];
    int* p = 0;
    int size = 5;

    p = built_in_data_type_function();
    printf("return value from built in data type funtion is = %d\n", *p);

    p = array_of_bulit_int_data_type(&arr[0],size);
    for(int i = 0; i<size; i++)
        printf("arr[%d] = %d\n", i, *(p+i));

    int m = structure_function();
   

    //date = array_of_structure_function(size);
}

int* built_in_data_type_function()
{
    int return_value = 55;
    return (&return_value);
}
int* array_of_bulit_int_data_type(int* p_arr, int size)
{
    for(int i = 0; i<size; i++)
    {
        *(p_arr+i) = i*10;
    }
    return (p_arr);
}
int structure_function()
{
  p_date->day = 1;
  p_date->month = 6;
  p_date->year = 2022;

  return(0);
}
//struct DATE* array_of_structure_function();