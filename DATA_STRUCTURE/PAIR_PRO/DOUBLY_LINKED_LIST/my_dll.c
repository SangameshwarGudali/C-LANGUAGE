#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS             1
#define LIST_DATA_FOUND     2
#define LIST_DATA_NOT_FOUND 3
#define LIST_IS_EMPTY       4


struct node* create_list(void);
struct node* get_new_node(int data);
int insert_at_end(struct node* p_list, int new_data);
int insert_at_start(struct node* p_list, int new_data);
int insert_after_data(struct node* p_list, int e_data, int new_data);
void destroy_list(struct node* p_list);

void test_suite(void);

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

int main(void)
{
    test_suite();
}

struct node* create_list(void)
{
    struct node* p = NULL;

    p = get_new_node(-1);

    return p;
}

struct node* get_new_node(int new_data)
{
    struct node* p = NULL;

    p = (struct node*)malloc(sizeof(struct node));
    assert(p != NULL);

    p->data = new_data;
    p->next = NULL;
    p->prev = NULL;
    
    return (p);
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_list->next; 
    p_new_node->prev = p_list;
    p_list->next = p_new_node;
   
    return(SUCCESS);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_run = NULL;
    struct node* p_new_node = NULL;

    p_run = p_list;
    while(p_run->next != NULL)
        p_run = p_run->next;
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_run->next = p_new_node;

    return(SUCCESS);
}

int insert_after_data(struct node* p_list, int e_data, int new_data)
{
    struct node* p_run = NULL;
    struct node* p_new_node = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    p_run = p_list;
    while(p_run != NULL)
    {
        if((p_run->data) == e_data)
            break;
        p_run = p_run->next;
    }
    if(p_run == NULL)
        return(LIST_DATA_NOT_FOUND);
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_run->next = p_new_node;

    return(SUCCESS);
}

int insert_before_data(struct node* p_list, int e_data, int new_data)
{
    struct node* p_run = NULL;
    struct node* p_new_data = NULL;

    p_run = p_list;
    while(p_run != NULL)
    {
        if(p_run->data == e_data)
            break;
        p_run = p_run->next;
    }
    p_new_data = get_new_node(new_data);
    p_new_node->next = p_run->prev->next;
    
}

void show_list(struct node* p_list, char* msg)
{
    int i;
    struct node* p_run = NULL;

    if(msg)
        puts(msg);
    
    printf("[START]-");
    p_run = p_list->next;
    while(p_run != NULL)
    {
        printf("<->[%d]", p_run->data);
        p_run = p_run->next;
    }
    printf("-[END]\n");
}


 void destroy_list(struct node* p_list)
 {
    struct node* p_run_next = NULL;
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        p_run_next = p_run;
        free(p_run_next);
        p_run = p_run->next;
    }
    free(p_list);
    p_list = NULL;
    
}

void test_suite(void)
{
    int ret, i;
    struct node* p_list_1 = NULL;

    p_list_1 = create_list();

    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_start(p_list_1, (i+1)*100);
        assert(ret == SUCCESS);
    }
    show_list(p_list_1, "Showing list p_list_1");

    ret = insert_at_start(p_list_1, 1000);
    assert(ret == SUCCESS);

    for(i = 0; i < 5; ++i)    
    {
        ret = insert_at_end(p_list_1, (i+1)*5);
        assert(ret == SUCCESS);
    }
    show_list(p_list_1, "insert at end");

    ret = insert_after_data(p_list_1, 100, 999);
    assert(ret == SUCCESS);

    show_list(p_list_1, "insert after_data 100, 999");

    destroy_list(p_list_1);
    p_list_1 = NULL;

}
