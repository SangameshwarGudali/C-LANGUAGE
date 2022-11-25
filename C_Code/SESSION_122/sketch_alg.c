int cpa_strcat(const char* p1, const char* p2, char** pp_str, long long int* p_size)
{
    // compute len_1 of p1 
    // compute len_2 of p2 
    // new string requires len_1 + len_2 + 1 -> number of chars 
    // char* p3 = calloc(1, len_1 + len_2 + 1); 
    // p3[0...len_1-1] = string(p1)
    // p3[len_1...len_2-1] = string(p2)
    // p3[len_1+len_2] = '\0' 
    // *pp_str = p3 
    // *p_size = len_1 + len_2; 

}