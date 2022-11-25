#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS     1

struct node
{
    int data;
    struct node* next;
};

void* xcalloc(size_t nr_of_elements, size_t size_in_bytes);
struct node* create_list(void);
struct node* get_new_node(int new_data);
int insert_at_start(struct node* p_list, int new_data);
int insert_at_end(struct node* p_list, int new_data);
void show_list(struct node* p_list, const char* msg);
struct node* search_node(struct node* p_list, int search_data);

int main(void)
{
    int i;
    int status;
    struct node* p_list = NULL;
    struct node* p_serch_node = NULL;
    int search_data;

    p_list = create_list();

    for(i = 0; i < 10; ++i)
    {
        status = insert_at_end(p_list, i);
        assert(status == SUCCESS);
    }
    show_list(p_list, "insert at end list "); 
    puts("search your data");
    scanf("%d", &search_data);

    p_serch_node = search_node(p_list, search_data);
    assert(p_serch_node != NULL);
    if(p_serch_node->data == search_data)
    {
        printf("Your serach data %d is avilable in the list\n", p_serch_node->data);
    }
    else
    {
        puts("YOUR DATA NOT AVILABLE IN THIS LIST");
    }

    free(p_list);
    p_list = NULL;
    return(0);
}

struct node* search_node(struct node* p_list, int search_data)
{
    struct node* search_node = NULL;

    search_node = p_list;
    while(search_node->next != NULL)
    {
        if(search_node -> data == search_data)
        {
            break;
        }
        search_node = search_node->next;
    }
    return(search_node);

}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_last_node = NULL;
    struct node* p_new_node = NULL;

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

void show_list(struct node* p_list, const char* msg)
{
    struct node* p_run = NULL;
    
    if(msg != NULL)
        puts(msg);
        
    printf("[Start]");
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

struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)xcalloc(1,sizeof(struct node));
    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return(p_new_node);
}

struct node* create_list(void)
{
    struct node* p_list = NULL;

    p_list = get_new_node(-1);
    
    return(p_list);
}

void* xcalloc(size_t nr_of_elements, size_t size_in_bytes)
{
    void* p = NULL;

    p = calloc(nr_of_elements, size_in_bytes);
    assert(p != 0);

    return(p);
}