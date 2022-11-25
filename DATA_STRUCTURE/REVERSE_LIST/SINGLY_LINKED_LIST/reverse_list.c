#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1
#define LIST_EMPTY 2

typedef int data_t;
typedef int status_t;
typedef struct node node_t;
typedef node_t list_t;

struct node
{
    data_t data;
    struct node *next;
};

/* helper function declaration */

list_t *create_list(void);
node_t *get_new_node(data_t new_data);
void show_list(list_t *p_list, const char *msg);

/* interface function declarations */
status_t insert_at_start(list_t *p_list, data_t new_data);
status_t reverse_list(list_t *p_list);
status_t insert_at_end(list_t *p_list, data_t new_data);

/* auxilary function declarations */
void *xcalloc(size_t nr_elements, size_t size_in_bytes);

int main(void)
{
    int i;
    int status;
    list_t *p_list = NULL;

    p_list = create_list();
    for (i = 10; i <= 100; i = i + 10)
    {
        status = insert_at_end(p_list, i);
        assert(status == SUCCESS);
    }
    show_list(p_list, "insert at end");
    status = reverse_list(p_list);
    show_list(p_list, "reverse list");

    free(p_list);
    p_list = NULL;

    return (0);
}

list_t *create_list(void)
{
    list_t *p_list = NULL;

    p_list = get_new_node(-1);
    p_list->next = p_list;
    return (p_list);
}

node_t *get_new_node(data_t new_data)
{
    node_t *p_new_node = NULL;

    p_new_node = (node_t *)xcalloc(1, sizeof(node_t));
    assert(p_new_node != NULL);
    p_new_node->data = new_data;

    return (p_new_node);
}

status_t insert_at_start(list_t *p_list, data_t new_data)
{
    node_t *p_new_node = NULL;

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_list->next;
    p_list->next = p_new_node;

    return (SUCCESS);
}

status_t insert_at_end(list_t *p_list, data_t new_data)
{
    node_t *p_run = NULL;
    node_t *p_new_node = NULL;

    p_run = p_list;
    while (p_run->next != p_list)
        p_run = p_run->next;
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_run->next = p_new_node;

    return (SUCCESS);
}

status_t reverse_list(list_t *p_list)
{
    node_t *p_run = NULL;
    list_t *p_dummy = NULL;

    p_dummy = create_list();
    p_run = p_list->next;
    while (p_run->next != p_list)
    {
        p_dummy->next->data = p_run->data;
        p_run = p_run->next;
        p_dummy = p_dummy->next;
    }

    while (p_dummy->next != p_list)
    {
        insert_at_start(p_list, p_dummy->data);
    }

    return (SUCCESS);
}

void show_list(list_t *p_list, const char *msg)
{
    node_t *p_run = NULL;

    printf("[START]->");
    if (msg)
        puts(msg);

    p_run = p_list->next;
    while (p_run != p_list)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n\n");
}

void *xcalloc(size_t nr_elements, size_t size_in_bytes)
{
    void *p = NULL;

    p = calloc(nr_elements, size_in_bytes);
    assert(p != NULL);

    return (p);
}