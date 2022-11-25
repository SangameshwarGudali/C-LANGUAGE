#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS             1
#define TRUE                1
#define FALSE               0

#define LIST_DATA_FOND      2
#define LIST_DATA_NOT_FOUND 3

#define LIST_EMPTY          4

struct node
{
    int data;
    struct node* next;
};

struct node* create_list(void);
struct node* get_new_node(int new_data);
int insert_at_start(struct node* p_list, int new_data);
int insert_at_end(struct node* p_list, int new_data);
void show_list(struct node* p_list, const char* msg);

int main(void)
{
    int i = 0;
    int status;
    int get_data = 0;
    int length = 0;
    int* p_arr = NULL;
    struct node* p_list = NULL;
    struct node* p_concat_list = NULL;
    struct node* p_merged_list = NULL;
    struct node* p_arr_list = NULL;
    struct node* p_reversed_list = NULL;

    struct node* p_list1 = NULL;
    struct node* p_list2 = NULL;

    p_list1 = create_list();
    p_list2 = create_list();

    for(i=10; i<100; i=i+10)
    {
        status = insert_at_end(p_list1, i);
        assert(status == SUCCESS);
    }
    show_list(p_list1, "p_list1");

    for(i=10; i<100; i=i+20)
    {
        status = insert_at_end(p_list2, i);
        assert(status == SUCCESS);
    }
    show_list(p_list2, "p_list2");

    
    /*
    p_list = create_list();

    for(i = 10; i<=100; i=i+10)
    {
        status = insert_at_end(p_list, i);
        assert(status == SUCCESS);
    }
    show_list(p_list, "insert at end");

    status = insert_before_data(p_list, 10, 555);
    assert(status == SUCCESS);
    show_list(p_list, "insert before 40");

    status = insert_after_data(p_list, 100, 999);
    assert(status == SUCCESS);
    show_list(p_list, "insert after 60");

    status = get_start(p_list, &get_data);
    assert(status == SUCCESS);
    printf("get start data = %d\n", get_data);

    status = get_end(p_list, &get_data);
    assert(status == SUCCESS);
    printf("get end data = %d\n", get_data);

    status = pop_start(p_list, &get_data);
    assert(status == SUCCESS);
    printf("pop_start = %d\n", get_data);
    show_list(p_list, "pop start");

    status = pop_end(p_list, &get_data);
    assert(status == SUCCESS);
    printf("pop_end = %d\n", get_data);
    show_list(p_list, "pop end");

    status = remove_start(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "remove start");

    status = remove_end(p_list);
    assert(status == SUCCESS);
    show_list(p_list, "remove end");

    status = remove_data(p_list, 60);
    assert(status == SUCCESS);
    show_list(p_list, "remove data 60");
    
    status = get_length(p_list, &length);
    assert(status == SUCCESS);
    printf("length = %d\n", length);

    status = insert_at_end(p_list, 666);
    assert(status == SUCCESS);
    show_list(p_list, "insert 666");
    
    status = get_length(p_list, &length);
    assert(status == SUCCESS);
    printf("length = %d\n", length);

    status = find_data(p_list, 20);
    if(status == LIST_DATA_FOND)
        puts("list data found");
    else
        puts("list data not found");


    status = concat_lists(p_list1, p_list2, &p_concat_list);
    assert(status == SUCCESS);
    show_list(p_concat_list, "concated list");

    status = append_list(p_list1, p_list2);
    assert(status = SUCCESS);
    show_list(p_list1, "append list");

    status = merge_lists(p_list1, p_list2, &p_merged_list);
    assert(status == SUCCESS);
    show_list(p_merged_list, "merged list");
*/

    int arr[8] = {11,22,33,44,55,66,77,88};

    status = to_array(p_list1, &p_arr, &length);
    assert(status == SUCCESS);
    for(i = 0; i<length; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);

    status = to_list(arr, 8, &p_arr_list);
    assert(status == SUCCESS);
    show_list(p_arr_list, "array convert into list");

    status = get_reversed_list(p_arr_list, &p_reversed_list);
    assert(status == SUCCESS);
    show_list(p_reversed_list, "after reversed list");
    
    return(0);
}
/* Interface routines declarations */ 
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
    p_new_node->data = new_data;
    p_new_node->next = p_new_node;

    return(p_new_node);
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_first_node = NULL;

    p_first_node = get_new_node(new_data);
    p_first_node->next = p_list->next;
    p_list->next = p_first_node;

    return(SUCCESS);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_last_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list;
    while(p_run->next != p_list)
    {
        p_run = p_run->next;
    }
    p_last_node = get_new_node(new_data);
    p_last_node->next = p_run->next;
    p_run->next = p_last_node;

    return(SUCCESS);

}

void show_list(struct node* p_list, const char* msg)
{
    struct node* p_run = NULL;

    if(msg != NULL)
        puts(msg);
    
    p_run = p_list->next;
    printf("[START]->");
    while(p_run != p_list)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[End]\n");
}


int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != p_list)
    {
        if(p_run->data == ext_data)
            break;
        p_run = p_run->next;
    }
    if(p_run == p_list)
        return(LIST_DATA_NOT_FOUND);
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_run->next = p_new_node;

    return(SUCCESS);
}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;

    p_run = p_list->next;
    p_run_prev = p_list;
    while(p_run != p_list)
    {
        if(ext_data == p_run->data)
            break;
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    if(p_run == p_list)
        return(LIST_DATA_NOT_FOUND);
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run_prev->next;
    p_run_prev->next = p_new_node;

    return(SUCCESS);

}

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list->next == p_list)
        return(LIST_EMPTY);
    *p_start_data = p_list->next->data;
    return(SUCCESS);
}

int get_end(struct node* p_list, int* p_end_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run->next != p_list)
    {
        p_run = p_run->next;
    }
    *p_end_data = p_run->data;

    return(SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* p_first_node = NULL;
    if(p_list->next == p_list)
        return(LIST_EMPTY);
    p_first_node = p_list->next;
    *p_start_data = p_first_node->data;
    p_list->next = p_first_node->next;
    free(p_first_node);

    return(SUCCESS);
}

int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run->next != p_list)
        p_run = p_run->next;
    *p_end_data = p_run->data;
    p_run->next = p_list;
    free(p_run);

    return(SUCCESS);
}

int remove_start(struct node* p_list)
{
    struct node* p_first_node = NULL;

    if(p_list->next == p_list)
        return(LIST_EMPTY);
    p_first_node = p_list->next;
    p_list->next = p_first_node->next;
    free(p_first_node);

    return(SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;

    if(p_list->next == p_list)
        return(LIST_EMPTY);
    p_run = p_list->next;
    p_run_prev = p_list;
    while(p_run->next != p_list)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    p_run_prev->next = p_run->next;
    free(p_run);

    return(SUCCESS);
}

int remove_data(struct node* p_list, int r_data)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;

    p_run = p_list->next;
    p_run_prev = p_list;
    while(p_run != p_list)
    {
        if(p_run->data == r_data)
            break;
        p_run_prev = p_run;
        p_run = p_run->next;
    }
    if(p_run == p_list)
        return(LIST_DATA_NOT_FOUND);
    p_run_prev->next = p_run->next;
    free(p_run);

    return(SUCCESS);
}

int get_length(struct node* p_list, int* length)
{
    struct node* p_run = NULL;
    int len = 0;
    
    if(p_list->next == p_list)
        return(LIST_EMPTY);
    
    p_run = p_list->next;
    while(p_run != p_list)
    {
        len++;
        p_run = p_run->next;
    }
    *length = len;
    return(SUCCESS);
}

int is_list_empty(struct node* p_list)
{
    if(p_list->next == p_list)
    {
        puts("list is empty");
        return(LIST_EMPTY);
    }
    else
        puts("list is not empty");
    return(SUCCESS);
}


int find_data(struct node* p_list, int f_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != p_list)
    {
        if(p_run->data == f_data)
            return(LIST_DATA_FOND);
        p_run = p_run->next;
    }
    if(p_run == p_list);
        return(LIST_DATA_NOT_FOUND);
    return(SUCCESS);
}

//int destroy_list(struct node* p_list); 

int concat_lists(struct node* p_list_1, struct node* p_list_2, struct node** pp_concat_list)
{
    int status;
    struct node* p_run = NULL;
    struct node* p_concat_list = NULL;

    p_concat_list = create_list();
    
    p_run = p_list_1->next;
    while(p_run != p_list_1)
    {
        status = insert_at_end(p_concat_list, p_run->data);
        assert(status == SUCCESS);
        p_run = p_run->next;
    }
    p_run = p_list_2->next;
    while(p_run != p_list_2)
    {
        status = insert_at_end(p_concat_list, p_run->data);
        assert(status = SUCCESS);
        p_run = p_run->next;
    }

    *pp_concat_list = p_concat_list;
    return(SUCCESS);
}

int append_list(struct node* p_list_1, struct node* p_list_2)
{
    struct node* p_run = NULL;

    p_run = p_list_1;
    while(p_run->next != p_list_1)
        p_run = p_run->next;
    p_run->next = p_list_2->next;
    free(p_list_2);
    while(p_run->next != p_list_2)
        p_run = p_run->next;

    return(SUCCESS);
}

int merge_lists(struct node* p_list_1, struct node* p_list_2, struct node** pp_merged_list)
{
    int data = 0;
    int status;
    struct node* p_run1 = NULL;
    struct node* p_run2 = NULL;
    struct node* p_merged_list = NULL;

    p_run1 = p_list_1->next;
    p_run2 = p_list_2->next;

    p_merged_list = create_list();


    while(1)
    {
        if(p_run1 == p_list_1)
        {
            while(p_run2 != p_list_2)
            {
                status = insert_at_end(p_merged_list, p_run2->data);
                assert(status == SUCCESS);
                p_run2 = p_run2->next;
            }
            break;
        }
        if(p_run2 == p_list_2)
        {
            while(p_run1 != p_list_1)
            {
                status = insert_at_end(p_merged_list, p_run1->data);
                assert(status == SUCCESS);
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
            p_run2 =p_run2->next;
        }
    }
    *pp_merged_list = p_merged_list;
    return(SUCCESS);
}

int to_array(struct node* p_list_1, int** pp_arr, int* p_size)
{
    int* p_arr = NULL;
    int status;
    int i = 0;
    int len = 0;
    struct node* p_run = NULL;

    status = get_length(p_list_1, &len);
    assert(status == SUCCESS);
    printf("len = %d\n", len);

    if(len == 0)
    {
        *pp_arr = p_arr;
        *p_size = len;
    }
    
    p_arr = (int*)calloc(len, sizeof(int));
    if(p_arr == NULL){
        puts("calloc : Memory allocation failed in array");
        return(EXIT_FAILURE);
    }

    p_run = p_list_1->next;
    while(p_run != p_list_1)
    {
        p_arr[i++] = p_run->data;
        p_run = p_run->next;
    }

    *pp_arr = p_arr;
    *p_size = len;

    return(SUCCESS);

}

int to_list(int* p_arr, int N, struct node** pp_list)
{
    int i;
    int status;
    struct node* p_list = NULL;

    p_list = create_list();

    for(i = 0; i<N; ++i)
    {
        status = insert_at_end(p_list, p_arr[i]);
        assert(status == SUCCESS);
    }

    *pp_list = p_list;
    return(SUCCESS);
}

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list) 
{
    struct node* p_reversed_list = NULL;
    struct node* p_run = NULL;

    p_reversed_list = create_list();

    p_run = p_list->next;
    while(p_run != p_list)
    {
        assert(insert_at_start(p_reversed_list, p_run->data) == SUCCESS);
        p_run = p_run->next;
    }
    *pp_reversed_list = p_reversed_list;

    return(SUCCESS);
}

int reverse_list(struct node* p_list)
{
    return(SUCCESS);
}