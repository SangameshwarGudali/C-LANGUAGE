#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS             1
#define FAILURE             0
#define LIST_DATA_NOT_FOUND 2
#define LIST_DATA_FOUND     3
#define TRUE                1
#define FALSE               0
#define LIST_IS_EMPTY       0

struct node
{
    int data;
    struct node* next;
};

// Client interface functions
struct node* create_list(void);
void show_list(struct node* p_list, const char* msg);

int insert_at_start(struct node* p_list, int new_data);
int insert_at_end(struct node* p_list, int new_data);

int get_start(struct node* p_list, int* get_data);
int get_end(struct node* p_list, int* get_end_data);

int insert_after_data(struct node* p_list, int e_data, int new_data);
int insert_before_data(struct node* p_list, int e_data, int new_data);

int remove_start(struct node* p_list);
int remove_end(struct node* p_list);

int is_list_empty(struct node* p_list);
int find_data(struct node* p_list, int f_data);

int pop_start(struct node* p_list, int* first_data);
int pop_end(struct node* p_list, int* last_data);
int concat_list(struct node* p_lits1, struct node* p_list2, struct node** pp_concat_list);

int destroy_list(struct node* p_list);


// Helper functin Declarations
struct node* get_new_node(int new_data);
void* xcalloc(int nr_of_elements, int size_in_byte);
struct node* search_node(struct node* p_list, int search_data);

int main(void)
{
    struct node* p_list = NULL;
    int i;
    int status;
    int get_data = 0;
    int get_end_data = 0;
    p_list = create_list();

    for(i = 10; i<=100; i = i + 10)
    {
        status = insert_at_end(p_list, i);
        assert(status == SUCCESS);
    }
    show_list(p_list, "insert at start");

    status = get_start(p_list, &get_data);
    assert(status == SUCCESS);
    printf("get_start_data = %d\n", get_data);

    status = get_end(p_list , &get_data);
    assert(status == SUCCESS);
    printf("get_end_data = %d\n", get_data);

    status = insert_after_data(p_list, 40, 1000);
    assert(status == SUCCESS);
    show_list(p_list, "insert_after_data 40");

    status = insert_before_data(p_list, 30, 555);
    assert(status == SUCCESS);
    show_list(p_list, "insert before data 30");

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "remove start");

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "remove end");

    if(is_list_empty(p_list) == FALSE)
        puts("list is empty");
    else
        puts("list is not empty");

    if(find_data(p_list, 555) == SUCCESS)
        puts("list data found");
    else
        puts("list data not found");

    status = pop_start(p_list, &get_data);
    assert(status == SUCCESS);
    show_list(p_list, "pop_start");

    status = pop_end(p_list, &get_data);
    assert(status == SUCCESS);
    show_list(p_list, "pop end");

    status = destroy_list(p_list);
    assert(status == SUCCESS);


    free(p_list);
    p_list = NULL;

    return(0);
}

// Client interface which create a new list
struct node* create_list(void)
{
    struct node* p_list = NULL;

    p_list = get_new_node(-1);

    return(p_list);
}

void show_list(struct node* p_list, const char* msg)
{
    struct node* p_run = NULL;

    if(msg != NULL)
        puts(msg);

    printf("[START]->");
    p_run = p_list->next;
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[End]\n");
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_list->next;
    p_list->next = p_new_node;

    return(SUCCESS);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_last_node = NULL;
    struct node* p_new_node = NULL;

    p_last_node = p_list;
    while(p_last_node->next != NULL)
        p_last_node = p_last_node->next;
    p_new_node = get_new_node(new_data);
    p_last_node->next = p_new_node;
    p_new_node->next = NULL;

    return(SUCCESS);
}

int insert_after_data(struct node* p_list, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_search_node = NULL;

    p_search_node = search_node(p_list, e_data);
    if(search_node == NULL)
        return(LIST_DATA_NOT_FOUND);

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_search_node->next;
    p_search_node->next = p_new_node;

    return(SUCCESS);

}

int insert_before_data(struct node* p_list, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;

    p_run = p_list->next;
    p_run_prev = p_list;
    while(p_run != NULL)
    {
        if(e_data == p_run->data)
            break;
        p_run_prev = p_run;
        p_run = p_run->next;
    }

    if(p_run == NULL)
        return(LIST_DATA_NOT_FOUND);

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run_prev->next;
    p_run_prev->next = p_new_node;

    return(SUCCESS);
}

int get_start(struct node* p_list, int* get_data)
{
    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);

    *get_data = p_list->next->data;
    return(SUCCESS);
}

int get_end(struct node* p_list, int* get_end_data)
{
    struct node* p_run = NULL;

    p_run = p_list;
    if(p_run->next == NULL)
    {
        puts("list is emtpy");
        return(LIST_IS_EMPTY);
    }

    while(p_run->next != NULL)
        p_run = p_run->next;
    
    *get_end_data = p_run->data;
    return(SUCCESS);
}

int remove_start(struct node* p_list)
{
    struct node* first_node = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    
    first_node = p_list->next;
    p_list->next = first_node->next;
    free(first_node);
    first_node = NULL;

    return(SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;
        
    p_run = p_list->next;
    p_run_prev = p_list;
    while(p_run->next != NULL)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    p_run_prev->next = p_run->next;
    free(p_run);
    
    return(SUCCESS);
}

// Helper function which accept data and converts it into node
struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)xcalloc(1, sizeof(struct node));
    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return(p_new_node);
}

// Helper function which Allocate Memory to our each node
void* xcalloc(int nr_of_elements, int size_in_byte)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_in_byte);
    if(p == NULL)
        puts("calloc: Memory Allocation failed");
    return(p);
}

// Helper function for search node in the list
struct node* search_node(struct node* p_list, int search_data)
{
    struct node* p_search_node = NULL;

    p_search_node = p_list->next;
    while(p_search_node != NULL)
    {
        if(search_data == p_search_node->data)
            break;
        p_search_node = p_search_node->next;
    }
    return(p_search_node);
}

int is_list_empty(struct node* p_list)
{
    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    return(SUCCESS);
}

int find_data(struct node* p_list, int f_data)
{
    struct node* p_run = NULL;

    p_run = p_list;
    while(p_run != NULL)    
    {
        if(f_data == p_run->data)
            break;
        p_run = p_run->next;
    }
    if(p_run == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    return(SUCCESS);
}

int pop_start(struct node* p_list, int* first_data)
{
    struct node* first_node = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    first_node = p_list->next;
    *first_data = first_node->data;
    p_list->next = first_node->next;
    free(first_node);
    first_node = NULL;

    return(SUCCESS);
}

int pop_end(struct node* p_list, int* last_data)
{
    struct node* p_last_node = NULL;
    struct node* p_last_node_prev = NULL;

    p_last_node = p_list->next;
    p_last_node_prev = p_list;
    while(p_last_node->next != NULL)
    {
        p_last_node_prev = p_last_node;
        p_last_node = p_last_node->next;
    }
    *last_data = p_last_node->data;
    p_last_node_prev->next = p_last_node->next;
    free(p_last_node);

    return(SUCCESS);
}

int destroy_list(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;

    p_run = p_list->next;
    p_run_prev = p_list;

    while(p_run != NULL)
    {
        p_run_prev = p_run;
        free(p_run_prev);
        p_run = p_run->next;
    }
    free(p_list);
    p_list = NULL;

    return(SUCCESS);
}

int concat_list(struct node* p_lits1, struct node* p_list2, struct node** pp_concat_list)
{
    int status;
    struct node* p_run = NULL;
    struct node* p_concat_list = NULL;

    p_concat_list = create_list();

    p_run = p_list1->next;
    while(p_run != NULL)
    {
        status = insert_at_end(p_concat_list, p_run->data);
        assert(status == SUCCESS);
    }

    p_run = p_list2->next;
    while(p_run != NULL)
    {
        status = insert_at_end(p_concat_list, p_run->data);
        assert(status == SUCCESS);
    }

    *pp_concat_list = p_concat_list;
    return(SUCCESS);
}