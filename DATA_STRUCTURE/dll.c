#include "header.h"


struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;
    
    p_new_node = (struct node*)malloc(sizeof(struct node));
    assert(p_new_node != NULL);
            
    p_new_node->data = new_data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;
        
    return (p_new_node);   
}

struct node* create_list(void)
{
    struct node* p_list = NULL;

    p_list = get_new_node(-1);
    p_list->next = p_list;
    p_list->prev = p_list;
            
    return (p_list);
}


int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(new_data);
    p_new_node->next = p_list->next;
    p_new_node->prev = p_list;
    
    if(p_list->next != p_list)
        p_list->next->prev = p_new_node;

    p_list->next = p_new_node;

    return (SUCCESS);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_run = NULL;
    struct node* p_new_node = NULL;

    p_run = p_list;
    while(p_run->next != p_list)
        p_run = p_run->next;
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_run->next;
    p_new_node->prev = p_run->next->prev;

    p_run->next = p_new_node;
    return (SUCCESS);
}

int get_start(struct node* p_list, int* get_data)
{
    
    if(p_list->next == NULL && p_list->prev == NULL)
        return (LIST_EMPTY);
        
    *get_data = p_list->next->data;

    return (SUCCESS);
    
}

int get_end(struct node* p_list, int* get_end)
{
    struct node* p_run = NULL;

    if(p_list->next == p_list && p_list->prev == p_list)
        return (LIST_EMPTY);
    
    p_run = p_list->next;
    while(p_run->next != p_list)
        p_run = p_run->next;
    
    *get_end = p_list->prev->data;
     return (SUCCESS);
}


int remove_start(struct node* p_list)
{
    if(p_list->next == p_list && p_list->prev == p_list)
        return(LIST_EMPTY);
    struct node* p_remove_start = NULL;
    
    p_remove_start = p_list->next;
    p_list->next = p_remove_start->next;
    
    free(p_remove_start);
    p_remove_start = NULL;

    return(SUCCESS);
}

int remove_end(struct node* p_list)
{
    if((p_list->next == p_list) && (p_list->prev = p_list))
        return(LIST_EMPTY);
    struct node* p_run = NULL;

    p_run = p_list;
    while(p_run != p_list)
    {
        p_run = p_run->next;
    }
    p_run->prev->next = p_list;
    p_list->prev = p_run->prev->next;
    free(p_run);
    p_run = NULL;
    
    return(SUCCESS);
}

int to_list(int* p_arr, int* p_arr_size, struct node** pp_list)
{
    struct node* p_list = NULL;
    int N = 0;
    int status;

    p_list = create_list();
    N = sizeof(p_arr)/sizeof(int);
    
    int i = 0;
    for(i = 0; i < N; ++i)
    {
        status = insert_at_end(p_list, p_arr[i]);
        assert(status == SUCCESS);
    }
    *p_arr_size = N;
    *pp_list = p_list;
    
    return(SUCCESS);
}

int to_array(struct node* p_list_1, int** pp_arr, int* p_arr_size)
{
    int* p_arr = NULL;
    int len_p_list_1 = 0;
    struct node* p_run = NULL;
    int i = 0;

    len_p_list_1 = get_length(p_list_1);
    p_run = p_list_1->next;
    
    while(p_run != p_list_1)
    {
        p_arr[i] = p_list_1->data;
        p_run = p_run->next;
        i++;
    }
    *p_arr_size = len_p_list_1;
    *pp_arr = p_arr;
    return(SUCCESS);
}


int pop_start(struct node* p_list, int* pop_start_data)
{
    if(p_list->next == NULL && p_list->prev == NULL)
        return (LIST_EMPTY);
        
    struct node* pop_s_node = NULL;

    pop_s_node = p_list->next;
    *pop_start_data = pop_s_node->data;

    p_list->next = pop_s_node->next;
    free(pop_s_node); 
    pop_s_node = NULL;

    return (SUCCESS);
    
}

int pop_end(struct node* p_list, int* pop_data)
{
    struct node* p_delete_node = NULL; 

    if(p_list->next == p_list && p_list->prev == p_list)
        return (LIST_EMPTY); 

    p_delete_node = p_list; 
    while(p_delete_node->next != p_list)
    {
        p_delete_node = p_delete_node->next; 
    }

    *pop_data = p_delete_node->data; 
    p_delete_node->prev->next = p_list; 
    free(p_delete_node); 
    p_delete_node = NULL; 

    return (SUCCESS); 

}


int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_search_node = NULL;

    p_search_node = search_data(p_list, ext_data);
    if(p_search_node == p_list)
        return(LIST_DATA_NOT_FOUND);
    
    p_new_node = get_new_node(new_data);
    p_new_node->next = p_search_node->next;
    p_new_node->prev = p_search_node;
    p_search_node->next = p_new_node;

    return(SUCCESS);
}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_search_node = NULL;

    p_search_node = search_data(p_list, ext_data);
    if(p_search_node == p_list)
        return(LIST_DATA_NOT_FOUND);

    p_new_node = get_new_node(new_data);
    p_search_node->prev->next = p_new_node;
    p_new_node->prev = p_search_node->prev;
    p_new_node->next = p_search_node;

    return(SUCCESS);
}

int merge_list(struct node* p_list_1, struct node* p_list_2, struct node** pp_merged_list)
{
    struct node* p_run_1 = NULL;
    struct node* p_run_2 = NULL;    
    struct node* p_merged_list = NULL;
    int status;
    int data = 0;

    p_merged_list = create_list();

    p_run_1 = p_list_1->next;
    p_run_2 = p_list_2->next;
    while(1)
    {
        if(p_run_1 == p_list_1)
        {
            while(p_run_2 != p_list_2)
            {
                status = insert_at_end(p_merged_list, p_run_2->data);
                assert(status == SUCCESS);
            }
            break;
        }
        if(p_run_2 == p_list_2)
        {
            while(p_run_1 != p_list_2)
            {
                status = insert_at_end(p_merged_list, p_run_1->data);
                assert(status == SUCCESS);
            }
            break;
        }
    
        if(p_run_1->data <= p_run_2->data)
        {
            data = p_run_1->data;
            p_run_1 = p_run_1->next;
        }
        else
        {
            data = p_run_2->data;
            p_run_2 = p_run_2->next;
        }

        status = insert_at_end(p_merged_list, data);
        assert(status == SUCCESS);
        
    }
    *pp_merged_list = p_merged_list;
    return(SUCCESS);
}


int append_list(struct node* p_list_1, struct node* p_list_2)
{
    struct node* p_run = NULL;

    while(p_run !=  p_list_1)
        p_run = p_run->next;
    p_run->next = p_list_2->next;
    while(p_run != p_list_2)
        p_run = p_run->next;
    
    p_run->next = p_list_1;
    free(p_list_2);
    p_list_2 = NULL;

    return(SUCCESS);
}


int concat_list(struct node* p_list_1, struct node* p_list_2, struct node** pp_concat_list)
{
    struct node* p_concat_list = NULL;
    struct node* p_run_1 = NULL;
    struct node* p_run_2 = NULL;
    int status ;

    p_concat_list = create_list();

    if(p_run_2 == p_list_2)
        *pp_concat_list = p_list_1;
    else if(p_run_1 == p_list_1)
        *pp_concat_list = p_list_2;

    p_run_1 = p_list_1->next;
    while(p_run_1 != p_list_1)
    {
        status = insert_at_end(p_concat_list, p_run_1->data);
        assert(status == SUCCESS);
    }
    p_run_2 = p_list_2->next;
    while(p_run_2 != p_list_2)
    {
        status = insert_at_end(p_concat_list, p_run_2->data);
        assert(status == SUCCESS);
    }

    return(SUCCESS);
}

struct node* search_data(struct node* p_list, int search_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != p_list)
    {
        if(p_run->data == search_data)
            break;
        p_run = p_run->next;
    }
    return(p_run);
}

int get_length(struct node* p_list)
{
    struct node* p_run = NULL;
    int len = 0;
    
    p_run = p_list->next;
    while(p_run != p_list)
    {
        len++;
        p_run = p_run->next;
    }
    return(len);
}

void show_list(struct node* p_list, char* msg)
{
    if(msg)
        puts(msg);
    struct node* p_run = NULL;

    printf("[START]<->");
    p_run = p_list->next;
    while(p_run != p_list)
    {
        printf("[%d]<->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n");
}

void destroy_list(struct node* p_list)
{
    struct node* p_run = NULL;
    struct node* p_temp = NULL;
    
    p_run = p_list->next;
    while(p_run != p_list)
    {
        p_temp = p_run;
        free(p_temp);
        p_run = p_run->next;
    }
    free(p_list);
    p_list = NULL;
}

int remove_data(struct node* p_list, int r_data)
{
    struct node* p_search_node = NULL;

    p_search_node = search_data(p_list, r_data);
    if(p_search_node == p_list)
        return(LIST_DATA_NOT_FOUND);

    p_search_node->prev->next = p_search_node->next;
    free(p_search_node);
    p_search_node = NULL;

    return(SUCCESS);
}



int get_reversed_list(struct node* p_list, struct node** p_rev_list)
{
    struct node* p_reversed_list = NULL;
    struct node* p_run = NULL;

    p_reversed_list = create_list();

    int ret = 0;

    p_run = p_list->next;
    while(p_run != p_list)
    {
        ret = insert_at_start(p_reversed_list, p_list->data);
        p_run = p_run->next;
    }

    *p_rev_list = p_reversed_list;

    return (SUCCESS);

}

int find_data(struct node* p_list, int f_data)
{
    struct node* f_node = NULL;
    
    f_node = search_data(p_list, f_data);

    if(f_node->data == f_data)
        return (LIST_DATA_FOUND);
    else    
        return (LIST_DATA_NOT_FOUND);
}

