#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void *xmalloc(size_t size);
void *xcalloc(size_t nr_elements, size_t size_per_element);
void *xrealloc(void *old_ptr, size_t new_size_in_bytes);

size_t cpa_strlen(const char *p_str);
size_t cpa_strcpy(char *p_dest_str, const char *p_src_str);
size_t cpa_strcat(const char *p_src_str, const char *p_dest_str, char **pp_cat_str);
char *cpa_strbuilder(char *p_str, const char *append_str);

int main(void)
{
    char *msg = "This is interesting, isn't it?";
    size_t msg_len = 0;
    char *copy_msg = NULL;

    msg_len = cpa_strlen(msg);
    printf("msg_len = %llu\n", msg_len);

    copy_msg = (char *)xmalloc(msg_len + 1);
    cpa_strcpy(copy_msg, msg);

    printf("msg = %s\n", msg);
    printf("copy of msg = %s\n", copy_msg);

    free(copy_msg);
    copy_msg = NULL;

    const char *msg1 = "Hello";
    const char *msg2 = "World";
    char *msg3 = NULL;
    size_t msg3_len;
    msg3_len = cpa_strcat(msg1, msg2, &msg3);

    printf("msg3 = %s\n", msg3);
    printf("len(msg3) = %llu\n", msg3_len);

    free(msg3);
    msg3 = NULL;

    char *p_str = NULL;
    p_str = cpa_strbuilder(p_str, "Hello");
    printf("p_str = %s\n", p_str); // Hello
    p_str = cpa_strbuilder(p_str, ",");
    printf("p_str = %s\n", p_str); // Hello,
    p_str = cpa_strbuilder(p_str, "World");
    printf("p_str = %s\n", p_str); // Hello,World
    p_str = cpa_strbuilder(p_str, "!");
    printf("p_str = %s\n", p_str); // Hello,World!

    free(p_str);
    p_str = NULL;

    return (EXIT_SUCCESS);
}

size_t cpa_strlen(const char *p_str)
{
    size_t i;

    i = 0;
    while (*(p_str + i) != '\0')
        i = i + 1;

    return (i);
}

size_t cpa_strcpy(char *p_dest_str, const char *p_src_str)
{
    size_t src_len = cpa_strlen(p_src_str);
    size_t i;

    for (i = 0; i < src_len; ++i)
        p_dest_str[i] = p_src_str[i];

    *(p_dest_str + src_len) = '\0';

    return (src_len);
}

size_t cpa_strcat(const char *p_src_str, const char *p_dest_str, char **pp_cat_str)
{
    char *p_cat_str = NULL;
    size_t src_len, dest_len, cat_len;
    size_t i;

    src_len = cpa_strlen(p_src_str);
    dest_len = cpa_strlen(p_dest_str);
    cat_len = src_len + dest_len;
    p_cat_str = (char *)xmalloc(cat_len + 1);

    i = 0;
    while (i < src_len)
    {
        *(p_cat_str + i) = *(p_src_str + i);
        i = i + 1;
    }

    i = 0;
    while (i < dest_len)
    {
        *(p_cat_str + src_len + i) = *(p_dest_str + i);
        i = i + 1;
    }

    *(p_cat_str + cat_len) = '\0';
    *pp_cat_str = p_cat_str;

    return (cat_len);
}

char *cpa_strbuilder(char *p_str, const char *append_str)
{
    size_t current_length, additional_length, total_length;
    size_t i;

    current_length = (p_str == NULL) ? 0 : cpa_strlen(p_str);
    additional_length = (append_str == NULL) ? 0 : cpa_strlen(append_str);
    total_length = current_length + additional_length;
    p_str = (char *)xrealloc(p_str, total_length + 1);

    for (i = 0; i < additional_length; ++i)
        *(p_str + current_length + i) = *(append_str + i);
    *(p_str + total_length) = '\0';

    return (p_str);
}

void *xmalloc(size_t size)
{
    void *p = NULL;

    p = malloc(size);
    if (p == NULL)
    {
        fprintf(stderr, "malloc:fatal:out of virtual addrress space\n");
        exit(EXIT_FAILURE);
    }

    return (p);
}

void *xcalloc(size_t nr_elements, size_t size_per_element)
{
    void *p = NULL;

    p = calloc(nr_elements, size_per_element);
    if (p == NULL)
    {
        fprintf(stderr, "calloc:fatal:out of memory\n");
        exit(EXIT_FAILURE);
    }

    return (p);
}

void *xrealloc(void *old_ptr, size_t new_size_in_bytes)
{
    void *p = NULL;

    p = realloc(old_ptr, new_size_in_bytes);
    if (p == NULL)
    {
        fprintf(stderr, "fatal:realloc():resize failed\n");
        exit(EXIT_FAILURE);
    }

    return (p);
}
