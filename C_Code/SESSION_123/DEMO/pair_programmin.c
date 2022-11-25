#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_is_substring(void);
int cpa_strlen(const char* p);
int is_substring(char* p_str, const char* substr);
void test_count_substring_occureence(void);
long long int count_substring_occurrences(const char* p_str, const char* p_substr);
void test_split_string(void);
int split_string(const char* p_str, const char* p_sep, char*** ppp_str, long long int* p_size);


int main(void)
{
    //test_is_substring();
    //test_count_substring_occureence();
    test_split_string();
    return(0);
}

void test_is_substring(void)
{
    char* name = "shivkumar";
    char* p_sub = "vk";
    int ret;

    ret = is_substring(name, p_sub);
    if(ret == 1)
        puts("sting match");
    else
        puts("sting not match");
}

int cpa_strlen(const char* p)
{
    int i = 0;
    while(p[i] != '\0')
        ++i;
    return(i);
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
            if(p_str[j + i] != substr[i])
            {
                flag = 0; 
                break; 
            }
            puts("Inside nested for, after if block");
        }

        if(flag)
            return (1); 
    } 
    
    return (0); 
}


void test_count_substring_occureence(void)
{
    char* name = "sangameshwar";
    char* p_sub = "sangameshwar";
    int count;

    count = count_substring_occurrences(name, p_sub);
    printf("count = %d\n", count);
        
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
/*
void test_split_string(void)
{
    char* name  = "SHIV##KUMAR##CPA##";
    char* p_sep = "##";
    char** pp_str = NULL;
    long long int size;
    int ret;
    int i;

    ret = split_string(name, p_sep, &pp_str, &size);
    for(i = 0; i < size; ++i)
        printf("our splitted string = %s\n", pp_str[i]);

}

/*


int split_string(const char* p_str, const char* p_sep, char*** ppp_str, long long int* p_size)
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
    printf("origin len = %lld\n", orig_str_len);

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

*/

void test_split_string(void)
{
    char* name = "SHIV##KUMAR##CPA";
    char* p_sep = "##";
    char** pp_str = NULL;
    long long int size;
    int ret, i;
    ret = split_string(name, p_sep, &pp_str, &size);
    assert(ret);
    for(i = 0; i < size; ++i)
        printf("our splitted string = %s\n", pp_str[i]);
}

int split_string(const char* p_str, const char* p_sep, char***ppp_str, long long int* p_size)
{
    long long int len_pstr;
    long long int len_psep;
    int i, j, k;
    long long int start_index = 0;
    long long int end_index, component_len, flag;
    char** pp_str = NULL;
    char* p_component = NULL;
    int size = 0;
    
    len_psep = cpa_strlen(p_sep);
    len_pstr = cpa_strlen(p_str);

    k = start_index;
    while(k < len_psep && p_str[k] != '\0')         // SHIV##KUMAR##CPA
    {
        flag = 1;
        for(j = 0; p_sep[j] != '\0'; ++j)
        {
            puts("inside for");
            if(p_str[j+k] != p_sep[j])
            {
                puts("inside if");
                flag = 0;
                break;
            }
        }

        if(flag == 1)
        {
            puts("inside down if");
            end_index = k - 1;
            component_len = end_index - start_index + 1;

            p_component = (char*)calloc(1, component_len+1);
            assert(p_component);
            for(i = 0; i < component_len; ++i)
                p_component[i] = p_str[start_index + i];
            size = size + 1;
            pp_str = (char**)realloc(pp_str, size * sizeof(char*));
            pp_str[size - 1] = p_component;
            p_component = NULL;
            start_index = end_index + len_psep + 1;
            k = start_index;
        }

        else
        {
            puts("inside down else");
            k = k + 1;
        }
    }
*ppp_str = pp_str;
*p_size = size;

return(1);
    
}