void insertion_sort(int*, int); 

int main(void)
{
    int a[5] = {100, 80, 60, 40, 20}; 
    insertion_sort(a, 5); 
    return (0); 
}

void insertion_sort(int* pa, int N)
{
    int i, j, key; 
    for(j = 1; j < N; ++j)
    {
        key = pa[j]; 
        i = j-1; 
        while(i > -1 && pa[i] > key)
        {
            pa[i+1] = pa[i]; 
            i = i - 1; 
        }
        pa[i+1] = key; 
    }
}