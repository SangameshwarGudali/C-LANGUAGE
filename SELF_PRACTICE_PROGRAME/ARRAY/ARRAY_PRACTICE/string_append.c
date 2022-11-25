#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *cpa_builder(char *p_str, const char *append_str);
size_t cpa_strlen(const char *p_str);

int main(void)
{
    char *name = NULL;
    const char *surname = "GUDALI";
    char *fullname = NULL;

    name = cpa_builder(name, "hello");
    printf("full name = %s\n", name);

    free(fullname);
    fullname = NULL;

    return (0);
}

char *cpa_builder(char *p_str, const char *append_str)
{
    int i = 0;
    size_t p_str_len = 0;
    size_t append_str_len = 0;
    char *p_new_str = NULL;
    size_t total_str_len = 0;

    p_str_len = cpa_strlen(p_str);
    append_str_len = cpa_strlen(append_str);

    total_str_len = p_str_len + append_str_len;
    p_str = (char *)realloc(p_str, (total_str_len + 1));

    i = 0;
    while (i < append_str_len)
        *(p_str + p_str_len + i) = *(append_str + i);

    *(p_str + total_str_len) = '\0';
    return (p_str);
}

size_t cpa_strlen(const char *p_str)
{
    size_t i;
    size_t len = 0;

    i = 0;
    while (*(p_str + i) != '\0')
    {
        len++;
        i++;
    }
    return (len);
}
