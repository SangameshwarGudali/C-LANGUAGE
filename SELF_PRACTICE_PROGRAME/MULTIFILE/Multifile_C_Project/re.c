#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1

#include "genheadfil.h"



int string_ncompare_cs(const char* p_str_1, const char* p_str_2, long long int n);
int string_ncompare_ncs(const char* p_str_1, const char* p_str_2, long long int n);
int get_concatenated_string(const char* p_str_1, const char* p_str_2, char** pp_str, long long int* p_cat_length); 
int string_append(char* p_str, const char* p_append_str, long long int n);

int cpa_strlen(const char* p_str_1);
void* xrealloc(void* old_ptr, size_t new_size);
void test_string_ncompare_cs(void);
void test_string_ncompare_ncs(void);

void test_string_compare_cs(void);
void test_string_compare_ncs(void);

void test_get_concatenated_string(void);
void test_string_append(void);


int main(void)
{
    //test_string_ncompare_cs();   
    //test_string_ncompare_ncs();
    //test_string_compare_cs();      // To Do
    //test_string_compare_ncs();   // To Do
    //test_get_concatenated_string();
    test_string_append();

    return (0);
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

int string_ncompare_cs(const char* p_str_1, const char* p_str_2, long long int n)
{
    // N = min( min(len(str1), len(str2)), n))
    // for(i = 0; i < N; ++i)
    //  compare p_str_1[i] and p_str_2[i]
    //  if the above comparison fails even once then return false 
    //  if the above comparison holds true for all then return true 

    long long int str1_len = cpa_strlen(p_str_1);
    long long int str2_len = cpa_strlen(p_str_2);
    int N;
    int i;
    int flag;

    N = min( min(str1_len, str2_len), n); 

    printf("Length of str1 = %lld, str2 = %lld, n = %lld\n", str1_len, str2_len, n);

    for(i = 0; i < N; ++i)
    {
        if (p_str_1[i] != p_str_2[i])
            return (0);
    }    

    return (1);
}

//To Do
int string_compare_cs(const char* p_str_1, const char* p_str_2)
{
    int i;
    long long int str1_len = cpa_strlen(p_str_1);
    long long int str2_len = cpa_strlen(p_str_2);
    long long int N;
    int ret;
    int value1, value2;

    N = min(str1_len, str2_len);

    for(i = 0; i < N; ++i)
    {
        if (p_str_1[i] != p_str_2[i])
        {
            value1 = (int)p_str_1[i];
            value2 = (int)p_str_2[i];
            if(value1 > value2)
                return(1);
            else
                return(-1);
        }
        else if(p_str_1[i] == p_str_2[i])
            return(0);
    }   
    
    return(0);
}

/*
//To Do
int string_compare_ncs(const char* p_str_1, const char* p_str_2)
{   
    return(0);
}
*/

int string_ncompare_ncs(const char* p_str_1, const char* p_str_2, long long int n)
{
    long long int str1_len = 0;
    long long int str2_len = 0;
    int N = 0;
    int flag;

    str1_len = cpa_strlen(p_str_1);
    str2_len = cpa_strlen(p_str_2);

    N = min(min(str1_len, str2_len), n);

    printf("Length of str1 = %lld, str2 = %lld, n = %lld\n", str1_len, str2_len, n);
    
    int i;
    for(i = 0; i < N; ++i)
    {
        if(isalpha(p_str_1[i]))
            if(isupper(p_str_1[i]))
                if(p_str_1[i] == toupper(p_str_2[i]))
                    flag = 1;
                else
                    flag = 0;
            else if(islower(p_str_1[i]))
                if(p_str_1[i] == tolower(p_str_2[i]))
                    flag = 1;
                else
                    flag = 0;
            else
                return(0);  
        else
            if(p_str_1[i] == p_str_2[i])
                flag = 1;
            else
                return(0);
    }
    
    if(flag == 1)
        return (1);
        
    return (0);
    
}


int get_concatenated_string(const char* p_str_1, const char* p_str_2, char** pp_str, long long int* p_cat_length)
{
    long long int len_1 = cpa_strlen(p_str_1);
    long long int len_2 = cpa_strlen(p_str_2);
    char* p_str = NULL;
    long long int total_length;
    int i;

    total_length = len_1 + len_2;

    p_str = (char*)calloc(total_length, sizeof(char) + 1);
    assert(p_str != NULL);

    for(i = 0; i < len_1; ++i)
    {
        p_str[i] = p_str_1[i];
    }

    for(i = 0; i < len_2; ++i)
    {
        p_str[len_1 + i] = p_str_2[i];
    }

    p_str[total_length + 1] = '\0';

    *pp_str = p_str;
    *p_cat_length = total_length;

    return (SUCCESS);
}

void test_string_ncompare_cs(void)
{
    char* str1 = "sangmesh";
    char* str2 = "Sangmesh";
    int n = 5;
    int ret;

    ret = string_ncompare_cs(str1, str2, n);

    if(ret == 1)
        puts("String match - case sensitive");
    else
        puts("String not matched - case sensitive");
}   

void test_string_ncompare_ncs(void)
{
    char* p_str1 = "sh kumar";
    char* p_str2 = "shk";
    long long int n = 5;
    int ret;

    ret = string_ncompare_ncs(p_str1, p_str2, n);

    if(ret == 1)
        puts("string match - ncs");
    else
        puts("string not match - ncs");

}   

/*

void test_string_compare_cs(void)
{
    char* p_str_1 = "Sangmeshwar";
    char* p_str_2 = "Sahg";
    int ret;

    ret = string_compare_cs(p_str_1, p_str_2);

    if(ret == 0)
        puts("String length is equal");
    if(ret == 1)
        puts("str1 > str2");
    if(ret == -1)
        puts("str1 < str2");

}


void test_string_compare_ncs(void)
{
    return (0);
}

*/

void test_get_concatenated_string(void)
{
    char* p_str_1 = "India";
    char* p_str_2 = "Is My Country";
    char* p_cat_str = NULL;
    long long int cat_length = 0;
    int ret;

    ret = get_concatenated_string(p_str_1, p_str_2, &p_cat_str, &cat_length);
    assert(ret);

    printf("Concatenated string is %s\n", p_cat_str);
}


void test_string_append(void)
{
    int i;
    char* p_str1 = NULL;

    p_str1 = malloc(sizeof(char) * 12);

    for(i = 0; i < 12; ++i)
    {
        p_str1[i] = i * 65;
    }

    char* p_str2 = "Shivkumar";
    char* p_str_append = NULL;
    
    long long int len_1;
    long long int len_2;
    long long int total_len;
    int ret;

    printf("p_str1 = %s\n", p_str1);
    printf("p_str2 = %s\n", p_str2);

    len_1 = cpa_strlen(p_str1);
    len_2 = cpa_strlen(p_str2);

    total_len = len_1 + len_2;

    ret = string_append(p_str1, p_str2, total_len);
    assert(ret);
    printf("Appended string = %s\n", p_str1);    

}

int string_append(char* p_str, const char* p_append_str, long long int n)
{

    long long int len_1;
    long long int len_2;
    long long int total_len;
    int i;

    len_1 = cpa_strlen(p_str);
    len_2 = cpa_strlen(p_append_str);


    p_str = (char*)realloc(p_str, sizeof(char) * n);
    assert(p_str != NULL);

    for(i = 0; i < len_2; ++i)
        p_str[len_1 + i] = p_append_str[i];
    return(SUCCESS);
}
