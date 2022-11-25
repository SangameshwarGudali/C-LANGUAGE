#include <stdio.h>
#include <stdlib.h>


int cpa_strlen(const char* p);
int string_ncompare_cs(const char* p_str_1, const char* p_str_2, long long int n);
int string_ncompare_ncs(const char* p_str_1, const char* p_str_2, long long int n);
int string_compare_cs(const char* p_str_1, const char* p_str_2);
int string_compare_ncs(const char* p_str_1, const char* p_str_2);

int get_concatenated_string(const char* p_str1, const char* p_str2, char** pp_str, long long int* p_cat_length);
void test_string_ncompare_cs(void);
void test_string_ncompare_ncs(void);
void test_string_compare_cs(void);
void test_string_compare_ncs(void);
void test_split_string(void);

int main(void)
{
    //test_string_ncompare_cs();
    //test_string_ncompare_ncs();
    //test_string_compare_cs();
    test_string_compare_ncs();
    return(0);
}

int cpa_strlen(const char* p)
{
    int i = 0;
    while(p[i] != '\0')
        ++i;
    return(i);
}

void test_string_ncompare_cs(void)
{
    int ret;
    char* name_1 = "SANG";
    char* name_2 = "SANGAMESHWAR";

    ret = string_ncompare_cs(name_1, name_2, 2);
    if(ret == 1)
        puts("string are same");
    else
        puts("string not matches");
}

int string_ncompare_cs(const char* p_str_1, const char* p_str_2, long long int n)
{
    long long int len_1;
    long long int len_2;
    int i;
    int flag;
    int N;
    int min_len;

    len_1 = cpa_strlen(p_str_1);
    len_2 = cpa_strlen(p_str_2);
    printf("len_1 = %lld\n", len_1);
    printf("len_2 = %lld\n", len_2);
    
    N = min(min(len_1, len_2), n);
    printf("min vlue = %d\n", N);
    for(i = 0; i < N; ++i)
        if(p_str_1[i] == p_str_2[i])
            flag = 1;
        else
            flag = 0;
    if(flag == 1)
        return(1);
    
    return(0);
    
}

void test_string_ncompare_ncs(void)
{
    char* name1 = "sangam";
    char* name2 = "SANGAMESH";
    int ret;

    ret = string_ncompare_ncs(name1, name2, 12);
    if(ret == 1)
        puts("string match");
    else
        puts("string dose not match");
}


int string_ncompare_ncs(const char* p_str_1, const char* p_str_2, long long int n)
{
    long long int len_1;
    long long int len_2;
    int i;
    int flag = 0;
    int N;
    int min_len;

    len_1 = cpa_strlen(p_str_1);
    len_2 = cpa_strlen(p_str_2);
    printf("len_1 = %lld\n", len_1);
    printf("len_2 = %lld\n", len_2);
    N = min(min(len_1, len_2), n);
    
    for(i = 0; i < N; ++i)
    {
        if(isalpha(p_str_1[i]))
            if(isupper(p_str_1[i]))
                if(p_str_1[i] == toupper(p_str_2[i]))
                    flag = 1;
                if(p_str_1[i] == tolower(p_str_2[i]))
                    flag = 1;
                else
                    flag = 0;
    }
    if(flag == 1)
        return(1);
    else
        return(0);
}

void test_string_compare_cs(void)
{
    char* name1 = "yogeshwar";
    char* name2 = "yogeshwar";
    int ret;

    ret = string_compare_cs(name1, name2);
    if(ret == 1)
        puts("string matches");
    else
        puts("string does not match");
    
}

int string_compare_cs(const char* p_str_1, const char* p_str_2)
{
    int N = 0;
    int len_1, len_2;
    int ret;

    len_1 = cpa_strlen(p_str_1);
    len_2 = cpa_strlen(p_str_2);
    printf("len1 = %d\n", len_1);
    printf("len2  = %d\n", len_2);
    
    N = min(len_1, len_2); 

    ret = string_ncompare_cs(p_str_1, p_str_2, N); 
    if(ret != 0)  
        return ret; 

    if(len_1 == len_2)
        return 0; 
    else if(len_1 > len_2)
        return 1; 
    else 
        return -1; 
}

void test_string_compare_ncs(void)
{
    char* name1 = "yogeshwar";
    char* name2 = "yogeshwar";
    int ret;

    ret = string_compare_ncs(name1, name2);
    if(ret == 1)
        puts("string matches");
    else
        puts("string does not match");
    
}


int string_compare_ncs(const char* p_str_1, const char* p_str_2)
{
    int N = 0;
    int len_1, len_2;
    int ret;

    len_1 = cpa_strlen(p_str_1);
    len_2 = cpa_strlen(p_str_2);
    printf("len1 = %d\n", len_1);
    printf("len2  = %d\n", len_2);
    
    N = min(len_1, len_2); 

    ret = string_ncompare_ncs(p_str_1, p_str_2, N); 
    if(ret != 0)  
        return ret; 

    if(len_1 == len_2)
        return 0; 
    else if(len_1 > len_2)
        return 1; 
    else 
        return -1; 
}

void test_concatenated_string(void)
{
    char* p_str1 = "core programming ";
    char* p_str2 = "Academy";
    long long int 

}

int get_concatenated_string(const char* p_str1, const char* p_str2, char** pp_str, long long int* p_cat_length)
{
    long long int len_p1;
    long long int len_p2;
    long long int total_len;

    char* p_cat = NULL;

    len_p1 = strlen(p_str1);
    len_p2 = strlen(p_str2);
    total_len = len_p1 + len_p2;

    p_cat = (char*)calloc(total_len + 1, sizeof(char));
    assert(p_cat != NULL);

    for(i = 0; i < len_p1; ++i)
        p_cat[i] = p_str1[i];

    for(i = 0; i < len_p1; ++i)    
        p_cat[i + len_p1] + p_str2[i];

    *(p_cat + total_len) = '\0';

    *pp_str = p_cat;
    *p_cat_length = total_len;
}

void test_split_string(void)
{
    char* name = "SHIV##KUMAR##CPA";
    char* p_sep = "##";
    char** pp_str = NULL;
    long long int size;

    ret = split_string(name, p_sep, &pp_str, &size);
    assert(ret);
    for(i = 0; i < size; ++i)
        printf("our splitted string = %s\n", pp_str[i]);
}

int split_string(const char* p_str, const char* p_sep, char***ppp_str, long long int* p_size)
{
    long long int len_pstr;
    long long int len_psep;
    int k;
    long long int start_index = 0;
    long long int end_index, component_len;
    char** pp_str = NULL;
    char* p_component = NULL;
    int size = 0;
    
    len_psep = cpa_strlen(p_sep);
    len_pstr = cpa_strlen(p_str);

    k = start_index;
    while(k < len_psep && p_str[k] != '\0')         // SHIV##KUMAR##CPA
    {
        flag = 1
        for(j = 0; p_sep[j] != '\0'; ++i)
        {
            if(p_str[j+k] != p_str[k])
            {
                flag = 0;
                break;
            }
        }

        if(flag == 1)
        {
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
            k = k + 1
        }
    }
**ppp_str = pp_str;
*p_size = size;
    
}