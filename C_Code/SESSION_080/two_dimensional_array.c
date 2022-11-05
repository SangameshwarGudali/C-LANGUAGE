#include <stdio.h> 
#include <stdlib.h> 

#define N1  5 
#define N2  4 

#define SUCCESS                 1 
#define INVALID_ROW_NUMBER      2 
#define INVALID_COLOUMN_NUMBER  3 

void initialize(int [N1][N2], int nr_rows, int nr_cols); 
int sum_row(int [N1][N2], int nr_rows, int nr_cols, int row_number, int* p_row_sum); 
int sum_col(int [N1][N2], int nr_rows, int nr_cols, int col_number, int* p_col_sum); 

int main(void)
{
    int A[N1][N2]; 
    int sum; 
    int ret; 
    printf("main:A=%llu\n", (unsigned long long int)A); 
    initialize(A, N1, N2); 
    sum = 0; 
    ret = sum_row(A, N1, N2, 3, &sum);
    if(ret == INVALID_ROW_NUMBER)
    {
        printf("Row number is invalid. 0 <= row_number < %d\n", N1); 
        exit(EXIT_FAILURE); 
    } 
    printf("Sum(Row(3))=%d\n", sum); 
    sum = 0; 
    ret = sum_col(A, N1, N2, 2, &sum); 
    if(ret == INVALID_COLOUMN_NUMBER)
    {
        printf("Coloumn number invalid. 0 <= col_number < %d\n", N2); 
        exit(EXIT_FAILURE); 
    }
    printf("Sum(Coloumn(2))=%d\n", sum); 
    exit(EXIT_SUCCESS); 
}

void initialize(int A[N1][N2], int nr_rows, int nr_cols)
{
    int i, j; 
    for(i = 0; i < nr_rows; ++i)
    {
        for(j = 0; j < nr_cols; ++j)
        {
            A[i][j] = 3*i + 7*j; 
        }
    }
}

int sum_row(int A[N1][N2], int nr_rows, int nr_cols, int row_number, int* p_row_sum)
{
    int j; 
    int sum = 0; 
    printf("sum_row:A=%llu\n", (unsigned long long int)A); 
    if(row_number >= nr_rows)
    {
        return (INVALID_ROW_NUMBER); 
    }
    for(j = 0; j < nr_cols; ++j)
        sum = sum + A[row_number][j]; 
    *p_row_sum = sum; 
    return (SUCCESS); 
}

int sum_col(int A[N1][N2], int nr_rows, int nr_cols, int col_number, int* p_col_sum)
{
    int i; 
    int sum = 0; 
    if(col_number >= nr_cols)
    {
        return (INVALID_COLOUMN_NUMBER); 
    }
    for(i = 0; i < nr_rows; ++i)
        sum = sum + A[i][col_number]; 
    *p_col_sum = sum; 
    return (SUCCESS); 
}


    