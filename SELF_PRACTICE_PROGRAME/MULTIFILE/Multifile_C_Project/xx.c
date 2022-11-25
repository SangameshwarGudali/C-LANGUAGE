#include "header.h"

void test_string_append(void);
char* string_append(char* p_str, const char* p_append_str, long long int* n);
int cpa_strlen(const char* p_str_1);

int main(void)
{
    test_string_append();
    return(0);
}

int cpa_strlen(const char* p_str_1)
{
    int i = 0;
    
    while(p_str_1[i] != '\0')
    {
        i = i + 1;
    }

    return i;

}


void test_string_append(void)
{
    char* p_str1 = "yogeshwar";
    char* p_str2 = "shukla";
    char* p_append = NULL;
    long long int n = 0;
    int ret;

    printf("String before append = %s\n", p_str1);
  
    p_append = string_append(p_str1, p_str2, &n);
    assert(p_append != NULL);

    printf("After append string = %s\n", p_str1);

}


char* string_append(char* p_str, const char* p_append_str, long long int* n)
{
    long long int len_1;
    long long int len_2;
    long long int total_len;
    int i;
    char* p_str3 = NULL;

    len_1 = cpa_strlen(p_str);
    len_2 = cpa_strlen(p_append_str);
    total_len = len_1 + len_2;

    p_str3 = (char*)realloc(p_str, total_len+1);
    assert(p_str3 != NULL);

    for(i = 0; i < len_2; ++i)
        p_str3[len_1 + i] = p_append_str[i];
    
    p_str3[total_len + 1] = '\0';

    *n = total_len;

    return(p_str3);

}