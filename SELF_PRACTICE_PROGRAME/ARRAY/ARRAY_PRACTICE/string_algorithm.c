#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1

void *xmalloc(size_t nr_of_elements);
void *xrealloc(void *old_ptr, size_t new_size);
size_t cpa_strlen(const char *msg);
size_t cpa_strcpy(char *p_dest_str, const char *p_src_str);
size_t cpa_strcat(const char *p_src_str_1, const char *p_src_str_2, char **pp_cat_str);
char *cpa_str_builder(char *p_dest_str, char *p_src_str);

int main(int argc, char *argv[])
{
    int len = 0;
    char *msg = "sangameshwar";
    char *first_name = "java";
    char *last_name = "programming";
    char *copy_msg = NULL;
    char *get_name = NULL;
    char *p_str = NULL;

    len = cpa_strlen(msg);
    printf("lenth = %d\n", len);

    copy_msg = (char *)xmalloc(len + 1);
    len = cpa_strcpy(copy_msg, msg);
    printf("copy msg = %s\n", copy_msg);

    len = cpa_strcat(first_name, last_name, &get_name);
    printf("total len = %d\n", len);
    printf("full name = %s\n", get_name);

    p_str = cpa_str_builder(p_str, "hello ");
    p_str = cpa_str_builder(p_str, "sangameshwar ");
    p_str = cpa_str_builder(p_str, "How are you? ");
    p_str = cpa_str_builder(p_str, "is it fine everything? ");
    p_str = cpa_str_builder(p_str, "enjoy your life...! ");

    printf("append name = %s\n", p_str);

    return (0);
}

char *cpa_str_builder(char *p_str, char *append_str)
{
    int current_len = 0;
    int additional_len = 0;
    int total_len = 0;
    int i;

    if (p_str == NULL)
        current_len = 0;
    else
        current_len = cpa_strlen(p_str);

    if (append_str == NULL)
        additional_len = 0;
    else
        additional_len = cpa_strlen(append_str);

    total_len = current_len + additional_len;

    p_str = (char *)xrealloc(p_str, total_len + 1);

    i = 0;
    while (i < additional_len)
    {
        *(p_str + current_len + i) = *(append_str + i);
        i = i + 1;
    }
    *(p_str + total_len) = '\0';
    return (p_str);
}

size_t cpa_strcat(const char *p_src_str_1, const char *p_src_str_2, char **pp_cat_str)
{
    int i;
    size_t len_1;
    size_t len_2;
    size_t total_len;
    char *p_cat_str = NULL;

    len_1 = cpa_strlen(p_src_str_1);
    len_2 = cpa_strlen(p_src_str_2);

    total_len = len_1 + len_2;

    p_cat_str = (char *)xmalloc(total_len + 1);
    assert(p_cat_str != NULL);

    i = 0;
    while (i < len_1)
    {
        *(p_cat_str + i) = *(p_src_str_1 + i);
        i = i + 1;
    }

    i = 0;
    while (i < len_2)
    {
        *(p_cat_str + len_1 + i) = *(p_src_str_2 + i);
        i = i + 1;
    }

    *(p_cat_str + total_len) = '\0';
    *pp_cat_str = p_cat_str;

    return (total_len);
}

size_t cpa_strcpy(char *p_dest_str, const char *p_src_str)
{
    int i;
    int len = 0;
    len = cpa_strlen(p_src_str);
    for (i = 0; i < len; ++i)
        p_dest_str[i] = p_src_str[i];

    *(p_dest_str + len) = '\0';

    return (len);
}

size_t cpa_strlen(const char *p_str)
{
    int i;
    int len = 0;
    for (i = 0; p_str[i] != '\0'; ++i)
        len++;
    return (len);
}

void *xmalloc(size_t nr_of_elements)
{
    void *p = NULL;

    p = malloc(nr_of_elements);
    assert(p != NULL);

    return (p);
}

void *xrealloc(void *old_ptr, size_t new_size)
{
    void *p = NULL;

    p = realloc(old_ptr, new_size);
    assert(p != NULL);

    return (p);
}