#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
https://stackoverflow.com/questions/56317418/malloc-corrupted-top-size
*/

#define SUCCESS 1
#define FAILURE 2
#define LIST_DATA_NOT_FOUND 3
#define LIST_EMPTY          4
#define LIST_NOT_EMPTY      5
#define LIST_DATA_FOUND     6

struct node{
    int data;
    struct node* next;
};

/* Helper Routines */
struct node* get_new_node(int new_data);
struct node* search_node(struct node* p_list, int ext_data);

/* Routines that are called by clients to make use of list */

struct node* create_list(void);

int insert_at_start(struct node* p_list, int new_data);
int insert_at_end(struct node* p_list, int new_data);
int insert_after_data(struct node* p_list, int ext_data, int new_data);
int insert_before_data(struct node* p_list, int ext_data, int new_data);


int get_start(struct node* p_list, int* p_start_data); 
int get_end(struct node* p_list, int* p_end_data); 

int pop_start(struct node* p_list, int* p_start_data); 
int pop_end(struct node* p_list, int* p_end_data); 

int remove_start(struct node* p_list); 
int remove_end(struct node* p_list); 
int remove_data(struct node* p_list, int r_data); 

int is_list_empty(struct node* p_list); 
int find_data(struct node* p_list, int f_data); 

int concat_lists(struct node* p_list_1, struct node* p_list_2, 
                    struct node** pp_concat_list); 

int append_list(struct node* p_list_1, struct node* p_list_2); 
int merge_lists(struct node* p_list_1, struct node* p_list_2, 
                struct node** pp_merged_list); 

int to_array(struct node* p_list_1, int** pp_arr, int* p_size); 
int to_list(int* p_arr, int N, struct node** pp_list); 

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list); 
int reverse_list(struct node* p_list); 

void show_list(struct node* p_list, const char* msg);
int destroy_list(struct node* p_list);

void test_suite(void);
void test_suite2(void);
void test_suite3(void);
void test_suite4(void);

int main(void)
{
    
    test_suite();
    test_suite2();
    test_suite3();
    //test_suite4();

    return (0);
}

struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = (struct node*)malloc(sizeof(struct node));
    assert(p_new_node != NULL); 

    p_new_node->data = new_data;
    p_new_node->next = NULL;

    return (p_new_node);

}

struct node* create_list()
{
    struct node* p_list = NULL;

    p_list = get_new_node(-1);
    return (p_list);
}

int insert_at_start(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;

    p_new_node = get_new_node(new_data);

    p_new_node->next = p_list->next;
    p_list->next = p_new_node;

    return (1);
}

int insert_at_end(struct node* p_list, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_run = NULL;

    p_run = p_list;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    p_new_node = get_new_node(new_data);

    p_run->next = p_new_node;
    p_new_node->next = NULL;

    return (SUCCESS);
}

int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_new_node = NULL;
    struct node* p_ext_node = NULL;

    p_ext_node = search_node(p_list, ext_data);
    if(p_ext_node == NULL)
     {
        printf("List Data Not Found\n");
        return (FAILURE); 
     }

    p_new_node = get_new_node(new_data);
    
    p_new_node->next = p_ext_node->next;
    p_ext_node->next = p_new_node;

    return (SUCCESS);

}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_run = NULL;
    struct node* p_new_node = NULL;
    struct node* p_ext_prev_node = NULL;

    p_ext_prev_node = p_list;
    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(p_run->data == ext_data) 
            break;     
        p_ext_prev_node = p_run;
        p_run = p_run->next;
    }

    p_new_node = get_new_node(new_data);
    
    p_new_node->next = p_ext_prev_node->next;
    p_ext_prev_node->next = p_new_node;

    return (SUCCESS);
    
}

void show_list(struct node* p_list, const char* msg)
{
    if(msg)
        puts(msg);

    struct node* p_run = NULL;
    p_run = p_list->next;

    printf("[START]->");
    while(p_run != NULL)
    {
        printf("[%d]->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n");
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
        p_run = p_run_next;
    }
    free(p_list);
    return (SUCCESS);
}

struct node* search_node(struct node* p_list, int ext_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(p_run->data == ext_data)
            break;
        p_run = p_run->next;   
    }

    return (p_run);
    
}

int get_start(struct node* p_list, int* p_start_data)
{
    int data;

    if(p_list->next == NULL)
       return (LIST_EMPTY);
        
    data = p_list->next->data;
    *p_start_data = data;
    
    return (SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    int data;
    struct node* p_tmp_next= NULL; 

    if(p_list->next == NULL)
       return (LIST_EMPTY);
        
    data = p_list->next->data;
    *p_start_data = data;

    p_tmp_next = p_list->next;

    p_list->next = p_tmp_next->next;

    free(p_tmp_next);
    
    return (SUCCESS);
}


int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* p_run_prev = NULL;
    struct node* p_run = NULL;

    p_run_prev = p_list;
    p_run = p_list->next;
    while(p_run->next != NULL)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }

    *p_end_data = p_run->data;

    p_run_prev->next = p_run->next;

    free(p_run);

    return (SUCCESS);
}

int remove_start(struct node* p_list)
{
    struct node* p_tmp_next= NULL; 

    if(p_list->next == NULL)
       return (LIST_EMPTY);
            
    p_tmp_next = p_list->next;

    p_list->next = p_tmp_next->next;

    free(p_tmp_next);
    
    return (SUCCESS);
}

int remove_end(struct node* p_list)
{
    struct node* p_run_prev = NULL;
    struct node* p_run = NULL;

    p_run_prev = p_list;
    p_run = p_list->next;
    while(p_run->next != NULL)
    {
        p_run_prev = p_run;
        p_run = p_run->next;
    }

    p_run_prev->next = p_run->next;

    free(p_run);

    return (SUCCESS);
}


int remove_data(struct node* p_list, int r_data)
{
    struct node* p_run = NULL;
    struct node* p_run_prev = NULL;

    p_run_prev = p_list;
    p_run = p_list->next;
    
    while(p_run != NULL)
    {
        if(p_run->data == r_data)
            break;
        p_run_prev = p_run;
        p_run = p_run->next;   
    }

    if(p_run == NULL)
        return (LIST_DATA_NOT_FOUND);

    p_run_prev->next = p_run->next;

    free(p_run);

    return(SUCCESS);

}

int get_end(struct node* p_list, int* p_end_data)
{
    if(p_list->next == NULL)
        return (LIST_EMPTY);

    struct node* p_run = NULL;

    p_run = p_list;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    *p_end_data = p_run->data;
    
    return (SUCCESS);
}

int is_list_empty(struct node* p_list)
{
    if(p_list->next == NULL)
        return (LIST_EMPTY);
    else    
        return (LIST_NOT_EMPTY);
}

int find_data(struct node* p_list, int f_data)
{
    struct node* p_run = NULL;
    struct node* f_node = NULL;

    f_node = search_node(p_list, f_data);
    
    if(f_node == NULL)
        return (LIST_DATA_NOT_FOUND);
    else
        return (LIST_DATA_FOUND);
    
}

int concat_lists(struct node* p_list_1, struct node* p_list_2, 
                    struct node** pp_concat_list)
{
    struct node* p_run = NULL;
    struct node* p_run2 = NULL;
    struct node* p_concat_list = NULL;
    int ret;

    p_concat_list = create_list(); 

    p_run = p_list_1->next;
    while(p_run != NULL)
    {
        ret = insert_at_end(p_concat_list, p_run->data);
        assert(ret == SUCCESS);
        p_run = p_run->next;
    }
       
    p_run2 = p_list_2->next;  
    while(p_run2 != NULL)
    {
        ret = insert_at_end(p_concat_list, p_run2->data);
        assert(ret == SUCCESS);
        p_run2 = p_run2->next;
    }

    *pp_concat_list = p_concat_list;

    return (SUCCESS);
}

int append_list(struct node* p_list_1, struct node* p_list_2)
{
    struct node* p_run = NULL;

    p_run = p_list_1;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    p_run->next = p_list_2->next;  

    return (SUCCESS);
}

int merge_lists(struct node* p_list_1, struct node* p_list_2, 
                struct node** pp_merged_list)
{
    struct node* p_run1 = NULL;
    struct node* p_run2 = NULL;
    struct node* p_merged_list = NULL;
    int status;
    int data;

    p_merged_list = create_list();

    p_run1 = p_list_1->next;
    p_run2 = p_list_2->next;

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
           
        status = insert_at_end(p_merged_list, data);
        assert(status == SUCCESS);
    }
   
    *pp_merged_list = p_merged_list;
     return(SUCCESS);
}


int to_array(struct node* p_list_1, int** pp_arr, int* p_size)
{
    struct node* p_run = NULL;
    int* p_arr = NULL;
    int i;

    p_arr = (int*)malloc(*p_size * sizeof(int));
    assert(p_arr != NULL);

    i = 0;
    p_run = p_list_1->next;
    while(p_run != NULL)
    {
        p_arr[i] = p_run->data;
        i++;
        p_run = p_run->next;
    }
    
    *pp_arr = p_arr;
    *p_size = i;
    return(SUCCESS);
}


int to_list(int* p_arr, int N, struct node** pp_list)
{
    struct node* p_list = NULL;
    int ret;

    p_list = create_list();
 
    int i = 0;

    for(i = 0; i < N; ++i)
    {
        ret = insert_at_end(p_list, p_arr[i]);
        assert(ret == SUCCESS);
    }

    *pp_list = p_list;
    return(SUCCESS);
}



int get_reversed_list(struct node* p_list, struct node** pp_reversed_list)
{
    struct node* p_rev_list = NULL;
    struct node* p_run = NULL;
    int ret ;

    p_rev_list = create_list();

    p_run = p_list->next;
    while(p_run != NULL)
    {
        ret = insert_at_start(p_rev_list, p_run->data);
        assert(ret == SUCCESS);
        p_run = p_run->next;
    }

    *pp_reversed_list = p_rev_list;
    return(SUCCESS);
}

/*
int reverse_list(struct node* p_list)
{


    HEAD -> 1st -> 2nd -> 3rd -> 4th -> 5th -> NULL

    NULL <- 1st <- 2nd <- 3rd <- 4th <- 5th <- HEAD

    int count, i;
    struct node* p_run = NULL;
    struct node* temp_node = NULL;
    struct node* res_head_node = NULL;

    res_head_node = p_list;

    temp_node = p_list->next;


    temp_node->next = NULL;
/*
    struct node* p_run = NULL;
    p_run = p_list;
    while(p_run->next != NULL)
    {
        p_list = p_list->next;
    }

    int ret;
    struct node* p_run = NULL;
    p_run = p_list;
    while(p_run->next != NULL)
    {
        ret = insert_at_start(p_list, p_run->data);
        assert(ret == SUCCESS);
        p_run = p_run->next;
    }

    p_list = p_run;
    return(SUCCESS);

}
*/

/*
void test_suite4()
{
    struct node* p_list = NULL;
    int i = 0;
    int ret;

    p_list = create_list();

    for(i = 0; i < 10; ++i)
    {   
        ret = insert_at_end(p_list, (i+1) * 10);
        assert(ret == SUCCESS);
    }

    show_list(p_list, "Original List, before reversing original:");

    reverse_list(p_list);

    show_list(p_list, "Reversed List in the Original List itself:");


    destroy_list(p_list);
    p_list = NULL;
    
}
*/

void test_suite3()
{
    struct node* p_list = NULL;
    struct node* p_get_rev_list = NULL;
    int ret;
    int i;

    p_list = create_list();

    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_list, (i+1)*1000);
        assert(ret == SUCCESS);
    }

    show_list(p_list, "original list");

    ret = get_reversed_list(p_list, &p_get_rev_list);
    assert(ret == SUCCESS);

    show_list(p_get_rev_list, "reversed list");

    destroy_list(p_list);
    destroy_list(p_get_rev_list);
    p_list = NULL;
    p_get_rev_list = NULL;
}

void test_suite2(void)
{
    int i;
    struct node* p_list_1 = NULL;
    struct node* p_list_2 = NULL;
    struct node* p_concat_list = NULL;
    int ret;

    p_list_1 = create_list();
    p_list_2 = create_list();
    
    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_list_1, (i+1) * 10);
        assert(ret == SUCCESS);
    }
    show_list(p_list_1, "Showing list 1");

    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_list_2, (i+6) * 10);
        assert(ret == SUCCESS);
    }
    show_list(p_list_2, "Showing list 2");

    ret = concat_lists(p_list_1, p_list_2, &p_concat_list);
    assert(ret == SUCCESS);
    show_list(p_concat_list, "Showing Concatenated List");

    ret = append_list(p_list_1, p_list_2);
    assert(ret == SUCCESS);
    show_list(p_list_1, "Showing Append List");


    struct node* p_merge_list_input = NULL;
    struct node* p_merge_list_input_2 = NULL;
    struct node* p_merged_list = NULL;

    p_merge_list_input = create_list();
    p_merge_list_input_2 = create_list();

     for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_merge_list_input, (i+1) * 2);
        assert(ret == SUCCESS);
    }
    show_list(p_merge_list_input, "Showing Merge List Input 1");

    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_merge_list_input_2, (i+6) * 5);
        assert(ret == SUCCESS);
    }
    show_list(p_merge_list_input_2, "Showing Merge List Input 2");


    ret = merge_lists(p_merge_list_input, p_merge_list_input_2, &p_merged_list);
    assert(ret == SUCCESS);

    show_list(p_merged_list, "merged list");


    struct node* p_arr_list = NULL;
    p_arr_list = create_list();

    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_arr_list, (i+1) * 10);
        assert(ret == SUCCESS);
    }
    show_list(p_arr_list, "Showing Array List:");

    int* p_arr = NULL;
    int size = 0;
    ret = to_array(p_arr_list, &p_arr, &size);
    assert(ret == SUCCESS);
    
    for(i = 0; i < size; ++i)
        printf("Showing Array: arr[%d]=%d\n", i, p_arr[i]);
    
    int nr_of_element = 10;
    struct node* p_list_tolist = NULL;

    p_list_tolist = create_list();

    p_arr = (int*)calloc(nr_of_element, sizeof(int));
    assert(p_arr != NULL);

    for(i = 0; i < nr_of_element; ++i)
        p_arr[i] = (i+1)*100;
    
    ret = to_list(p_arr, nr_of_element, &p_list_tolist);
    assert(ret == SUCCESS);

    show_list(p_list_tolist, "Showing p_list_tolist");
    
    destroy_list(p_list_1);
    destroy_list(p_list_tolist);
    p_list_1 = NULL;
    p_list_tolist = NULL;
    free(p_arr);
    p_arr = NULL;

   destroy_list(p_merged_list);
   p_merged_list = NULL;
    
}

void test_suite(void)
{
    int i;
    struct node* p_list = NULL;
    int ret;
    int data;

    p_list = create_list();

    for(i = 0; i < 5; ++i)
     {
        ret = insert_at_start(p_list, (i + 1) * 10);
        assert(ret == SUCCESS);
     }

    show_list(p_list, "Insert at start");

    for(i = 0; i < 5; ++i)
        {
            ret = insert_at_end(p_list, (i + 6) * 10);
            assert(ret == SUCCESS);
        }

    show_list(p_list, "Insert at end");

    ret = insert_after_data(p_list, 60, 400);
    assert(ret == SUCCESS);
    show_list(p_list, "Insert after 60: 400");

    ret = insert_before_data(p_list, 60, 300);
    assert(ret == SUCCESS);
    show_list(p_list, "Insert before 60: 300");

    ret = get_start(p_list, &data);
    printf("Start Data: %d\n", data);

    ret = get_end(p_list, &data);
    printf("End data: %d\n", data);

    ret = pop_start(p_list, &data);
    printf("After Pop start: %d\n", data);
    show_list(p_list, "After Pop_Start:");

    ret = pop_end(p_list, &data);
    printf("After Pop End: %d\n", data);
    show_list(p_list, "After Pop_End:");

    ret = remove_start(p_list);
    show_list(p_list, "After Remove Start:\n");

    ret = remove_end(p_list);
    show_list(p_list, "After Remove End:\n");

    ret = remove_data(p_list, 400);
    show_list(p_list, "After Remove data 400:\n");

    ret = is_list_empty(p_list);
    if(ret == LIST_EMPTY)
        puts("List is empty");
    else if(ret == LIST_NOT_EMPTY)  
        puts("List is Not Empty");
    else    
        puts("List is Invalid");

    ret = find_data(p_list, 60);
    if(ret == LIST_DATA_NOT_FOUND)
        puts("List Data Not Found");
    else if(ret == LIST_DATA_FOUND)
        puts("List Data Found");

    ret = find_data(p_list, 1000);
    if(ret == LIST_DATA_NOT_FOUND)
        puts("List Data Not Found");
    else if(ret == LIST_DATA_FOUND)
        puts("List Data Found");

    destroy_list(p_list);

}