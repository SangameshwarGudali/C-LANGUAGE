#include <stdio.h>
#include <stdlib.h>

#define N1 5
#define N2 4

#define SUCCESS 1
#define FAILURE 0

void print_my_array(int arr[N1][N2], int nr_rows, int nr_colms);
int initilize_array_values(int arr[N1][N2], int nr_rows, int nr_colms);
int find_summation_of_row(int arr[N1][N2], int nr_rows, int nr_colms, int row_number, int* row_total);
int find_summation_of_column(int arr[N1][N2], int nr_rows, int nr_colms, int col_number, int* column_total);

int main(void)
{
    int ret;
    int arr[N1][N2];
    int row_total;
    int column_total;
    
    ret = initilize_array_values(arr, N1, N2);
    if(ret == 0)
    {
        printf("Array initilization Failed\n");
    }
    print_my_array(arr, N1, N2);
    ret = find_summation_of_row(arr, N1, N2, 3, &row_total);
    if(ret == FAILURE )
    {
        puts("PLEASE ENTER VALID ROW NUMBER");
    }
    printf("summation of row = %d\n", row_total);
    find_summation_of_column(arr, N1, N2, 52, &column_total);
    if(ret == FAILURE)
    {
        puts("PLESASE ENTER VALID COLUMN NUMBER");
    }
    printf("summation of column = %d\n", column_total);

    exit(0);
}

int initilize_array_values(int arr[N1][N2], int nr_rows, int nr_colms)
{
    for(int i = 0; i < nr_rows; ++i)
    {
        for(int j = 0; j < nr_colms; ++j)
        {
            arr[i][j] = 2*j;
        }
    }
    return(SUCCESS);
}


void print_my_array(int arr[N1][N2], int nr_rows, int nr_colms)
{
    for(int i = 0; i < nr_rows; ++i)
    {
        for(int j = 0; j < nr_colms; ++j)
        {
            printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
        }
    }
}

int find_summation_of_row(int arr[N1][N2], int nr_rows, int nr_colms, int row_number, int* row_total)
{
    int sum;
    
    if(row_number > nr_rows)
    {
        return(FAILURE);
    }
    for(int j = 0; j < nr_colms; ++j )
    {
        sum = sum + arr[row_number][j];
    }
    *row_total = sum;
    return(SUCCESS);
}


int find_summation_of_column(int arr[N1][N2], int nr_rows, int nr_colms, int col_number, int* column_total)
{
    int sum;
    if(col_number > nr_colms)   
    {
        return(FAILURE);
    }
    for(int i = 0; i < nr_rows; ++i)
    {
        sum = sum + arr[i][col_number];
    }
    *column_total = sum;
    return(SUCCESS);
}