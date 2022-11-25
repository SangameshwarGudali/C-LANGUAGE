#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS             1
#define LIST_DATA_NOT_FOUND 2
#define LIST_IS_EMPTY       2
#define LIST_DATA_FOUND    3

struct node
{
    int data;
    struct node* next;
};

void* xcalloc(size_t nr_of_elements, size_t size_in_bytes);
struct node* create_list(void);
struct node* get_new_node(int new_data);
void show_list(struct node* p_list, const char* msg);

int insert_at_start(struct node* p_list, int new_data);
int insert_at_end(struct node* p_list, int new_data);

int insert_after_data(struct node* p_list, int ext_data, int new_data);
int insert_before_data(struct node* p_list, int ext_data, int new_data);

int get_start(struct node* p_list, int* p_start_data);
int get_end(struct node* p_list, int* p_end_data);

int pop_start(struct node* p_list, int* p_start_data);
int pop_end(struct node* p_list, int* p_end_data);


int remove_start(struct node* p_list);
int remove_end(struct node* p_list);
int remove_data(struct node* p_list, int r_data);

int is_list_empty(struct node* p_list);

int find_data(struct node* p_list, int f_data);

int destroy_list(struct node* p_list);


int main(void)
{
    struct node* p_list = NULL;
    int i;
    int status;
    int get_data;
    int f_data;
    int r_data;

    p_list = create_list();

    for(i=10; i<=40; i=i+10)
    {
        status = insert_at_end(p_list, i);
        assert(status == SUCCESS);
    }
    show_list(p_list, "insert_at_start");

    for(i=50; i<=100; i=i+10)
    {
        status = insert_at_end(p_list, i);
        assert(status == SUCCESS);
    }
    show_list(p_list, "insert_at_end");

    status = insert_after_data(p_list, 10, 999);
    show_list(p_list, "insert_after_10");

    status = insert_before_data(p_list, 6, 777);
    show_list(p_list, "insert_befor_5");

    status = get_start(p_list, &get_data);
    assert(status == SUCCESS);
    printf("get_start_data = %d\n", get_data);
    show_list(p_list, "get_start_data");

    status = get_end(p_list, &get_data);
    assert(status == SUCCESS);
    printf("get_end_data = %d\n", get_data);
    show_list(p_list, "get_end_data");

    status = pop_start(p_list, &get_data);
    assert(status == SUCCESS);
    show_list(p_list, "after_pop_start");

    status = pop_end(p_list, &get_data);
    assert(status == SUCCESS);
    show_list(p_list, "after_pop_end");

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "remove_start");

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "remove_end");

    puts("Enter data for remove");
    scanf("%d", &r_data);
    status = remove_data(p_list, r_data);
    assert(status == SUCCESS);
    show_list(p_list, "remove_data 10");

    status = is_list_empty(p_list);
    if(status == EXIT_SUCCESS)
        puts("List is not Empty");
    else  
        puts("List is Empty");

    puts("find data in the list");
    scanf("%d", &f_data);
    status = find_data(p_list, f_data);
    if(status == SUCCESS)    
        puts("LIST DATA FOUND");
    else
        puts("LIST DATA NOT FOUND");

    status = destroy_list(p_list);
    assert(status == SUCCESS);


    return(0);
    
}

void* xcalloc(size_t nr_of_elements, size_t size_in_bytes)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_in_bytes);
    assert(p != NULL);

    return(p);
}

struct node* create_list(void)
{
    struct node* p_list = NULL;

    p_list = get_new_node(-1);
    return(p_list);
}

struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)xcalloc(1, sizeof(struct node));
    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return(p_new_node);
}

void show_list(struct node* p_list, const char* msg)
{
    struct node* p_run = NULL;

    if(msg != NULL)
        puts(msg);
    printf("[Start]->");
    p_run = p_list->next;
    while(p_run != NULL)
    {
        printf("[%d]->",p_run->data);
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
    struct node* p_new_node = NULL;
    struct node* p_last_node = NULL;

    p_last_node = p_list;
    while(p_last_node->next != NULL)
    {
        p_last_node = p_last_node->next;
    }
    p_new_node = get_new_node(new_data);
    p_last_node->next = p_new_node;
    p_new_node->next = NULL;

    return(SUCCESS);
    
}


int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list;
    while(p_run->next != NULL)
    {
        if(p_run->data == ext_data)
            break;
        p_run = p_run->next;
    }

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_run->next = p_new_node;

    return(SUCCESS);
}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;
    struct node* p_ext_node_prev = NULL;

    p_run = p_list->next;
    p_ext_node_prev = p_list;
    while(p_run != NULL)
    {
        if(p_run->data == ext_data)
            break;
        p_ext_node_prev = p_run;
        p_run = p_run->next;
    }
    if(p_run == NULL)
        return(LIST_DATA_NOT_FOUND);
        
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_ext_node_prev->next;
    p_ext_node_prev->next = p_new_node;

    return(SUCCESS);
}

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);

    *p_start_data = p_list->next->data;
    return(SUCCESS);
}


int get_end(struct node* p_list, int* p_end_data)
{
    struct node* p_run = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    
    p_run = p_list;
    while(p_run->next != NULL)
        p_run = p_run->next;
    
    *p_end_data = p_run->data;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* p_first_node = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    
    p_first_node = p_list->next;
    *p_start_data = p_first_node->data;

    p_list->next = p_first_node->next;
    free(p_first_node);
    p_first_node = NULL;

    return(SUCCESS);
}

int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* p_end_node = NULL;
    struct node* p_end_node_prev = NULL;
    
    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
        
    p_end_node_prev = p_list;
    p_end_node = p_list->next;
    while(p_end_node->next != NULL)
    {
        p_end_node_prev = p_end_node;
        p_end_node = p_end_node->next;
    }

    *p_end_data = p_end_node_prev->data;
    p_end_node_prev->next = p_end_node->next;
    free(p_end_node);

    return(SUCCESS);
}

int remove_start(struct node* p_list)
{
    struct node* first_node = NULL;

    first_node = p_list->next;
    p_list->next = first_node->next;
    free(first_node);
    first_node = NULL;

    return(SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* last_node = NULL;
    struct node* last_node_prev = NULL;

    last_node = p_list->next;
    last_node_prev = p_list;
    while(last_node->next != NULL)
    {
        last_node_prev = last_node;
        last_node = last_node->next;
    }

    if(last_node == NULL)
        return(LIST_IS_EMPTY);
    
    last_node_prev->next = last_node->next;
    free(last_node);
    last_node = NULL;

    return(SUCCESS);
}


int remove_data(struct node* p_list, int r_data)
{
    struct node* remove_node_prev = NULL;
    struct node* remove_node = NULL;

    remove_node = p_list->next;
    remove_node_prev = p_list;
    while(remove_node != NULL)
    {
        if(remove_node->data == r_data)
            break;
        remove_node_prev = remove_node;
        remove_node = remove_node->next;
    }

    if(remove_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    remove_node_prev->next =  remove_node->next;
    free(remove_node);
    remove_node = NULL;

    return(SUCCESS);
}

int is_list_empty(struct node* p_list)
{
    if(p_list->next == NULL)
        return(EXIT_FAILURE);
    
    return(EXIT_SUCCESS);
}

int find_data(struct node* p_list, int f_data)
{
    struct node* find_node = NULL;

    find_node = p_list;
    while(find_node != NULL)
    {
        if(find_node->data == f_data)
            break;
        find_node = find_node->next;
    }

    if(find_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    return(SUCCESS);
}   

int destroy_list(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_run_next = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run->next;
    }

    free(p_list);
    return(SUCCESS);
}
