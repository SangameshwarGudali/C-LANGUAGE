[1] multidimensional array 
    int* p = malloc(m * n * sizeof(int)); 

    for(i = 0; i < m; ++i )
        for(j = 0; j < n; ++j )
            *(p + i * n + j) -> a[i][j]

    n1 x n2 x n3 

    for(i=0; i<n1; ++i)
        for(j=0; j<n2; ++j)
            for(k=0; k<n3; ++k)
                *(p+i*n2*n3+j*n3+k)

[2] union/enum 

[3] volatile, restrict 

[4] va_start, va_arg, va_end 

[5] goto 
#-------------------------------------------------------

