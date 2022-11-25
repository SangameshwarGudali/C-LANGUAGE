int make_string_range_reverse(char* p_str, long long int len, long long int i, long long int j)
{
    long long int mid;
    long long int cnt; 
    char tmp; 

    assert(0 <= i && i < len && 0 <= j && j < len && i < j);
    mid = (j-i+1)/2; 
    for(cnt = 0; cnt < mid; ++cnt)
    {
        tmp = p_str[i+cnt]; 
        p_str[i+cnt] = p_str[j-cnt]; 
        p_str[j-cnt] = tmp; 
    }
    
    return (1); 
}

int make_string_range_reverse(char* p_str, long long int len, long long int i, long long int j)
{
    long long int mid;
    long long int cnt;
    char temp;

    assert(0 <= i && < len && 0 <= j && len && i < len);

    mid = (j - i + 1) / 2;

    for(cnt = 0; cnt < mid; cnt++)
    {
        temp = p_str[i + cnt];
        p_str[i + cnt] = p_str[j - cnt];
        p_str[j - cnt] = temp;
    }

    return(0);
}

int make_string_range_reverse(char* p_str, long long int len, long long int i, long long int j)
{
    long long int mid;
    long long int cnt;
    char temp;

    assert(0 <= i && i < len && 0 <= j && j < len && i < j);

    mid = (j-i+1)/2;
    for(cnt = 0; cnt < mid; ++cnt)
    {
        temp = p_str[i+cnt];
        p_str[i+cnt] = p_str[j-cnt];
        p_str[j-cnt] = temp;
    }

    return(1);
    
}

Range 0 <= i && i < len && 0 <= j && j < len && i < j
Range 0 <= i && i < len && 0 <= j && j < len && i < j
Range 0 <= i && i < len && 0 <= j && j < len && i < j
Range 0 <= i && i < len && 0 <= j && j < len && i < j

int make_string_range_reverse(char* p_str, long long int len, long long int i, long long j)
{
    long long int mid;
    long long int cnt;
    char tmp;

    assert(0 < = i && i < len && 0 <= j < len && i < len)
    
    mid = (j-i+1)/2;
    for(cnt = 0; cnt < mid; cnt++)
    {
        tmp = p_str[i+cnt];
        p_str[i+cnt] = p_str[j-cnt];
        p_str[j-cnt] = tmp;
    }
}