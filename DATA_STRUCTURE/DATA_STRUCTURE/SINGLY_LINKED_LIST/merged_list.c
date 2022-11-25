#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS                 1
#define TRUE                    1
#define FALSE                   0
#define LIST_EMPTY              3
#define LIST_DATA_NOT_FOUND     2
#define LIST_DATA_FOUND         5

struct node
{
    int data;
    struct node* next;
};


struct node* create_list(void);
struct node* get_new_node(int new_data);
int insert_at_end(struct node* p_list, int new_data);
int merge_list(struct node* p_list1, struct node* p_list2, struct node** pp_merged_list);
void show_list(struct node* p_list, const char* msg);

int main(void)
{
    int i;
    int status;
    int length;
    struct node* p_list1 = NULL;
    struct node* p_list2 = NULL;
    struct node* p_merged_list = NULL;
    struct node* p_concat_list = NULL;
    struct node* p_reversed_list = NULL;
    struct node* p_arr_list = NULL;
    int* p_arr = NULL;

    p_list1 = create_list();
    p_list2 = create_list();

    for(i=10; i<=100; i=i+10)
    {
        status = insert_at_end(p_list1, i);
        assert(status == SUCCESS);
    }
    show_list(p_list1, "p_list1 insert at end");

    for(i=20; i<=100; i=i+20)
    {
        status = insert_at_end(p_list2, i);
        assert(status == SUCCESS);
    }
    show_list(p_list2, "p_list2 insert at end");

    status = merge_list(p_list1, p_list2, &p_merged_list);
    assert(status == SUCCESS);
    show_list(p_merged_list, "merged list");

    status = concat_list(p_list1, p_list2, &p_concat_list);
    assert(status == SUCCESS);
    show_list(p_concat_list, "concat_list");

    length = get_length(p_list1);
    printf("length = %d\n", length);
    length = get_length(p_list2);
    printf("length = %d\n", length);

    if(is_list_empty(p_list1) == FALSE);
        puts("list is not empty");

    
    status = get_reversed_list(p_list1, &p_reversed_list);
    assert(status == SUCCESS);
    show_list(p_reversed_list, "reversed p_list1");

    int arr[9] = {1,2,3,4,5,6,7,8,9};
    status = to_list(arr, sizeof(arr)/sizeof(int), &p_arr_list);
    assert(status == SUCCESS);
    show_list(p_arr_list, "array to list ");

    int size = 0;
    status = to_array(p_list1, &p_arr, &size);
    printf("size = %d\n", size);
    assert(status == SUCCESS);
    for(i = 0; i < size; i++)
        printf("p_arr[%d]\n", p_arr[i]);
    return(0);  
    
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
    printf("[End]\n");
}

struct node* create_list(void)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(-1);
    return(p_new_node);
}

struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));
    if(p_new_node == NULL)
        puts("malloc : Memory allocation failed");
    assert(p_new_node != NULL);
    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return(p_new_node);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list;
    while(p_run->next != NULL)
        p_run = p_run->next;
    p_new_node = get_new_node(new_data);
    p_run->next = p_new_node;
    p_new_node->next = NULL;
    return(SUCCESS);
}

int merge_list(struct node* p_list1, struct node* p_list2, struct node** pp_merged_list)
{
    int status;
    int data;
    struct node* p_run1 = NULL;
    struct node* p_run2 = NULL;
    struct node* p_merged_list = NULL;

    p_merged_list = create_list();
    
    p_run1 = p_list1->next;
    p_run2 = p_list2->next;
    puts("inside merge");
    while(1)
    {
        if(p_run1 == NULL)
        {
            while(p_run2 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run2->data);
                assert(status == SUCCESS);
                p_run2 = p_run2->next;
            }
            break;
        }

        if(p_run2 == NULL)
        {
            while(p_run1 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run1->data);
                assert(status == SUCCESS);
                p_run1 = p_run1->next;
            }
            break;
        }

        if(p_run1->data < p_run2->data)
        {
            data = p_run1->data;
            p_run1= p_run1->next;
        }
        else
        {
            data = p_run2->data;
            p_run2 = p_run2->next;
        }

        status = insert_at_end(p_merged_list, data);
        assert(status == SUCCESS);
    }
    puts("end");
    *pp_merged_list = p_merged_list;
    return(SUCCESS);
}


int concat_list(struct node* p_list1, struct node* p_list2, struct node** pp_concat_list)
{
    int status;
    struct node* p_concat_list = NULL;
    struct node* p_run = NULL;
    
    p_concat_list = create_list();
    p_run = p_list1->next;
    while(p_run != NULL)
    {
        status = insert_at_end(p_concat_list, p_run->data);
        assert(status == SUCCESS);
        p_run = p_run->next;
    }
    p_run = p_list2->next;
    while(p_run != NULL)
    {
        status = insert_at_end(p_concat_list, p_run->data);
        assert(status == SUCCESS);
        p_run = p_run->next;
    }

    *pp_concat_list = p_concat_list;
    return(SUCCESS);
    
}

int get_length(struct node* p_list)
{
    struct node* p_run = NULL;
    int len = 0;
    
    p_run = p_list->next;
    while(p_run != NULL)
    {
        len = len+1;
        p_run = p_run->next;
    }
    return(len);
}

int is_list_empty(struct node* p_list)
{
    return(p_list->next == NULL);
}   

struct node* search_node(struct node* p_list, int search_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(search_data == p_run->data)
            break;
        p_run = p_run->next;
    }
    return(p_run);
}

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list)
{
    int status;
    struct node* p_run = NULL;
    struct node* p_reversed_list = NULL;

    p_reversed_list = create_list();

    p_run = p_list->next;
    while(p_run != NULL)
    {
        status = insert_at_start(p_reversed_list, p_run->data);
        assert(status == SUCCESS);
        p_run = p_run -> next;
    }
    *pp_reversed_list = p_reversed_list;
    return(SUCCESS);
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;
    
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_list->next;
    p_list->next = p_new_node;

    return(SUCCESS);
}

int to_list(int* p_arr, int N, struct node** pp_list)
{
    int i;
    struct node* p_list = NULL;

    p_list = create_list();
    for(i = 0; i < N; ++i)
    {
        insert_at_end(p_list, p_arr[i]);
    } 

    *pp_list = p_list;
    return(SUCCESS);
}

int to_array(struct node* p_list, int** pp_arr, int* p_size)
{
    int len = 0;
    int i = 0;
    struct node* p_run = NULL;
    int* p_arr = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        len++;
        p_run = p_run->next;
    }

    p_arr = (int*)calloc(len,sizeof(int));

    if(p_list->next == NULL)
    {
        *pp_arr = p_arr;
        *p_size = len;    
    }

    p_run = p_list->next;
    while(p_run != NULL)
    {
        p_arr[i++] = p_run->data;
        p_run = p_run->next;
    }

    *pp_arr = p_arr;
    *p_size = len;

    return(SUCCESS);
}