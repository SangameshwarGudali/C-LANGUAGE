#include <stdio.h>

#ifndef _LIST_H
#define _LIST_H

#define TRUE            1
#define FALSE           0
#define LIST_NOT_FOUND  2
#define LIST_IS_EMPTY   3

typedef int status_t;
typedef int data_t;

typedef struct node node_t;
typedef node_t list_t;

struct node
{
    data_t data;
    struct node* prev;
    struct node* next;
};

/* interface routines */

list_t* create_list(void);
status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data);

status_t get_start(list_t* p_list, data_t* p_start_data);
status_t get_end(list_t* p_list, data_t* p_end_data);

status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);

status_t remove_first(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t e_data);

status_t is_list_empty(list_t* p_list);
len_t get_length(list_t* p_list);
void show_list(list_t* p_list);
void destroy_list(list_t** pp_list);


/* auxilory routines */

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_delete_node);
static node_t* serch_node(list_t* p_list, data_t serch_data);
static node* get_node(data_t new_data);

/*auxilory routines */
void* xcalloc(size_t nr_of_elements, size_t size_per_element);

#endif