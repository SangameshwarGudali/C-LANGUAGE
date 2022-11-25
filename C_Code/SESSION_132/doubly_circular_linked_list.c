/* Headers */ 
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

/* Symbolic constants */ 
#define SUCCESS             1 
#define TRUE                1 
#define FALSE               0 
#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY          3

/* Typedefs */ 
typedef int data_t; 
typedef int status_t; 
typedef int len_t; 

typedef struct node node_t; 
typedef node_t list_t; 

/* Node layout */ 
struct node 
{
    data_t data; 
    struct node* prev; 
    struct node* next; 
}; 

/* Declaration of interface functions */ 
list_t* create_list(void); 

status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data); 

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list); 

status_t find_data(list_t* p_list, data_t f_data); 
status_t is_list_empty(list_t* p_list); 
len_t get_length(list_t* p_list); 
void show_list(list_t* p_list, const char* msg); 

status_t destroy_list(list_t** pp_list); 

status_t concat_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_cat_list); 
status_t append_list(list_t* p_list_1, list_t* p_list_2); 
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_merged_lists); 
status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list); 
status_t reverse_list(list_t* p_list); 

/* Declaration of list auxillary functions */ 
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
void generic_delete(node_t* p_delete_node); 
node_t* search_node(list_t* p_list, data_t s_data); 
node_t* get_node(data_t new_data); 

/* Declaration of auxillary routines */ 
void* xcalloc(size_t nr_elements, size_t size_per_element); 

int main(void)
{

    return (EXIT_SUCCESS);
}

/* Declaration of interface functions */ 
list_t* create_list(void)
{   
    list_t* p_list = NULL; 

    p_list = get_node(-1); 
    p_list->next = p_list; 
    p_list->prev = p_list; 

    return (p_list); 
}

status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    generic_insert(p_list->prev, get_node(new_data), p_list); 
    return (SUCCESS); 
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL; 

    e_node = search_node(p_list, e_data); 
    if(e_node == NULL)
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(e_node, get_node(new_data), e_node->next); 
    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL; 

    e_node = search_node(p_list, e_data); 
    if(e_node == NULL)
        return (LIST_DATA_NOT_FOUND); 

    generic_insert(e_node->prev, get_node(new_data), e_node); 
    return (SUCCESS); 
}

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start_data); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_list); 

status_t find_data(list_t* p_list, data_t f_data); 
status_t is_list_empty(list_t* p_list); 
len_t get_length(list_t* p_list); 
void show_list(list_t* p_list, const char* msg); 

status_t destroy_list(list_t** pp_list); 

status_t concat_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_cat_list); 
status_t append_list(list_t* p_list_1, list_t* p_list_2); 
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_merged_lists); 
status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list); 
status_t reverse_list(list_t* p_list); 

/* Declaration of list auxillary functions */ 
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node); 
    p_delete_node = NULL; 
}

node_t* search_node(list_t* p_list, data_t s_data)
{
    node_t* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != p_list)
    {
        if(p_run->data == s_data)
            return (p_run); 
        p_run = p_run->next; 
    }
    
    return (NULL); 
}

node_t* get_node(data_t new_data)
{
    node_t* p_new_node = NULL; 

    p_new_node = (node_t*)xcalloc(1, sizeof(node_t)); 
    p_new_node->data = new_data; 
    return (p_new_node);
}

/* Definition of auxillary routines */ 
void* xcalloc(size_t nr_elements, size_t size_per_element)
{
    void* p = NULL; 

    p = calloc(nr_elements, size_per_element); 
    if(p == NULL)
    {
        printf("calloc:fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    return (p); 
}
