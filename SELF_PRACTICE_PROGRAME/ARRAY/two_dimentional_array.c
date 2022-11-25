#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void fill_array_data(int arr[4][3], int row, int column);
void print_array_element(int arr[4][3], int row, int column);


int main(void)
{
    int arr[4][3];
    fill_array_data(arr, 4, 3);
    print_array_element(arr, 4, 3);

    exit(0);
}



void fill_array_data(int arr[4][3], int row, int column)
{
    int i = 0;
    int j = 0;

    for(i = 0; i<row; ++i)
    {
        for(j = 0; j<column; ++j)
        {
            arr[i][j] = j*2;
        }
    }
}


void print_array_element(int arr[4][3], int row, int column)
{
    int i = 0;
    int j = 0;

    for(i = 0; i<row; ++i)
    {
        for(j = 0; j<column; ++j)
        {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}
