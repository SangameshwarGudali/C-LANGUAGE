void merge(int* a, int p, int q, int r)
{
    int i, j, k; 
    int* pa1=(void*)0, *pa2=(void*)0;
    int n1, n2; 

    n1 = q - p + 1; 
    n2 = r - q; 

    pa1 = (int*)malloc(n1 * sizeof(int)); 
    assert(pa1); 

    pa2 = (int*)malloc(n2 * sizeof(int)); 
    assert(pa2); 

    for(i = 0; i < n1; ++i)
        pa1[i] = a[p+i]; 
    for(i = 0; i < n2; ++i)
        pa2[i] = a[q+1+i]; 

    i = 0; 
    j = 0; 
    k = 0; 

    while(1)
    {
        if(pa1[i] <= pa2[j]
        {
            a[p+k++] = pa1[i++]; 
            if(i == n1)
            {
                while(j < n2)
                {
                    a[p+k++] = pa2[j++]; 
                }
            }
        }
    }


}

/* 
    CISC MICROPROCESSOR 
    ASSEMBLY -> 
    auto increment 
    auto decrement 
    movl %r1, (%r0)++ 
    movl %r2, ++(%r0)
    ++i; 
    i++;
    i--; 
    --j 
*/ 