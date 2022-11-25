#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

int cpa_strlen(const char* p_str_1);
int string_multiply(char* p_str, long long int n, char** pp_str);
void test_string_multiply(void);


int main(void)
{
    test_string_multiply();
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

void test_string_multiply(void)
{
    char* p_str1 = "SHIV";
    long long int n = 5;
    char* p_str2 = NULL;
    int ret, i;

    ret = string_multiply(p_str1, n, &p_str2);
    assert(ret);

    printf("p_str2[%d] = %s", i, p_str2);
}

int string_multiply(char* p_str1, long long int n, char** pp_str)
{
    long long int len1;
    int size ;
    char* p_str = NULL;
    int ret;
    
    len1 = cpa_strlen(p_str1);
    size = n * len1;

    p_str = (char*)malloc(size + 1);
    assert(p_str != NULL);

    int i;

  
    for(i = 0; i < size; i = i + len1)
    {
        ret = string_ncopy(p_str + i * len1, p_str1, len1);
        asset(ret);
    }
    *pp_str =  p_str;
    return(1);

    // len = cpa_strlen(p_str)
    //  size = n * len;  
    //  char* p_new_str = malloc(size + 1);
    //  memset(p_new_str, 0, size+1);  
    //  for(i = 0; i < size; i = i + len)
    //      string_ncopy(p_new_str + i * len, p_str, len); 
    //  **pp_str = p_new_str; 
    //  return 1; 
}

int string_ncopy(char* p_str1, char* p_str2, long long int len)
{
    int i;
    for(i = 0; i < len; ++i)
        p_str1[i] = p_str2[i];
    return(SUCCESS);
}