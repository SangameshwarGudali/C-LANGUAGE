#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    int data;
    struct node* next;
};

struct node* create_list(void);
int insert_start(struct node* p_start_node, int data);
void print_list(struct node* p_start_node);

int main(void)
{
    int i;
    int data;
    int status;
    int choice;

    struct node* p_list1 = NULL;
    p_list1 = create_list();
    
    while(1)
    {
        puts("Do you want to insert element at first position?  1] YES ");
        scanf("%d",&choice);

        if(choice != 1)
            break;  

        puts("Enter the element");
        scanf("%d", &data);

        status = insert_start(p_list1, data);
        assert(status == 1);
       
    }
    print_list(p_list1);
    free(p_list1);
    p_list1 = NULL;

    return(0);
}


struct node* create_list(void)
{
    struct node* p_start_node = NULL;
    p_start_node = (struct node*)malloc(sizeof(struct node));
    assert(p_start_node != NULL);
    p_start_node -> data = 0;
    p_start_node -> next = NULL;

    return(p_start_node);
}

int insert_start(struct node* p_start_node, int data)
{
    if(p_start_node == NULL)
    {
        p_start_node = (struct node*)malloc(sizeof(struct node));
        assert(p_start_node != NULL);
        p_start_node -> data;
        p_start_node->next = NULL;
    }
        
    else
    {
        p_start_node->next = (struct node*)malloc(sizeof(struct node));
        assert(p_start_node != NULL);
        p_start_node->data = data;
        p_start_node->next = p_start_node->next->next;
    }
        
    return(1);
}

void print_list(struct node* p_start_node)
{
    struct node* p_run = p_start_node;
    while(p_start_node->next != NULL)
    {
        printf("data = %d\n", p_start_node->data);
        p_run = p_run->next;
    }
}