#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

 #define SUCCESS    1

 struct node
 {
    int data;
    struct node* next;
 };

 struct node* create_list(void);
 struct node* get_new_node(int new_data);
 int insert_at_start(struct node* p_list, int new_data);
 int insert_at_end(struct node* p_list, int new_data);
 struct node* search_node(struct node* p_list, int search_data);
 int insert_after_data(struct node* p_list, int ext_data, int new_data);
 void show_list(struct node* p_list, const char* msg);

 int main(void)
 {
    int status;
    int data;
    int search;
    int after_data;
    int after_insert;
    struct node* p_list = NULL;
    struct node* search_data = NULL;

    p_list = create_list();
    
    for(data = 1; data <= 100; data = data + 1)
    {
        status = insert_at_end(p_list, data);
        assert(status == SUCCESS);
    }
    
    show_list(p_list,"show insert at end list");

    puts("insert data after");
    scanf("%d", &after_data);

    puts("which data you want to insert");
    scanf("%d", &after_insert);
    
    status = insert_after_data(p_list, after_data, after_insert);
    assert(status == SUCCESS);

    show_list(p_list, "after insert data");
    
    status = destroy_list(p_list);
    assert(status == SUCCESS);

    return(0);
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

    p_new_node = (struct node*)malloc(sizeof(struct node));
    assert(p_new_node != NULL);

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return(p_new_node);
 }

 int insert_at_start(struct node* p_list, int new_data)
 {
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(new_data);
    assert(p_new_node != NULL);

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
        p_last_node = p_last_node->next;
    p_new_node = get_new_node(new_data);
    p_last_node->next = p_new_node;
    p_new_node->next = NULL;

    return(SUCCESS);

 }

 void show_list(struct node* p_list, const char* msg)
 {
    struct node* p_run = NULL;
    if(msg != NULL)
        puts(msg);
    printf("[start]->");

    p_run = p_list->next;
    while(p_run != NULL)
    {
        printf("[%d]->",p_run->data);
        p_run = p_run->next;
    }
    
    printf("[End]\n");
 }

int destroy_list(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_run_next = NULL;

    p_run = p_list;
    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;  
    }
    free(p_list);
    return(SUCCESS);
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

    return(p_run);
 }

int insert_after_data(struct node* p_list, int ext_data, int new_data)
 {
    struct node* p_ext_node = NULL;
    struct node* p_new_node = NULL;

    p_ext_node = search_node(p_list, ext_data);
    if(p_ext_node == NULL)
        puts("DATA NOT FOUND");
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_ext_node->next;
    p_ext_node->next = p_new_node;
    
    return(SUCCESS);
 }
 /*

 int insert_befor_data(struct node* p_list, int ext_data, int new_data)
 {
    struct node* p_ext_node = NULL;
    struct node* p_new_node = NULL;

    p_ext_node = search_node(p_list, ext_data)
    if(p_ext_node->data == NULL)
        puts("DATA NOT FOUND");
    
    p_new_node = get_new_node(new_data);

 
 }
 */