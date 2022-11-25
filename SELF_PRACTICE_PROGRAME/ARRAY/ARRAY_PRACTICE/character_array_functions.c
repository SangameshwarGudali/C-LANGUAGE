#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

size_t cpa_strlen(const char* p_str);
size_t cpa_strcpy(char* dest, const char* src);
size_t cpa_strcat(const char* p_src_str, const char* p_dest_str, const char** p_cat_str);

int main(void)
{
    const char* name = "sangameshwar";
    const char* surname = "gudali";
    int len = 0;
    char* copy_name = NULL;
    char* fullname = NULL;

    len = cpa_strlen(name);
    printf("len = %d\n", len);

    copy_name = (char*)calloc(len, sizeof(char)+1);

    len = cpa_strcpy(copy_name, name);
    printf("copy name = %s\n", copy_name);

    len = cpa_strcat(name, surname, &fullname);
    printf("%s",fullname);
    printf("total len = %d\n", len);

    return(0);
}

size_t cpa_strlen(const char* p_str)
{
    int len = 0;
    int i;
    char temp;
    
    i = 0;
    while(1)
    {
        if(*(p_str+i)=='\0')
            break;
        len++;
        i++;
    }
    
   return(len);
}

size_t cpa_strcpy(char* dest, const char* src)
{
    size_t src_len = cpa_strlen(src);
    size_t i;

    for(i = 0; i < src_len; ++i)
    {
        dest[i] = src[i];
    }

    return(src_len);
}

size_t cpa_strcat(const char* p_src_str, const char* p_dest_str, const char** pp_cat_str)
{
    size_t src_len = 0;
    size_t dest_len = 0;
    size_t cat_len = 0;
    char* p_cat_str = NULL;
    int i;

    cat_len = cpa_strlen(p_src_str) + cpa_strlen(p_dest_str);

    p_cat_str = (char*)calloc(cat_len, sizeof(char)+1);

    i = 0;
    while(i < src_len)
    {
        *(p_cat_str + i) = *(p_src_str + i);
        i++;
    }

    i = 0;
    while(i < dest_len)
    {
        *(p_cat_str + src_len + i) = *(p_dest_str + i);
        i++;
    }

    *(p_cat_str + cat_len) = '\0';
    *pp_cat_str = p_cat_str;

    printf("%s\n",p_cat_str);
    return(cat_len);
}