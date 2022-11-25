#include <stdio.h>
#include <stdlib.h>

int calculate_sum(int* p_arr , int size);

int main(void)
{
    int arr[10]={10,20,30,40,50,60,70,80,90,100};
    int sum_of_all_array=0;

    sum_of_all_array = calculate_sum(&arr[0], 10);
    printf("%d",sum_of_all_array);

    return(0);
}

int calculate_sum(int* p_arr , int size)
{
    int bucket;
    int i;
    for(i=0; i < size; i++)
    {
        bucket = bucket + p_arr[i];
    }
    return (bucket);
}