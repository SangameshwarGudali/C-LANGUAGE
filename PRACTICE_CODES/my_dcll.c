#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1
#define TRUE    1
#define FALSE   0
#define LIST_DATA_NOT_FOUND 3
#define LIST_EMPTY 4


typedef int data_t;
typedef int status_t;
typedef int len_t;

typedef struct node node_t;
typedef node_t list_t;

struct node
{
    data_t data;
    node_t* next;
    node_t* prev;
};

status_t insert_at_start(list_t* p_list, data_t new_data);
status_t insert_at_end(list_t* p_list, data_t new_data);

status_t insert_after_data(list_t* p_list, data_t e_data, data_t new_data);
status_t insert_before_data(list_t* p_list, data_t e_data, data_t new_data);

status_t concatenate_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_cat_list);
status_t append_lists(list_t* p_list_1, list_t* p_list_2);
status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_merged_list);

status_t pop_start(list_t* p_list, data_t* p_start_data);
status_t pop_end(list_t* p_list, data_t* p_end_data);
status_t get_start(list_t* p_list, data_t* get_start_data);
status_t get_end(list_t* p_list, data_t* get_end_data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list);


/* Helper routines*/

list_t* create_list(void);
node_t* get_node(data_t new_data);
void* xcalloc(size_t nr_of_elements, size_t size_of_element);

void show_list(list_t* p_list, const char* msg);
node_t* search_node(list_t* p_list, data_t s_node);

status_t find_data(list_t* p_list, data_t f_data);
status_t is_list_empty(list_t* p_list);
len_t get_length(list_t* p_list);
status_t destroy_list(list_t** pp_list);

/* generic routines */

void generic_insert(node_t* p_big, node_t* p_mid, node_t* p_end);
void generic_delete(node_t* p_delete_node);

/* Test Suite */
void test_suite_1(void);
void test_suite_2(void);
void test_suite_3(void);


int main(void)
{
    test_suite_1();
    test_suite_2();
    test_suite_3();
    return(EXIT_SUCCESS);
}

void test_suite_1(void)
{
    int i;
    int ret;

    list_t* p_list = NULL;
    list_t* p_reversed_list = NULL;
    node_t* p_search_node = NULL;
    
    p_list = create_list();
    p_reversed_list = create_list();
    
    for(i = 0; i < 5; ++i)
        assert(insert_at_start(p_list, (i + 1) * 10) == SUCCESS);
    show_list(p_list, "Insert at Start:\n");
    

    for(i = 0; i < 5; ++i)
        assert(insert_at_end(p_list, (i+1)*100) == SUCCESS);
    show_list(p_list, "insert_at_end:\n");

    int get_pop_start_data = 0;
    ret = pop_start(p_list, &get_pop_start_data);
    assert(ret == SUCCESS);
    printf("pop_start_data = %d\n", get_pop_start_data);
    show_list(p_list, "After Pop start Data");

    int get_pop_end_data = 0;
    ret = pop_end(p_list, &get_pop_end_data);
    assert(ret == SUCCESS);
    printf("pop end Data = %d\n", get_pop_end_data);
    show_list(p_list, "After Pop End Data");

    ret = remove_start(p_list);
    assert(ret == SUCCESS);
    show_list(p_list, "Remove Start");
    
    ret = remove_end(p_list);
    assert(ret == SUCCESS); 
    show_list(p_list, "Remove End");

    ret = remove_data(p_list, 20);
    assert(ret == SUCCESS);
    show_list(p_list, "Remove Data");

    ret = get_reversed_list(p_list, &p_reversed_list);
    assert(ret == SUCCESS);
    show_list(p_reversed_list, "Reversed list");
    
    ret = insert_after_data(p_list, 10, 10000);
    assert(ret == SUCCESS);
    show_list(p_list, "After insert after data 10, 10000:");

    ret = insert_before_data(p_list, 30, 50000);
    assert(ret == SUCCESS);
    show_list(p_list, "After insert before data 30, 50000:");

    ret = find_data(p_list, 50);
    if(ret == SUCCESS)
        puts("50 -> DATA FOUND");
    else
        puts("50 -> DATA NOT FOUND");
    
    p_search_node = search_node(p_list, 60);
    if(p_search_node != NULL)
        puts("NODE with provided data IS AVAILABLE IN THE LIST");
    else
        puts("NODE with provided data NOT AVAILABLE IN THE LIST");
        
    ret = is_list_empty(p_list);
    if(ret == SUCCESS)
        puts("list is empty");
    else
        puts("list is not empty");
    
    len_t len;
    len = get_length(p_list);
    printf("len of list = %d\n", len);

    free(p_list);
    p_list = NULL;

}

void test_suite_2(void)
{
    int i;
    int ret;
    list_t* p_list_1 = create_list();
    list_t* p_list_2 = create_list();
    list_t* p_concatenated_list = create_list();
     
    for(i = 0; i < 5; ++i)
    {
        assert(insert_at_start(p_list_1, (i * 2) + 100) == SUCCESS);
    }
    show_list(p_list_1, "p_list_1:\n");
    
    for(i = 0; i < 5; ++i)
    {
        assert(insert_at_start(p_list_2, (i * 1) + 200) == SUCCESS);
    }
    show_list(p_list_2, "p_list_2:\n");
      
    ret = concatenate_lists(p_list_1, p_list_2, &p_concatenated_list);
    assert(ret == SUCCESS);
    show_list(p_concatenated_list, "Concatenated list p_list_1 and p_list_2:\n");
    
    
    list_t* p_merge_list_1 = create_list();
    list_t* p_merge_list_2 = create_list();
    list_t* p_merged_list =  create_list();

    for(i = 0; i < 5; ++i)
    {
        assert(insert_at_start(p_merge_list_1, (i * 10) + 100) == SUCCESS);
    }
    show_list(p_merge_list_1, "p_merge_list_1:\n");
    
    for(i = 0; i < 5; ++i)
    {
        assert(insert_at_start(p_merge_list_2, (i * 10) + 200) == SUCCESS);
    }
    show_list(p_merge_list_2, "p_merge_list_2:\n");

    ret = merge_lists(p_merge_list_1, p_merge_list_2, &p_merged_list);
    assert(ret == SUCCESS);
    show_list(p_merged_list, "Merged list of p_merge_list_1 and p_merge_list_2");
    

}

void test_suite_3(void)
{
    int i, ret;
    list_t* p_app_list_1 = create_list();
    list_t* p_app_list_2 = create_list();
    
    for(i = 0; i < 5; ++i)
    {
        assert(insert_at_start(p_app_list_1, (i * 10) + 100) == SUCCESS);
    }
    show_list(p_app_list_1, "p_app_list_1:\n");
    
    for(i = 0; i < 5; ++i)
    {
        assert(insert_at_start(p_app_list_2, (i * 10) + 200) == SUCCESS);
    }
    show_list(p_app_list_2, "p_app_list_2:\n");


    ret = append_lists(p_app_list_1, p_app_list_2);
    assert(ret == SUCCESS);
    show_list(p_app_list_1, "Appended List");

}


status_t insert_at_start(list_t* p_list, data_t new_data)
{
    node_t* new_node = NULL;

    generic_insert(p_list, get_node(new_data), p_list->next);

    return(SUCCESS);
}

status_t insert_at_end(list_t* p_list, data_t new_data)
{
    node_t* new_node = NULL;
    generic_insert(p_list->prev, get_node(new_data), p_list);
    return(SUCCESS);
}

status_t insert_after_data(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* new_node = NULL;
    node_t* p_search_data = NULL;
    p_search_data = search_node(p_list, e_data);
    if(p_search_data == NULL)
        return(LIST_DATA_NOT_FOUND);
    generic_insert(p_search_data, get_node(new_data), p_search_data->next);
    return(SUCCESS);
}

status_t insert_before_data(list_t* p_list, data_t e_data, data_t new_data)    
{

    node_t* new_node = NULL;
    node_t* p_search_data = NULL;
    
    p_search_data = search_node(p_list, e_data);
    
    if(p_search_data == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    generic_insert(p_search_data->prev, get_node(new_data), p_search_data);
    return(SUCCESS);

}

list_t* create_list(void)
{
    list_t* p_list = NULL;

    p_list = get_node(-1);
    p_list->next = p_list;
    p_list->prev = p_list;

    return (p_list);
}

node_t* get_node(data_t new_data)
{
    node_t* new_node = NULL;
    new_node = (struct node*)xcalloc(1, sizeof(struct node));
    new_node->data = new_data;
    return(new_node);
}

void* xcalloc(size_t nr_of_elements, size_t size_of_element)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_of_element);
    if(p == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return(p);
}

void show_list(list_t* p_list, const char* msg)
{
    if(msg)
        puts(msg);
    node_t* p_run = NULL;

    p_run = p_list->next;
    printf("[START]<->");
    while(p_run != p_list)
    {
        printf("[%d]<->", p_run->data);
        p_run = p_run->next;
    }
    puts("[END]<->");
}

node_t* search_node(list_t* p_list, data_t s_node)
{
    node_t* p_search_node = NULL;

    p_search_node = p_list->next;
    while(p_search_node != p_list)
    {
        if(p_search_node->data == s_node)
            return(p_search_node);
        p_search_node = p_search_node->next;
    }
    return(NULL);
}

status_t find_data(list_t* p_list, data_t f_data)
{
    node_t* p_search_node = NULL;
    p_search_node = search_node(p_list, f_data);
    
    if(p_search_node != NULL)
       return(TRUE);
    else
       return(FALSE);
}

status_t is_list_empty(list_t* p_list)
{
    return(p_list->next == p_list && p_list->prev == p_list);
}

len_t get_length(list_t* p_list)
{
    node_t* p_run = NULL;
    len_t len = 0;

    p_run = p_list->next;
    while(p_run != p_list)
    {
        len++;
        p_run = p_run->next;
    }

    return len;
}

status_t destroy_list(list_t** pp_list)
{
    node_t* p_run = NULL;
    node_t* temp = NULL;
    node_t* p_list = NULL;

    p_list = *pp_list;         

    p_run = p_list->next;
    while(p_run != p_list);
    {
        temp = p_run->next;
        free(p_run);
        p_run = temp;
    }
    free(p_list);
    *pp_list = NULL;

    return (SUCCESS);
}


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
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(p_list->next == p_list)
        return(LIST_EMPTY);
    *p_start_data = p_list->next->data;
    generic_delete(p_list->next);
    return(SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    if(p_list->next == p_list)
        return(LIST_EMPTY);
    *p_end_data = p_list->prev->data;
    generic_delete(p_list->prev);
    return(SUCCESS);
}

status_t get_start(list_t* p_list, data_t* get_start_data)
{
    if(p_list->next == p_list)
        return(LIST_EMPTY);
    *get_start_data = p_list->prev->data;
    return (SUCCESS);
}

status_t remove_start(list_t* p_list)
{
    if(p_list->next == p_list)
        return (LIST_EMPTY);
        
    generic_delete(p_list->next);
    return (SUCCESS);    
}

status_t remove_end(list_t* p_list)
{
    if(p_list->prev == p_list)
        return(LIST_EMPTY);

    generic_delete(p_list->prev);
    return(SUCCESS);
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* p_search_node = NULL;

    p_search_node = search_node(p_list, r_data);
    if(p_search_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    generic_delete(p_search_node);
    return(SUCCESS);
}

status_t concatenate_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_cat_list)
{
    list_t* p_cat_list = NULL;
    node_t* p_run = NULL;
    
    p_cat_list = create_list();
    
    p_run = p_list_1->next;
    while(p_run != p_list_1)
    {
        assert(insert_at_end(p_cat_list, p_run->data) == SUCCESS);
        p_run = p_run->next;
    }
    p_run = p_list_2->next;
    while(p_run != p_list_2)
    {
        assert(insert_at_end(p_cat_list, p_run->data) == SUCCESS);
        p_run = p_run->next;
    }
    *pp_cat_list = p_cat_list;
    return(SUCCESS);
}

status_t append_lists(list_t* p_list_1, list_t* p_list_2)
{
    if(is_list_empty(p_list_2) == TRUE)
        {
            free(p_list_2);
            p_list_2 = NULL;
        }

    p_list_1->prev->next = p_list_2->next;
    p_list_2->next->prev = p_list_1->prev;
    p_list_2->prev->next = p_list_1;
    p_list_1->prev = p_list_2->prev;

    free(p_list_2); 
    p_list_2 = NULL; 

    return (SUCCESS);
}

status_t merge_lists(list_t* p_list_1, list_t* p_list_2, list_t** pp_merged_list)
{
    list_t* p_merged_list = NULL;
    int data = 0;
    p_merged_list = create_list();

    node_t* p_run_1 = p_list_1->next;
    node_t* p_run_2 = p_list_2->next;

    while(TRUE)
    {
        if(p_run_1 == p_list_1)
        {
            while(p_run_2 != p_list_2)
            {
                assert(insert_at_end(p_merged_list, p_run_2->data) == SUCCESS);
                p_run_2 = p_run_2->next;
            }
            break;
        }
        
        if(p_run_2 == p_list_2)
        {
            while(p_run_1 != p_list_1)
            {
                assert(insert_at_end(p_merged_list, p_run_1->data) == SUCCESS);
                p_run_1 = p_run_1->next;
            }
            break;
        }

        if(p_run_1->data <= p_run_2->data)
        {
            data = p_run_1->data;
            p_run_1 = p_run_1->next;
        }
        else
        {
            data = p_run_2->data;
            p_run_2 = p_run_2->next;
        }

        assert(insert_at_end(p_merged_list, data) == SUCCESS);
    }

    *pp_merged_list = p_merged_list;
    return(SUCCESS);

}

status_t get_reversed_list(list_t* p_list, list_t** pp_reversed_list)
{
    
    list_t* p_reversed_list = create_list();
    node_t* p_run = NULL;
    data_t ret;

    if(p_list->next == p_list)
        return(LIST_EMPTY);

    p_run = p_list->next;
    while(p_run != p_list)
    {
        ret = insert_at_start(p_reversed_list, p_run->data);
        assert(ret == SUCCESS);
        p_run = p_run->next;
    }

    *pp_reversed_list = p_reversed_list;
    return(SUCCESS);
}