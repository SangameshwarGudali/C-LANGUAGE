#include <stdio.h>
#include <stdlib.h>
#include "list.h"


status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list -> next);
    return(SUCCESS);
}

list_t* create_list(void)
{
    list_t* p_list = NULL;

    p_list = get_node(-1);
    p_list -> prev = p_list;
    p_list -> next = p_list;

    return(p_list);
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid -> next = p_end;
    p_mid -> prev = p_beg;
    p_beg -> next = p_mid;
    p_end -> prev = p_mid;
}

static node_t* get_node(data_t* new_data)
{
    node_t* p_new_node = NULL;

    p_new_node = (node_t*)xcalloc(1, sizeof(node_t));
    p_new_node -> data = new_data;
    p_new_node -> prev = NULL;
    p_new_node -> next = NULL;

    return(p_new_node);
}

void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    node_t* p = NULL;

    p = calloc(nr_of_elements, size_per_element);
    if(p == NULL)
    {
        fprintf(stderr, "out of virtual box\n");
        exit(EXIT_FAILURE);
    }

    return(p);
}