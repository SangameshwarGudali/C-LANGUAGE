#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS                 1

#define LIST_DATA_NOT_FOUND     2
#define LIST_IS_EMPTY           3

#define TRUE                    1
#define FALSE                   0

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* create_list(void);
void show_list(struct node* p_list, const char* msg);

int insert_at_start(struct node* p_list, int new_data);
int insert_at_end(struct node* p_list, int new_data);

int insert_after_data(struct node* p_list, int ext_data, int new_data);
int insert_before_data(struct node* p_list, int ext_data, int new_data);

int remove_start(struct node* p_list);
int remove_end(struct node* p_list);

int pop_start(struct node* p_list, int* get_start);
int pop_end(struct node* p_list, int* get_end);

int get_start(struct node* p_list, int* get_start_data);
int get_end(struct node* p_list, int* get_end_data);

int concat_list(struct node* p_list1, struct node* p_list2, struct node** pp_concat_list);
int merge_list(struct node* p_list1, struct node* p_list2, struct node** pp_merge_list);
int append_list(struct node* p_list1, struct node* p_list2);

int to_array(struct node* p_list, int *N, int** pp_arr);
int to_list(int* p_arr, int N, struct node** pp_list);

int get_length(struct node* p_list);
int is_list_empty(struct node* p_list);
int find_data(struct node* p_list, int f_data);

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list);
int reverse_list(struct node* p_list);

int destroy_list(struct node* p_list);

struct node* get_new_node(int new_data);
struct node* search_node(struct node* p_list, int search_data);

int main(void)
{
    int status;
    int i = 0;
    int get_data = 0;
    int len = 0;
    struct node* p_list = NULL;
    struct node* p_list1 = NULL;
    struct node* p_list2 = NULL;
    struct node* p_concat_list = NULL;
    struct node* p_merge_list = NULL;
    struct node* p_reversed_list = NULL;
    struct node* p_arr_list = NULL;
    int* p_arr = NULL;
    int p_brr [] = {111,222,333,444,555,666,777,888};

    p_list = create_list();
    for(i = 10; i<=100; i=i+10)
        assert(insert_at_end(p_list, i) == SUCCESS);
    show_list(p_list, "insert_at_end");

    p_list1 = create_list();
    for(i = 5; i <= 50; i=i+5)
        assert(insert_at_end(p_list1, i) == SUCCESS);

    
    p_list2 = create_list();
    for(i = 10; i <= 100; i = i+10)
        assert(insert_at_end(p_list2, i) == SUCCESS);

    assert(insert_after_data(p_list, 50, 55) == SUCCESS);
    show_list(p_list, "insert after data");

    assert(insert_before_data(p_list, 40, 440) == SUCCESS);
    show_list(p_list, "insert berfore data");

    assert(get_start(p_list, &get_data) == SUCCESS);
    printf("get start data = %d\n", get_data);

    assert(get_end(p_list, &get_data) == SUCCESS);
    printf("get end data = %d\n", get_data);

    assert(remove_start(p_list) == SUCCESS);
    show_list(p_list, "remove start");

    assert(remove_end(p_list) == SUCCESS);
    show_list(p_list, "remove end");

    assert(pop_start(p_list, &get_data)== SUCCESS);
    printf("pop start data = %d\n", get_data);
    show_list(p_list, "pop start");

    assert(pop_end(p_list, &get_data)== SUCCESS);
    printf("pop end data = %d\n", get_data);
    show_list(p_list, "pop end");

    //assert(append_list(p_list1, p_list2) == SUCCESS);
    //show_list(p_list1, "append list ");

    //assert(concat_list(p_list1, p_list2, &p_concat_list) == SUCCESS);
    //show_list(p_concat_list, "concat list");

    assert(merge_list(p_list1, p_list2, &p_merge_list) == SUCCESS);
    show_list(p_merge_list, "merge list");

    assert(to_array(p_list1, &len, &p_arr) == SUCCESS);
    for(i = 0; i < len; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);
    
    assert(get_reversed_list(p_list1, &p_reversed_list) == SUCCESS);
    show_list(p_list1, "p_list");
    show_list(p_reversed_list, "reversed list");
    
    to_list(p_brr, 8, &p_arr_list);
    show_list(p_arr_list, "to list");
    assert(destroy_list(p_list) == SUCCESS);
    p_list = NULL;

    return(0);
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

struct node* create_list(void)
{
    return(get_new_node(-1));
}

struct node* get_new_node(int new_data)
{
    struct node* p_new_data = NULL;

    p_new_data = (struct node*)malloc(sizeof(struct node));
    assert(p_new_data != NULL);
    p_new_data->data = new_data;
    p_new_data->prev = NULL;
    p_new_data->next = NULL;

    return(p_new_data);
}

struct node* search_node(struct node* p_list, int search_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run->next != NULL)
    {
        if(p_run->data == search_data)
            break;
        p_run = p_run->next;
    }
    return(p_run);
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
        p_run = p_run->next;

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_new_node->prev = p_run;
    if(p_run->next != NULL)
        p_run->next->prev = p_new_node;
    p_run->next = p_new_node;

    return(SUCCESS);
}

int insert_after_data(struct node* p_list ,int ext_data, int new_data)
{
    struct node* p_search_node = NULL;
    struct node* p_new_node = NULL;

    p_search_node = search_node(p_list, ext_data);
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_search_node->next;
    p_new_node->prev = p_search_node;
    if(p_search_node->next != NULL)
        p_search_node->next->prev = p_new_node;
    p_search_node->next = p_new_node;

    return(SUCCESS);
}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_search_node = NULL;
    struct node* p_new_node = NULL;

    p_search_node = search_node(p_list, ext_data);
    p_new_node = get_new_node(new_data);

    p_new_node->next = p_search_node;
    p_new_node->prev = p_search_node->prev;
    p_search_node->prev->next = p_new_node;
    p_search_node->prev = p_new_node;

    return(SUCCESS);
}   

int get_start(struct node* p_list, int* get_start_data)
{
    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    *get_start_data = p_list->next->data;

    return(SUCCESS);
}

int get_end(struct node* p_list, int* get_end_data)
{
    struct node* p_run = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    p_run = p_list->next;
    while(p_run->next != NULL)
        p_run = p_run->next;
    
    *get_end_data = p_run->data;
    return(SUCCESS);
}

int remove_start(struct node* p_list)
{
    struct node* p_delete_node = NULL;

    p_delete_node = p_list->next;
    p_list->next = p_delete_node->next;
    free(p_delete_node);
    p_list->next->prev = p_list;

    return(SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* p_delete_node = NULL;
    struct node* p_run = NULL;

    p_delete_node = p_list;
    while(p_delete_node->next != NULL)
    {
        p_delete_node = p_delete_node->next;
    }

    p_delete_node->prev->next = p_delete_node->next;
    free(p_delete_node);
    p_delete_node = NULL;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* get_start_data)
{
    struct node* p_delete_node = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    
    p_delete_node = p_list->next;
    *get_start_data = p_delete_node->data;
    p_list->next = p_delete_node->next;
    free(p_delete_node);
    p_list->next->prev = p_list;

    return(SUCCESS);
}

int pop_end(struct node* p_list, int* get_end_data)
{
    struct node* p_delete_node = NULL;
    
    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);
    
    p_delete_node = p_list->next;
    while(p_delete_node->next != NULL)
        p_delete_node = p_delete_node->next;

    *get_end_data = p_delete_node->data;
    p_delete_node->prev->next = p_delete_node->next;
    free(p_delete_node);

    return(SUCCESS);
}

int append_list(struct node* p_list1, struct node* p_list2)
{
    struct node* p_run = NULL;

    p_run = p_list1;
    p_run = p_run->next;
    while(p_run->next != NULL)
        p_run = p_run->next;
    
    p_run->next = p_list2->next;
    free(p_list2);

    return(SUCCESS);
}

int concat_list(struct node* p_list1, struct node* p_list2, struct node** pp_concat_list)
{
    int status;
    struct node* p_run = NULL;
    struct node* p_concat_list = NULL;

    p_concat_list = create_list();
    p_run = p_list1->next;
    while(p_run != NULL)
    {
        assert(insert_at_end(p_concat_list, p_run->data) == SUCCESS);
        p_run = p_run->next;
    }

    p_run = p_list2->next;
    while(p_run != NULL)
    {
        assert(insert_at_end(p_concat_list, p_run->data) == SUCCESS);
        p_run = p_run->next;
    }
    
    *pp_concat_list = p_concat_list;
    return(SUCCESS);
}

int merge_list(struct node* p_list1, struct node* p_list2, struct node** pp_merge_list)
{
    int data = 0;
    struct node* p_run1 = NULL;
    struct node* p_run2 = NULL;
    struct node* p_merge_list = NULL;

    p_merge_list = create_list();

    p_run1 = p_list1->next;
    p_run2 = p_list2->next;

    while(1)
    {
        if(p_run1 == NULL)
        {
            while(p_run2 != NULL)
            {
                assert(insert_at_end(p_merge_list, p_run2->data) == SUCCESS);
                p_run2 = p_run2->next;
            }
            break;
        }

        if(p_run2 == NULL)
        {
            while(p_run1 != NULL)
            {
                assert(insert_at_end(p_merge_list, p_run1->data) == SUCCESS);
                p_run1 = p_run1->next;
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

        assert(insert_at_end(p_merge_list, data) == SUCCESS);
    }
    
        *pp_merge_list = p_merge_list;
        return(SUCCESS);
}

int to_array(struct node* p_list, int* N, int** pp_arr)
{
    int len = 0;
    int i = 0;
    int* p_arr = NULL;
    struct node* p_run = NULL;

    len = get_length(p_list);
    
    p_arr = (int*)calloc(len, sizeof(int));
    if(len == 0)
    {
        *pp_arr = p_arr;
        *N = len;
    }
    
    p_run = p_list->next;
    while(p_run != NULL)
    {
        p_arr[i++] = p_run->data;
        p_run = p_run->next;
    }

    *pp_arr = p_arr;
    *N = len;
    return(SUCCESS);
}

int get_length(struct node* p_list)
{
    int len = 0;
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        len++;
        p_run = p_run->next;
    }
    return(len);
}

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list)
{
    struct node* p_reversed_list = NULL;
    struct node* p_run = NULL;

    p_reversed_list = create_list();
    p_run = p_list->next;
    while(p_run != NULL)
    {
        assert(insert_at_start(p_reversed_list, p_run->data) == SUCCESS);
        p_run = p_run->next;
    }

    *pp_reversed_list = p_reversed_list;
    return(SUCCESS);
}

int to_list(int* p_arr, int size, struct node** pp_list)
{
    int i;
    struct node* p_list = NULL;

    p_list = create_list();
    for(i = 0; i < size; ++i)
        assert(insert_at_end(p_list, p_arr[i]) == SUCCESS);
    
    *pp_list = p_list;
    return(SUCCESS);

}
