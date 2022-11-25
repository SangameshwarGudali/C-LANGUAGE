#include <stdio.h>
#include <stdlib.h>
int string_ncompare_cs(const char* p_str_1, const char* p_str_2, long long int n);
void test_string_ncompare(void);
int cpa_strlen(const char* p);

int main(void)
{
    test_string_ncompare();
    return(0);
}

int cpa_strlen(const char* p)
{
    int i = 0;
    while(p[i] != '\0')
        i = i + 1;
    return(i);
}

void test_string_ncompare(void)
{
    char* p_str1 = "shivkumarople";
    char* p_str2 = "shivr";
    long long int N = 13;
    int ret;

    ret = string_ncompare_cs(p_str1, p_str2, N);
    if(ret == 1)
        puts("string match");
    else
        puts("sting not match");
}

int string_ncompare_cs(const char* p_str_1, const char* p_str_2, long long int n)
{
    long long int len_1;
    long long int len_2;
    int i, j;
    int flag;
    int N;
    int min_len;

    len_1 = cpa_strlen(p_str_1);
    len_2 = cpa_strlen(p_str_2);
    printf("len_1 = %lld\n", len_1);
    printf("len_2 = %lld\n", len_2);
    N = min(min(len_1, len_2), n);
    printf("min vlue = %d\n", N);
    
    if(len_1 > len_2)
    {
        for(i = 0; i < N; ++i)
        {
            flag = 1;
            for(j = 0; j < N; ++j)
            {
                if(p_str_1[i+j] != p_str_2[j])
                    flag = 0;
            }
        }
    }
    
    else
    {
        for(i = 0; i < N; ++i)
        {
            flag = 1;
            for(j = 0; j < N; ++j)
            {
                if(p_str_2[i+j] != p_str_1[j])
                    flag = 0;
            }
        }
    }

    if(flag == 1)
        return (flag);

return (0);
    
}