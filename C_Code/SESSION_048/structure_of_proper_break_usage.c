/* Syntaxwise, you can put the break statement inside while/for loop. 
    But if you put the break statement inside the while/for loop 
    unconditionally then the loop effect of the loop statement 
    is nullified. 
    (Because you will break out of the loop in the first repetition itself!)

int main(void)
{
    int index; 
    int N; 

    index = 0; 
    while(index < N)    
    {
        st; 
        st; 
        st; 
        st; 
        // break can occur in if block 
        if(COND)
        {
            break; 
        }

        st; 
        st; 
        st; 
        st; 
        index = index + 1; 
    }

    index = 0; 
    while(index < N)    
    {
        st; 
        st; 
        st; 
        st; 

        if(COND)
        {
            st; 
            st; 
            st; 
        }
        // break can occur in else block 
        else 
        {
            break; 
        }

        st; 
        st; 
        st; 
        st; 
        index = index + 1; 
    }
    
    // break can occru in else if block 
    index = 0; 
    while(index < N)    
    {
        st; 
        st; 
        st; 
        st; 

        if(COND)
        {
            st; 
            st; 
            st; 
        }
        else if (COND)
        {
            st; 
            st;
            st;
        }
        else if(COND)
        {
            st; 
            st; 
            break; 
        }
        else
        {
            st; 
            st; 
            st; 
        }

        st; 
        st; 
        st; 
        st; 
        index = index + 1; 
    }

}

/****************************************/ 

/* 
int main(void)
{
    int index; 
    int N; 

    for(index = 0; index < N; index = index + 1)
    {
        st; 
        st;
        st; 
        if(COND)
        {
            break; 
        }
        st; 
        st; 
        st; 
    }

    for(index = 0; index < N; index = index + 1)
    {
        st; 
        st;
        st; 
        if(COND)
        {
            st; 
            st; 
            st; 
        }
        else
        {
            break; 
        }
        st; 
        st; 
        st; 
    }
    
    for(index = 0; index < N; index = index + 1)
    {
        st; 
        st;
        st; 
        if(COND)
        {
            st; 
            st; 
            st; 
        }
        else if (COND)
        {
            st; 
            st; 
            st; 
        }
        else if (COND)
        {
            st; 
            st; 
            break; 
        }
        else
        {

        }
        st; 
        st; 
        st; 
    }
}
*/ 

/* What is true for break, is true for continue also */ 
/* Why?*/ 

int main(void)
{
    int index;
    int N;  
    for(index = 0; index <= N-1; index = index + 1)
    {
        st; 
        st; 
        st; 
        continue; 
        // unconditional continue here will always skip 
        // these statements! 
        st; 
        st; 
        st; 
    }
} 

