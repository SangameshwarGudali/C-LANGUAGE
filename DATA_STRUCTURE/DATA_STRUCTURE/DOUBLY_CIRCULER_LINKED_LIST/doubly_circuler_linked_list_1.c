#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// MACROS
#define SUCCESS             1
#define TRUE                1
#define FALSE               0

#define LIST_DATA_NOT_FOUND 2
#define LIST_IS_EMPTY       3

// Typedefs
typedef int data_t;
typedef int status_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t list_t;

// Structure
struct node
{
    data_t data;
    struct node* prev;
    struct node* next;
};

list_t* create_list(void);



status_t insert_at_start(list_t* p_list, data_t new_data);
status_t insert_at_end(list_t* p_list, data_t new_data);

status_t insert_after_data(list_t* p_list, data_t e_data, data_t new_data);
status_t insert_before_data(list_t* p_list, data_t e_data, data_t new_data);

status_t get_first(list_t* p_list);
status_t get_end(list_t* p_list);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);

status_t pop_start(list_t* p_list, data_t* get_first);
status_t pop_end(list_t* p_list, data_t* get_end);

status_t concat_list(list_t* p_list_1, list_t* p_list_2, list_t** pp_concat_list);
status_t merge_list(list_t* p_list_1, list_t* p_list_2, list_t** pp_merge_list);

status_t list_to_array(list_t* p_list, data_t* size, data_t** pp_arr);
status_t array_to_list(data_t* p_arr, data_t* size, data_t** pp_arr_list);

status_t destroy_list(list_t* p_list);

len_t get_length(list_t* p_list);
status_t find_data(list_t* p_list, data_t f_data);
status_t is_list_empty(list_t* p_list);
void show_list(list_t* p_list, const char* msg);

/* Declaration of Auxilary functions */
node_t* get_new_node(data_t new_data);
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
void generic_delete(node_t* p_delete_node);
node_t* search_node(list_t* p_list, data_t search_data);

/* Declaration of Auxilary routines*/
void* xcalloc(size_t nr_of_elements, size_t size_in_byte);

int main(void)
{
    int i;
    int status;
    int get_data = 0;


    list_t* p_list_1 = NULL;
    list_t* p_list_2 = NULL;
    list_t* p_concat_list = NULL;
    list_t* p_merge_list = NULL;
    
    p_list_1 = create_list();
    p_list_2 = create_list();

    for(i = 10; i <=100; i = i+10)
        assert(insert_at_end(p_list_1, i) == SUCCESS);
    show_list(p_list_1, "p_list_1");
    
    for(i = 15; i <=100; i = i+15)
        assert(insert_at_end(p_list_2, i) == SUCCESS);
    show_list(p_list_2, "p_list_2");

    assert(concat_list(p_list_1, p_list_2, &p_concat_list) == SUCCESS);
    show_list(p_concat_list, "concated list");

    assert(merge_list(p_list_1, p_list_2, &p_merge_list) == SUCCESS);
    show_list(p_merge_list, "merged list");


/*
    list_t* p_list = NULL;

    p_list = create_list();
    for(i = 10; i <= 100; i = i+10)
        assert(insert_at_end(p_list, i) == SUCCESS);
    show_list(p_list, "insert_at_end");

    assert(insert_after_data(p_list, 50, 200) == SUCCESS);
    show_list(p_list, "insert_after_data");

    status = find_data(p_list, 50);
    assert(status == SUCCESS);

    assert(remove_start(p_list) == SUCCESS);
    show_list(p_list, "remove start");

    assert(remove_end(p_list) == SUCCESS);
    show_list(p_list, "remove end");

    assert(pop_start(p_list, &get_data) == SUCCESS);
    printf("get data = %d\n", get_data);
    show_list(p_list, "pop start");

    assert(pop_end(p_list, &get_data) == SUCCESS);
    printf("get data = %d\n", get_data);
    show_list(p_list, "pop end");
*/

    assert(destroy_list(p_list_1) == SUCCESS);
    assert(destroy_list(p_list_2) == SUCCESS);

    return(0);
}


status_t merge_list(list_t* p_list_1, list_t* p_list_2, list_t** pp_merge_list)
{
    int data = 0;
    node_t* p_run1 = NULL;
    node_t* p_run2 = NULL;
    list_t* p_merge_list = NULL;

    p_merge_list = create_list();
    p_run1 = p_list_1->next;
    p_run2 = p_list_2->next;

    while(1)
    {
        if(p_run1->next == p_list_1)
        {
            while(p_run2 != p_list_2)
            {
                assert(insert_at_end(p_merge_list, p_run2->data) == SUCCESS);
                p_run2 = p_run2->next;
            }
            break;
        }

        if(p_run2->next == p_list_2)
        {
            while(p_run1 != p_list_1)
            {
                assert(insert_at_end(p_merge_list, p_run1->data) == SUCCESS);
                p_run1 = p_run1->next;
            }
            break;
        }

        if(p_run1->data <= p_run2->data)
        {
            data = p_run1->data;
            p_run1 = p_run1->next;
        }
        else
        {
            data = p_run2->data;
            p_run2 = p_run2->next;
        }

        insert_at_end(p_merge_list, data);
    }

    *pp_merge_list = p_merge_list;
    return(SUCCESS);

}

status_t concat_list(list_t* p_list_1, list_t* p_list_2, list_t** pp_concat_list)
{
    node_t* p_run = NULL;
    list_t* p_concat_list = NULL;

    p_concat_list = create_list();

    for(p_run = p_list_1->next; p_run != p_list_1; p_run = p_run->next)
        assert(insert_at_end(p_concat_list, p_run->data) == SUCCESS);

    for(p_run = p_list_2->next; p_run != p_list_2; p_run = p_run->next)
        assert(insert_at_end(p_concat_list, p_run->data) == SUCCESS);
    
    *pp_concat_list = p_concat_list;
    return(SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* get_last)
{
    node_t* p_delete_node = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    
    p_delete_node = p_list->next;
    while(p_delete_node->next != p_list)
        p_delete_node = p_delete_node->next;
    
    *get_last = p_delete_node->data;
    generic_delete(p_delete_node);

    return(SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* get_first)
{
    node_t* p_delete_node = NULL;

    if(p_list->next != NULL)
        *get_first = p_list->next->data;
    else
        return(LIST_IS_EMPTY);
    
    p_delete_node = p_list->next;
    generic_delete(p_delete_node);

    return(SUCCESS);
}

status_t remove_end(list_t* p_list)
{
    node_t* p_delete_node = NULL;

    p_delete_node = p_list->next;
    while(p_delete_node->next != p_list)
        p_delete_node = p_delete_node->next;
    
    generic_delete(p_delete_node);
    return(SUCCESS);
}

status_t remove_start(list_t* p_list)
{
    node_t* p_delete_node = NULL;\
    
    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    p_delete_node = p_list->next;
    
    generic_delete(p_delete_node);

    return(SUCCESS);
}

status_t find_data(list_t* p_list, data_t f_data)
{
    node_t* p_search_node = NULL;

    p_search_node = search_node(p_list, f_data);
    if(p_search_node != NULL)
        printf("data = %d\n", p_search_node->data);

    return(SUCCESS);
}

status_t insert_after_data(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* ext_node = NULL;

    ext_node = search_node(p_list, e_data);

    if(ext_node == NULL)
    {
        puts("not found in after data");
        return(LIST_DATA_NOT_FOUND);
    }
    
    generic_insert(ext_node, get_new_node(new_data), ext_node->next);
    return(SUCCESS);
}

status_t insert_before_data(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* ext_node = NULL;

    ext_node = search_node(p_list, e_data);
    
    if(ext_node == NULL);
        return(LIST_DATA_NOT_FOUND);

    generic_insert(ext_node->prev, get_new_node(new_data), ext_node);
    return(SUCCESS);
}

status_t insert_at_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_new_node(new_data), p_list->next);
    return(SUCCESS);
}

status_t insert_at_end(list_t* p_list, data_t new_data)
{
    generic_insert(p_list->prev, get_new_node(new_data), p_list);
    return(SUCCESS);
}


list_t* create_list(void)
{
    list_t* p_list = NULL;

    p_list = get_new_node(-1);
    p_list->next = p_list;
    p_list->prev = p_list;
    return(p_list);
}

node_t* get_new_node(data_t new_data)
{
    node_t* p_new_node = NULL;

    p_new_node = (node_t*)xcalloc(1, sizeof(node_t));
    assert(p_new_node != NULL);
    p_new_node->data = new_data;

    return(p_new_node);
}

void* xcalloc(size_t nr_of_elements, size_t size_in_bytes)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_in_bytes);
    if(p == NULL)
    {
        puts("calloc : Memory allocation failed");
        exit(EXIT_FAILURE);
    }
        
    return(p);
}

void generic_insert(node_t* p_big, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_big;
    p_big->next = p_mid;
    p_end->prev = p_mid;
}

void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node);
    p_delete_node = NULL;
}

void show_list(list_t* p_list, const char* msg)
{
    node_t* p_run = NULL;

    if(msg != NULL)
        puts(msg);
    printf("[START]->");
    p_run = p_list->next;
    while(p_run != p_list)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n");
}

status_t destroy_list(list_t* p_list)
{
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;

    p_run = p_list;
    while(p_run->next != p_list)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }
    free(p_list);
    p_list = NULL;

    return(SUCCESS);
}

node_t* search_node(list_t* p_list, data_t search_data)
{
    node_t* p_run = NULL;

    p_run = p_list->next;
    while(p_run != p_list)
    {
        if(p_run->data == search_data)
            return(p_run);
        p_run = p_run->next;
    }

    return(NULL);
}

status_t append_list(list_t* p_list_1, list_t* p_list_2)
{
    node_t* p_run = NULL;

    p_run = p_list_1->next;
    while(p_run->next != p_list1)
        p_run = p_run->next;
    
    p_run->next = p_list_2->next;
    while(p_run != p_list_2)
        p_run = p_run->next;
}