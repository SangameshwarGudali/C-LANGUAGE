#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N1 3
#define N2 2
#define SUCCESS 1
#define INVALID_ROW_NUMBER 2
#define INVALID_COLUMN_NUMBER 3

void set_matrix_value(int array[N1][N2], int rows, int columns);
void print_value_in_matrix(int array[N1][N2], int rows, int columns);
int summation_of_row(int array[N1][N2], int row, int columns, int row_number, int* p_sum_value);
int summation_of_columns(int array[N1][N2], int row, int columns, int column_number, int* p_sum_value);

int i;
int j;
int ret;

int main(void)
{
    int A[N1][N2];
    int sum = 0;
    
    set_matrix_value(A, N1, N2);
    print_value_in_matrix(A, N1, N2);
    
    ret = summation_of_row(A, N1, N2, 5, &sum);
    if(ret == INVALID_ROW_NUMBER)
    {
        printf("Please Enter valid row number\n");
    }
    
    ret = summation_of_columns(A, N1, N2, 1, &sum);
    if(ret == INVALID_COLUMN_NUMBER)
    {
        puts("Please Enter valid columnn number");
    }

    printf("summation of row =%d\n", sum);
    printf("summation of column = %d\n", sum);

    exit(EXIT_SUCCESS);
}

void set_matrix_value(int array[N1][N2], int rows, int columns)
{
    int i=0, j=0;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            array[i][j] = i*5;
        }
    }
}

void print_value_in_matrix(int array[N1][N2], int rows, int columns)
{
    int i=0, j=0;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<columns; j++)
        {
            printf("arr[%d][%d] = %d\n", i, j, array[i][j]);
        }
    }
}

int summation_of_row(int array[N1][N2], int row, int columns, int row_number, int* p_sum_value)
{
    int sum = 0;
    if(row_number >= row)
    {
        return(INVALID_ROW_NUMBER);
    }
    for(j=0; j<columns; j++)
    {
        sum = sum + array[row_number][j];
    }
    *p_sum_value = sum;
    return(SUCCESS);
}

int summation_of_columns(int array[N1][N2], int row, int columns, int column_number, int* p_sum_value)
{
    int sum = 0;
    if(column_number >= columns)
    {
        puts("invalid column number");
        return(INVALID_COLUMN_NUMBER);

    }
    for(i=0; i<row; i++)
    {
        sum = sum + array[i][column_number];
    }
    *p_sum_value = sum;
    return(SUCCESS);
}


