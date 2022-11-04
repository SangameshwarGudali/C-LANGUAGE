/* 
    S1: Accept array size from user. 
    S2: Validate the size. 
    S3: Allocate array of integer 
        of the user entered 'array_size' 
    S4: Take every value of array from 
        end user (i.e. use scanf() for 
        all array elements)
    
    S5: Display the array 

    
    Beginners: 
        S6: Write a logic to 
            calculate the sum of all 
            elements in array 
        
            Display the sum 

        S7: Free array and exit 

    Experienced: 
        S6: Write a logic to SORT elements in 
            array 
        S7: Display sorted array 
        S8: Free array and exit 
*/ 

/* 
PSEUDOCODE of sorting algo 

for j = 0 to j = N-1
{ 
    key = A[j] 
    i = j - 1 
    while i > -1 and A[i] > key
    {
        A[i+1] = A[i]
        i = i - 1 
    }
    A[i+1] = key
}
*/ 