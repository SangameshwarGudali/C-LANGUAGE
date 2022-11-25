#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

char* allocate_string(long long int size); 
int cpa_strcpy(char* p_dest, const char* p_src); 
long long int cpa_strlen(const char* p); 
int cpa_strcat(const char* p_str_1, const char* p_str_2, char** pp_str, long long int* p_size);

// reverse the chars from i to j 
int make_string_range_reverse(char* p_str, long long int len, long long int i, long long int j);

// clone a string range from i to j - 1 and return it via pp_str
int get_substring_by_range(const char* p_str, long long int i, long long int j, char** pp_str, 
                            long long int* p_size); 
int get_substring_by_slice(const char* p_str, long long int i, long long int j, long long int k, 
                            char** pp_str, long long int* p_size); 
int is_substring(char* p_str, const char* substr); 
long long int count_substring_occurrences(const char* p_str, const char* p_substr); 
int split_string(const char* p_str, const char* p_sep, char*** ppp_str, long long int* p_size); 


void test_strcat(void); 
void test_make_string_range_reverse(void); 
void test_get_substring_by_range(void); 
void test_is_subtring(void); 
void test_count_substring_occurrences(void); 
void test_split_string(void); 

int main(void)
{
    char* p_src = "Core Programming Academy"; 
    char* p_dest = NULL; 
    long long int src_len = 0; 
    int ret; 

    src_len = cpa_strlen(p_src); 
    printf("src_len = %lld\n", src_len); 

    p_dest = calloc(1, src_len+1); 
    assert(p_dest); 

    ret = cpa_strcpy(p_dest, p_src); 
    assert(ret == 1); 
    printf("p_dest = %s\n", p_dest); 

    free(p_dest); 
    p_dest = NULL; 

    test_strcat(); 
    test_make_string_range_reverse(); 
    test_get_substring_by_range(); 
    test_is_subtring(); 
    test_count_substring_occurrences(); 
    test_split_string(); 

    return (0); 
}

char* allocate_string(long long int size)
{
    assert(size > 0); 
    return ((char*)calloc(1, size)); 
}

int cpa_strcpy(char* p_dest, const char* p_src)
{   
    // assumption: p_dest contains a valid address 
    // of array whose length is at least as long as 
    // len(p_src) + 1
    long long int i; 

    for(i = 0; *(p_src + i) != '\0'; ++i)
        p_dest[i] = p_src[i]; 

    p_dest[i] = '\0'; 

    return (1); 
}

long long int cpa_strlen(const char* p)
{
    long long int i = 0; 

    while(*(p+i) != '\0')
        i = i + 1; 

    return (i); 
}

int cpa_strcat(const char* p1, const char* p2, char** pp_str, long long int* p_size)
{
    long long int len_1, len_2, len_total; 
    int ret; 
    char* p_cat = NULL; 

    len_1 = cpa_strlen(p1); 
    len_2 = cpa_strlen(p2); 
    len_total = len_1 + len_2 + 1; 

    p_cat = (char*)calloc(1, len_total); 
    assert(p_cat != NULL); 

    ret = cpa_strcpy(p_cat, p1); 
    assert(ret); 
    ret = cpa_strcpy(p_cat + len_1, p2); 
    assert(ret); 

    *(p_cat + len_total - 1) = '\0'; 

    *pp_str = p_cat; 
    *p_size = len_total - 1; 

    return (1); 
}

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

int get_substring_by_range(const char* p_str, long long int i, long long int j, 
                            char** pp_str, long long int* p_size)
{
    long long int range_len; 
    long long int len; 
    long long int k; 
    char* p_range_str= NULL; 

    len = cpa_strlen(p_str); 
    assert(0 <= i && i < len && 0 <= j && j < len && i < j);

    range_len = j - i; 
    p_range_str = (char*)calloc(1, range_len + 1); 
    assert(p_range_str != NULL); 

    for(k = 0; k < range_len; ++k)
        p_range_str[k] = p_str[i + k]; 
    *(p_range_str+k) = '\0'; 

    *pp_str = p_range_str; 
    *p_size = range_len; 

    return (1); 
}


int is_substring(char* p_str, const char* substr)
{ 
    long long int i, j;
    long long int len_substr, len_str; 
    int flag; 

    len_str = cpa_strlen(p_str); 
    len_substr = cpa_strlen(substr); 

    for(j = 0; j < len_str - len_substr + 1; ++j)
    {
        flag = 1; 
        
        for(i = 0; substr[i] != '\0'; ++i)
        {
            if(p_str[i+j] != substr[i])
            {
                flag = 0; 
                break; 
            }
        }

        if(flag)
            return (1); 
    } 
    
    return (0); 
}

long long int count_substring_occurrences(const char* p_str, const char* p_substr) 
{
    long long int i, j; 
    long long int cnt = 0; 
    int flag; 
    long long int len_str = cpa_strlen(p_str); 
    long long int len_substr = cpa_strlen(p_substr); 

    for(i = 0; i < len_str - len_substr + 1; ++i)
    {
        flag = 1; 
        for(j = 0; p_substr[j] != '\0'; ++j)
        {
            if(p_str[i+j] != p_substr[j])
            {
                flag = 0; 
                break; 
            }
        }

        if(flag == 1)
            ++cnt; 
    }
    return (cnt); 
}

int split_string(const char* p_str, 
                const char* p_sep, 
                char*** ppp_str, 
                long long int* p_size)
{
    char** pp_str = NULL; 
    long long int size = 0; 
    long long int start_index, end_index, k; 
    long long int component_len, i, sep_len, orig_str_len; 
    char* p_component; 
    int flag, j; 

    start_index = 0; 
    sep_len = cpa_strlen(p_sep); 
    orig_str_len = cpa_strlen(p_str);
    printf("origin len = %d\n", orig_str_len);

    k = start_index; 
    while(k < orig_str_len && p_str[k] != '\0') // SHIV##KUMAR##CPA
    {
        flag = 1;                               // 1
        for(j = 0; p_sep[j] != '\0'; ++j)       // TRUE p[j] = S
        {       
            if(p_str[k + j] != p_sep[j])        // p_str[0 + 0] ! = p_sep[0]
            {                                   //       if TURE
                flag = 0;                       //          flag = 0
                break;                          //          break;
            }
        }                                       

        if(flag == 1) // control flow will come after -> if(p_str[k+j] != p_sep[j]) block TRUE 
        {
            end_index = k-1;                                        // end_index = k-1; (k = 4-1) ; (k = 3)
            component_len = end_index - start_index + 1;            // (component_len = 3 - 0 + 1) // (4 = 3 - 0 + 1)
            p_component = (char*)calloc(1, component_len + 1);      // p_component = (char*)calloc(1, 4 + 1) 
            assert(p_component); 
            for(i = 0; i < component_len; ++i)                      // i = 0; i < 4; ++i
                p_component[i] = p_str[start_index + i];            //      p_component[0] = p_str[0 + 0]
            size += 1;                                              // size = 1
            pp_str = (char**)realloc(pp_str, size * sizeof(char*)); // pp_str =(char**)realloc(NULL,8)
            assert(pp_str);     
            pp_str[size-1] = p_component;                           // pp_str[1 - 1] = p_component;
            p_component = NULL;                                     // p_component = NULL
            start_index = end_index + sep_len + 1;                  // (start_index = -1 + 3 + 1) ; (k = 6)
            k = start_index;                                        // k = 3
        }
        else           // control flow will come from break statement after flag = 0;
        {
            k += 1; 
        }
    }

    *ppp_str = pp_str; 
    *p_size = size; 

    return (1); 
}

void test_strcat(void)
{
    char* p1 = "Hello"; 
    char* p2 = "World"; 
    char* p3 = NULL; 
    long long int len; 
    int ret; 
    long long int i; 

    ret = cpa_strcat(p1, p2, &p3, &len);
    assert(ret == 1); 
    puts("-------------------------------------"); 
    for(i = 0; i < len; ++i)
        printf("p3[%lld]:%c\n", i, p3[i]); 
    puts("-------------------------------------"); 
    free(p3); 
    p3 = NULL; 
}

void test_make_string_range_reverse(void)
{
    char* p = "Core Programming Academy"; 

    printf("p = %s\n", p); 
    make_string_range_reverse(p, cpa_strlen(p), 5, 15); 
    printf("p = %s\n", p); // output: Core gnimmargorP Academy 
    make_string_range_reverse(p, cpa_strlen(p), 5, 15); 
    printf("p = %s\n", p); // output: Core Programming Academy
}

// [a, b] | a <= n <= b. How many n's are there? b-a+1
// (a, b] | a < n <= b. How many n's are thre? b - a 
// [a, b) | a <= n < b. How many n's are there? b - a 
// (a, b) | a < n < b. How many n's are there? b - a - 1 

void test_get_substring_by_range(void)
{
    char* p = "Core Programming Academy"; 
    long long int len; 
    char* p_str = NULL; 
    int ret; 

    puts("In test_get_substring_by_range():"); 
    ret = get_substring_by_range(p, 5, 16, &p_str, &len); 
    assert(ret); 
    printf("p_str = %s\n", p_str); 
    
    free(p_str);    
    p_str = NULL; 
}

void test_is_subtring(void)
{
    int ret; 
    char* p_str = "Core Programming Academy"; 
    char* p_substr_1 = "Programming"; 
    char* p_substr_2 = "mm"; 
    char* p_substr_3 = "Acad"; 
    char* p_substr_4 = "XYZ"; 
    char* p_substr_5 = "P"; 

    printf("p_str:Core Programming Academy\n"); 
    ret = is_substring(p_str, p_substr_1); 
    assert(ret == 1); 
    puts("1:Programming:YES"); 

    ret = is_substring(p_str, p_substr_2); 
    assert(ret == 1); 
    puts("2:mm:YES"); 

    ret = is_substring(p_str, p_substr_3); 
    assert(ret == 1); 
    puts("3:Acad:YES"); 

    ret = is_substring(p_str, p_substr_4); 
    assert(ret == 0); 
    puts("4:XYZ:NO"); 

    ret = is_substring(p_str, p_substr_5); 
    assert(ret == 1); 
    puts("5:P:YES"); 
}

void test_count_substring_occurrences(void)
{
    char* p_str = "AAbbAABBBAACCCCAAADDPP"; 
    char* p_substr_1 = "AA"; 
    char* p_substr_2 = "BB"; 
    char* p_substr_3 = "CCC"; 
    char* p_substr_4 = "PP"; 
    long long int count; 

    count = count_substring_occurrences(p_str, p_substr_1); 
    printf("%s occurrs in %s, %lld times\n", p_str, p_substr_1, count); 

    count = count_substring_occurrences(p_str, p_substr_2); 
    printf("%s occurrs in %s, %lld times\n", p_str, p_substr_2, count); 

    count = count_substring_occurrences(p_str, p_substr_3); 
    printf("%s occurrs in %s, %lld times\n", p_str, p_substr_3, count); 

    count = count_substring_occurrences(p_str, p_substr_4); 
    printf("%s occurrs in %s, %lld times\n", p_str, p_substr_4, count); 
}

void test_split_string(void)
{
    char* p = "abc:pqr:lmn:jkl"; 
    char* sep = ":"; 
    char** pp_str = NULL; 
    long long int size = 0, i; 

    split_string(p, sep, &pp_str, &size); 
    for(i = 0; i < size; ++i)
        printf("component = %s\n", pp_str[i]); 

    for(i = 0; i < size; ++i)
        free(pp_str[i]); 

    free(pp_str); 
    pp_str = NULL; 
}