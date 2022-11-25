int string_ncompare_cs(const char* p_str_1, const char* p_str_2, long long int n)
{
    // N = min( min(len(str1), len(str2)), n))
    // for(i = 0; i < N; ++i)
    //  compare p_str_1[i] and p_str_2[i]
    //  if the above comparison fails even once then return false 
    //  if the above comparison holds true for all then return true 
}

int string_ncompare_ncs(const char * p_str_1, const char* p_str_2, long long int n)
{
    // N = min( min(len(str1), len(str2)), n))
    // for(i = 0; i < N; ++i)
    //      compare p_str_1[i] and p_str_2[i] (NON-CASE-SENSETIVE COMPARISON)
    //  if(isalpha(p_str_1[i])) 
    //      if(isupper(p_str_1[i]))
    //          p_str_1[i] == toupper(p_str_2[i])
    //      else 
    //          p_str_1[i] == tolower(p_str_2[i])
    //  if the above comparison fails even once then return false 
    //  if the above comparison holds true for all then return true 
}

int string_compare_cs(const char* p_str_1, const char* p_str_2)
{
    //  N = min(len_1, len_2) where len_1 = cpa_strlen(p_str_1)
    //                              len_2 = cpa_strlen(p_str_2)

    //  ret = string_ncompare_cs(p_str_1, p_str_2, N); 
    //  if(ret != 0)  
    //      return ret; 

    //  if(len1 == len2)
    //      return 0; 
    //  else if(len1 > len2)
    //      return 1; 
    //  else 
    //      return -1; 
}

int stirng_compare_ncs(const char* p_str_1, const char* p_str_2)
{
    // same cs version, only, use ncs version of string_ncompare
    //  viz string_ncompare_ncs()
}

int get_concatenated_string(const char* p_str_1, const char* p_str_2, char** pp_str, 
                            long long int* p_cat_length); 
char* string_append(char* p_str, const char* p_append_str, long long int n); 

int string_multiply(char* p_str, long long int n, char** pp_str)
{
    // len = cpa_strlen(p_str)
    //  size = n * len;  
    //  char* p_new_str = malloc(size + 1);
    //  memset(p_new_str, 0, size+1);  
    //  for(i = 0; i < size; i = i + len)
    //      string_ncopy(p_new_str + i * len, p_str, len); 
    //  **pp_str = p_new_str; 
    //  return 1; 
}

int make_string_reverse(char* p_str)
{
    //  N = cpa_strlen(p_str); 
    //  for(i = 0; i < N/2; ++i)
    //      swap -> p_str[i] <-> p_str[N-1-i]; 
}

int get_reversed_string(char* p_str, char** pp_str)
{
    //  N = cpa_strlen(p_str); 
    //  char* p_new_str = (char*)malloc(N+1); 
    //  memset(p_new_str, 0, N+1); 
    //  for(i = N-1; i > -1; i--)
    //      p_new_str[i - N + 1] = p_str[i]
    //  **p_str =  p_new_str; 
}

int string_copy(char* p_destination_str, const char* p_source_string, long long int n)
{
    //  src_len = cpa_strlen(p_source_string); 
    //  N = min(src_len, n) 
    //  for(i = 0; i < N; ++i)
    //      p_destination_str[i] = p_source_string[i]; 
    //  p_destination_str[N] = '\0'; 
    //  return 1 
}

char* clone_string(char* p_str)
{
    //  len_1 = cpa_strlen(p_str); 
    //  char* p_new_string = malloc(len_1 + 1); 
    //  memset(p_new_string, 0, len_1 + 1); 
    //  string_ncopy(p_new_string, p_str, len_1); 
    //  return p_new_string
}

char* get_upper_string(const char* p_str)
{
    // TODO
}

int make_string_upper(char* p_str)
{
    // TODO
}

char* get_lower_string(const char* p_str)
{
    // TODO
}

int make_string_lower(char* p_str)
{
    // TODO
}

char* get_title_case_string(const char* p_str)
{
    // core programming academy 
    //  Core Programming Academy 
    //  core                    programming                      Academy
    //  Core                    Programming                      Academy
}

int make_string_title_case(char* p_str)
{
    int IN = 1; 
    int OUT = 2; 
    int state; 
    long long int i; 
    
    state = OUT; 
    for(i = 0; p_str[i] != '\0'; ++i)
    {
        if(state == OUT && !isspace(p_str[i]))
        {
            state = IN; 
            if(islower(p_str[i]))
                p_str[i] = toupper(p_str[i]); 
        }
        else if(state == IN && isspace(p_str[i]))
        {
            state = OUT; 
        }
    }
}

char* get_lstripped_string(const char* p_str)
{
    
}

int make_lstripped_string(char* p_str)
{

}

char* get_rstripped_string(const char* p_str)
{
    
}

int make_rstripped_string(char* p_str)
{

}

char* get_stripped_string(const char* p_str)
{

}

int make_stripped_string(char* p_str)
{

}

char* get_case_swapped_string(const char* p_str)
{

}

int make_string_case_swapped(const char* p_str)
{

}

int join(const char** pp_strings, const char* p_sep, const char** pp_joined_str) 
{

}

int startswith(const char* p_str, const char* p_prefix_str)
{

}

int endswith(const char* p_str, const char* p_suffix_str)
{

}

int remove_prefix(char* p_str, char* p_prefix); 
int remove_suffix(char* p_str, char* p_suffix); 

int is_string_alpha(const char* p_str); 
int is_string_digit(const char* p_str); 
int is_string_alnum(const char* p_str); 
int is_string_decimal(const char* p_str); 
int is_string_identifier(const char* p_str); 
int is_string_lower(const char* p_str); 
int is_string_upper(const char* p_str); 
int is_string_title(const char* p_str); 
int is_string_printable(const char* p_str); 

int get_substring_by_slice(const char* p_str, long long int len, long long int start_index, long long int end_index, 
                            long long int step, char* pp_str);