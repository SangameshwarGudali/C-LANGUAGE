#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

struct node
{
    int data;
    struct node* next;
};

int insert_at_end(struct node* p_list, int new_data);
int concat_list(struct node* p_list1, struct node* p_list2, struct node** pp_concat_list);
int merge_list(struct node* p_list1, struct node* p_list2, struct node** pp_merged_list);
int append_list(struct node* p_list1, struct node* p_list2);

struct node* create_list(void);
struct node* get_new_node(int new_data);

int destroy_list(struct node* p_list);
void show_list(struct node* p_list, const char* msg);
void* xcalloc(int nr_of_element, int size_in_bytes);

int main(void)
{
    int i;
    int status;
    struct node* p_list1 = NULL;
    struct node* p_list2 = NULL;
    struct node* p_concated_list = NULL;
    struct node* p_merged_list = NULL;

    p_list1 = create_list();
    p_list2 = create_list();

    for(i = 10; i<=100; i = i + 10)
    {
        status = insert_at_end(p_list1, i);
        assert(status == SUCCESS);
    }
    show_list(p_list1, "p_list1");

    for(i = 1; i<=50; i = i + 5)
    {
        status = insert_at_end(p_list2, i);
        assert(status == SUCCESS);
    }
    show_list(p_list2, "p_list2");

    status = append_list(p_list1, p_list2);
    assert(status == SUCCESS);
    show_list(p_list1, "append list");

    status = merge_list(p_list1, p_list2, p_merged_list);
    puts("inside return");
    assert(status == SUCCESS);
    show_list(p_merged_list, "merged list");

    status = concat_list(p_list1, p_list2, &p_concated_list);
    assert(status == SUCCESS);
    show_list(p_concated_list, "concated list");


    return(0);

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


int concat_list(struct node* p_list1, struct node* p_list2, struct node** pp_concat_list)
{
    int status;
    struct node* p_run = NULL;
    struct node* p_concat_list = NULL;

    p_concat_list = create_list();
    puts("inside concat list");
    
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

void* xcalloc(int nr_of_elements, int size_in_byets)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_in_byets);
    if(p == NULL)
        puts("calloc : Memory allocation failed");
    assert(p != NULL);

    return(p);
}

void show_list(struct node* p_list, const char* msg)
{
    struct node* p_run;

    if(msg != NULL)
        puts(msg);
    printf("[START]->\n");
    p_run = p_list->next;
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[End]\n");
}

int merge_list(struct node* p_list1, struct node* p_list2, struct node** pp_merged_list)
{
    struct node* p_run1 = NULL;
    struct node* p_run2 = NULL;
    struct node* p_merged_list = NULL;
    int status;
    int data;

    p_merged_list = create_list();

    p_run1 = p_list1->next;
    p_run2 = p_list2->next;

    while(1)
    {
        if(p_run1 == NULL)
        {
            while(p_run2 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run2->data);
                assert(status == SUCCESS);
            }
            break;
        }

        if(p_run2 == NULL)
        {
            while(p_run1 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run1->data);
                assert(status == SUCCESS);
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
    puts("Merged list");


        status = insert_at_end(p_merged_list, data);
        assert(status == SUCCESS);
    }

    *pp_merged_list = p_merged_list;


    return(SUCCESS);

}

int append_list(struct node* p_list1, struct node* p_list2)
{
    struct node* p_run = NULL;

    p_run = p_list1->next;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }
    p_run->next = p_list2->next;
    free(p_list2);
    p_list2 = NULL;

    return(SUCCESS);
}
