#define _CRT_RAND_S

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

/* In stdlib.h --> 
#ifdef _CRT_RAND_S 
errno_t rand_s(unsigned int* p_num); 
#endif 
*/ 

#define SUCCESS             1 
#define LIST_DATA_NOT_FOUND 2 
struct node 
{
    int data; 
    struct node* next; 
}; 

/*  
    Routines that are called by client 
    to make use of the list 
*/ 
struct node* create_list(void); 

int insert_at_start(struct node* p_list, int new_data); 
int insert_at_end(struct node* p_list, int new_data);
int insert_after_data(struct node* p_list, int ext_data, int new_data); 
int insert_before_data(struct node* p_list, int ext_data, int new_data);  
void show_list(struct node* p_list, const char* msg);
int destroy_list(struct node* p_list); 

void extreme_testing(void); 

/* helper function */ 
struct node* get_new_node(int new_data); 
struct node* search_node(struct node* p_list, int search_data); 
/* Client Code */ 

int main(void)
{
    struct node* p_list = NULL; 
    int status; 
    int data; 

    p_list = create_list(); 
    show_list(p_list, "Showing list just after creation:"); 

    for(data = 10; data <= 60; data = data + 10)
    {
        status = insert_at_end(p_list, data); 
        assert(status == SUCCESS); 
    }
    show_list(p_list, "Showing after insert_at_end():"); 

    for(data = 100; data <= 600; data = data + 100)
    {
        status = insert_at_start(p_list, data); 
        assert(status == SUCCESS); 
    }
    show_list(p_list, "Showing after insert_at_start():"); 

    status = insert_after_data(p_list, 10, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "After inserting 0 after 10:"); 

    status = insert_before_data(p_list, 10, -1); 
    assert(status == SUCCESS); 
    show_list(p_list, "After inserting -1 before 10"); 

    status = insert_before_data(p_list, 600, -600); 
    assert(status == SUCCESS); 
    show_list(p_list, "After inserting -600 before 600"); 

    status = insert_after_data(p_list, 60, -60); 
    assert(status == SUCCESS); 
    show_list(p_list, "After inserting -60 after 60"); 

    status = insert_after_data(p_list, -500, 10); 
    assert(status == LIST_DATA_NOT_FOUND); 
    puts("-500 is not present in list"); 

    status = insert_before_data(p_list, -500, 10); 
    assert(status == LIST_DATA_NOT_FOUND); 
    puts("-500 is not present in list"); 

    status = destroy_list(p_list); 
    p_list = NULL; 
    assert(status == SUCCESS); 

    // extreme_testing(); 
    puts("SUCCESS"); 
    return (EXIT_SUCCESS); 
}

/* End of client code */

/* Server code */ 

struct node* create_list(void)
{
    struct node* p_list = NULL; 

    p_list = get_new_node(-1); 
    return (p_list); 
    // return get_new_node(-1); 
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL; 

    p_new_node = get_new_node(new_data); 
    p_new_node->next = p_list->next; 
    p_list->next = p_new_node; 

    return (SUCCESS); 
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

    return (SUCCESS); 
}

int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_ext_node = NULL; 
    struct node* p_new_node = NULL; 

    p_ext_node = search_node(p_list, ext_data); 
    if(p_ext_node == NULL)
        return (LIST_DATA_NOT_FOUND); 

    p_new_node = get_new_node(new_data); 
    p_new_node->next = p_ext_node->next; 
    p_ext_node->next = p_new_node; 

    return (SUCCESS); 
}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_ext_node_prev = NULL; 
    struct node* p_run = NULL; 
    struct node* p_new_node = NULL; 

    p_ext_node_prev = p_list; 
    p_run = p_list->next; 
    while(p_run != NULL)
    {
        if(p_run->data == ext_data)
            break; 
        p_ext_node_prev = p_run; 
        p_run = p_run->next; 
    }

    if(p_run == NULL)
        return (LIST_DATA_NOT_FOUND); 

    p_new_node = get_new_node(new_data); 
    p_new_node->next = p_ext_node_prev->next; 
    p_ext_node_prev->next = p_new_node; 

    return (SUCCESS); 
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
    printf("[END]\n"); 
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
        p_run = p_run_next; 
    }

    free(p_list); 
    return (SUCCESS); 
}

struct node* search_node(struct node* p_list, int search_data)
{
    struct node* p_run = NULL; 

    p_run = p_list->next; 
    while(p_run != NULL)
    {
        if(p_run->data == search_data)
            break; 
        p_run = p_run->next; 
    }

    return (p_run); 
}

struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    if(p_new_node == NULL)
    {
        fprintf(stderr, "malloc:fatal:out of memory\n"); 
        exit(EXIT_FAILURE); 
    }

    p_new_node->data = new_data; 
    p_new_node->next = NULL; 

    return (p_new_node); 
}

void extreme_testing(void)
{
    unsigned long long int nr_elements = 500000; 
    unsigned long long int i; 
    struct node* p_list = NULL; 
    unsigned int data; 
    int status; 

    p_list = create_list(); 
    data = 10; 
    for(i = 0; i < nr_elements; ++i)
    {
        //rand_s(&data); 
        printf("i = %llu\n", i); 
        status = insert_at_start(p_list, data); 
        assert(status == SUCCESS); 
        //rand_s(&data); 
        status = insert_at_end(p_list, data); 
        assert(status == SUCCESS); 
    }

    show_list(p_list, "Extreme Testing:"); 
    status = destroy_list(p_list); 
    assert(status == SUCCESS); 
    p_list = NULL; 
}