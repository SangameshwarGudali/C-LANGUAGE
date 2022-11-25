#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS                 1

#define LIST_DATA_NOT_FOUND     2
#define LIST_EMPTY              3

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* create_list(void); 
struct node* get_new_node(int new_data);
int insert_at_start(struct node* p_list, int new_data); 
int insert_at_end(struct node* p_list, int new_data);

int insert_before_data(struct node* p_list, int e_data, int new_data);
int insert_after_data(struct node* p_list, int e_data, int new_data);

int get_start(struct node* p_list, int* get_data);
int get_end_daa(struct node* p_list, int* get_data);

int pop_start(struct node* p_list, int* get_data);
int pop_end(struct node* p_list, int* p_end_data);

int remove_start(struct node* p_lsit);
int remove_end(struct node* p_list);



void show_list(struct node* p_list, const char* msg);

int main(void)
{
    int i = 0;
    int status;
    int get_data = 0;
    struct node* p_list = NULL;
    
    p_list = create_list();
    for(i = 50; i <= 100; i = i+10)
    {
        status = insert_at_end(p_list, i);
        assert(status == SUCCESS);
    }
    
    show_list(p_list, "insert_at_end");

    status = insert_after_data(p_list, 40 , 999);
    assert(status == SUCCESS);
    show_list(p_list, "insert after 40");
    

    status = insert_before_data(p_list, 50 , 88999);
    assert(status == SUCCESS);
    show_list(p_list, "insert before 555");

    puts("he");
    status = get_start(p_list, &get_data);
    printf("start data = %d\n", get_data);
    
    status = get_end_data(p_list, &get_data);
    printf("end data = %d\n", get_data);

    status = pop_start(p_list, &get_data);
    assert(status == SUCCESS);
    printf("pop start = %d\n", get_data);
    show_list(p_list, "pop _start");

    status = pop_end(p_list, &get_data);
    assert(status == SUCCESS);
    printf("pop end = %d\n", get_data);
    show_list(p_list, "pop end");

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "after remove start");
   
    return(0);
}


int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* p_delete_node = NULL; 

    if(p_list->next == NULL && p_list->prev == NULL)
        return (LIST_EMPTY); 

    p_delete_node = p_list; 
    while(p_delete_node->next != NULL)
        p_delete_node = p_delete_node->next; 

    *p_end_data = p_delete_node->data; 
    p_delete_node->prev->next = NULL; 
    free(p_delete_node); 
    p_delete_node = NULL; 

    return (SUCCESS); 
}

int get_end_data(struct node* p_list, int* get_data)
{
    struct node* p_run = NULL;
    if(p_list->next == NULL)
    {
        return(LIST_EMPTY);
    }

    p_run = p_list->next;
    while(p_run->next != NULL)
        p_run = p_run->next;

    *get_data = p_run->data;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* get_data)
{
    struct node* p_first_node = NULL;

    if(p_list->next == NULL)
        return(LIST_EMPTY);
    p_first_node = p_list->next;
    p_list->next = p_first_node->next;
    *get_data = p_first_node->data;
    free(p_first_node);

    return(SUCCESS);

}

int get_start(struct node* p_list, int* get_data)
{
    if(p_list->next == NULL)
        return(LIST_EMPTY);
    *get_data = p_list->next->data;

    return(SUCCESS);
}

int insert_before_data(struct node* p_list, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(p_run->data == e_data)
            break;
        p_run = p_run->next;
    }
    if(p_run == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run;
    p_new_node->prev = p_run->prev;
    p_run->prev->next = p_new_node;
    p_run->prev = p_new_node;

    return(SUCCESS);
}

int insert_after_data(struct node* p_list, int e_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run->next != NULL)
    {
        if(p_run->data == e_data)
            break;
        p_run = p_run->next;
    }
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_new_node->prev = p_run;
    if(p_run->next != NULL)
        p_run->next->prev = p_new_node;
    p_run->next = p_new_node;

    return(SUCCESS);
}

/* Interface routines declarations */ 
struct node* create_list(void)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(-1);
    return(p_new_node);
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_list->next;
    p_new_node->prev = p_list;
    if(p_list->next != NULL)
        p_list->next->prev = p_new_node;
    p_list->next = p_new_node;

    return(SUCCESS);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    if(p_run->next != NULL)
        p_run->next->prev = p_new_node;
    p_run->next = p_new_node;

    return(SUCCESS);

}
void show_list(struct node* p_list, const char* msg)
{
    struct node* p_run = NULL;
    if(msg != NULL)
        puts(msg);
    p_run = p_list->next;
    printf("[START]->");
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n");
}

struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
    {
        puts("malloc : Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    p_new_node->data = new_data;
    p_new_node->prev = NULL;
    p_new_node->next = NULL;

    return(p_new_node);
}

int remove_start(struct node* p_list)
{
    struct node* p_delete_node = NULL;

    if(p_list->next == NULL)
        return(LIST_EMPTY);
    
    p_delete_node = p_list->next;
    if(p_list->next != NULL)
        p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->prev = p_delete_node->next;
    free(p_delete_node);
    p_delete_node = NULL;

    return(SUCCESS);
}