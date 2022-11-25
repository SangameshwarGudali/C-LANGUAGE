#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

struct node
{
    int data;
    struct node* next;
};

struct node* create_list(void);
struct node* get_new_node(int new_data);
int insert_at_start(struct node* p_list, int new_data);
void show_list(struct node* p_list, const char* msg);

int main(void)
{
    int data;
    int status;
    struct node* p_list1 = NULL;
    p_list1 = create_list();


    for(data = 1; data <= 100; data = data + 1)
    {
        status = insert_at_start(p_list1, data);
        assert(status == SUCCESS);
    }

    show_list(p_list1, "showing list after insert at start():");

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

    p_new_node -> data = new_data;
    p_new_node -> next = NULL;

    return(p_new_node);
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(new_data);
    p_new_node -> next = p_list -> next;
    p_list -> next = p_new_node;

    return(SUCCESS);
}

void show_list(struct node* p_list, const char* msg)
{
    struct node* p_run = NULL;

    if(msg != NULL)
        puts(msg);
    printf("[start]->");

    p_run = p_list->;
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("End\n");
}