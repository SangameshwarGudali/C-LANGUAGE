#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

#define SUCCESS 1 

#define TRUE    1 
#define FALSE   0 

#define LIST_DATA_NOT_FOUND 2 
#define LIST_EMPTY          3 

struct node 
{
    int data;           /* data element */ 
    struct node* prev;  /* backward link */ 
    struct node* next;  /* forward link */ 
}; 

/* Interface routines declarations */ 
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

int get_length(struct node* p_list); 
int is_list_empty(struct node* p_list); 
int find_data(struct node* p_list, int f_data); 

void show_list(struct node* p_list, const char* msg);
int destroy_list(struct node* p_list); 

int concat_lists(struct node* p_list_1, struct node* p_list_2, 
                    struct node** pp_concat_list); 

int append_list(struct node* p_list_1, struct node* p_list_2); 
int merge_lists(struct node* p_list_1, struct node* p_list_2, 
                struct node** pp_merged_list); 

int to_array(struct node* p_list_1, int** pp_arr, int* p_size); 
int to_list(int* p_arr, int N, struct node** pp_list); 

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list); 
int reverse_list(struct node* p_list); 


/* Helper routines declaration */ 
struct node* get_new_node(int new_data); 
struct node* search_node(struct node* p_list, int search_data); 

int main(void)
{
    struct node* p_list = NULL; 
    int status; 
    int data; 

    p_list = create_list(); 
    show_list(p_list, "Showing list just after creation:"); 

    for(data = 10; data <= 60; data = data + 10)
    {
        status = insert_at_end(p_list, data); 
        assert(status == SUCCESS); 
    }
    show_list(p_list, "Showing after insert_at_end():"); 

    for(data = 100; data <= 600; data = data + 100)
    {
        status = insert_at_start(p_list, data); 
        assert(status == SUCCESS); 
    }
    show_list(p_list, "Showing after insert_at_start():"); 

    status = insert_after_data(p_list, 10, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "After inserting 0 after 10:"); 

    status = insert_before_data(p_list, 10, -1); 
    assert(status == SUCCESS); 
    show_list(p_list, "After inserting -1 before 10"); 

    status = insert_before_data(p_list, 600, -600); 
    assert(status == SUCCESS); 
    show_list(p_list, "After inserting -600 before 600"); 

    status = insert_after_data(p_list, 60, -60); 
    assert(status == SUCCESS); 
    show_list(p_list, "After inserting -60 after 60"); 

    status = insert_after_data(p_list, -500, 10); 
    assert(status == LIST_DATA_NOT_FOUND); 
    puts("-500 is not present in list"); 

    status = insert_before_data(p_list, -500, 10); 
    assert(status == LIST_DATA_NOT_FOUND); 
    puts("-500 is not present in list"); 

    status = get_start(p_list, &data); 
    assert(status == SUCCESS); 
    printf("start data = %d\n", data); 
    show_list(p_list, "After get_start():"); 

    status = get_end(p_list, &data); 
    assert(status == SUCCESS); 
    printf("end data = %d\n", data); 
    show_list(p_list, "After get_end():"); 

    status = pop_start(p_list, &data); 
    assert(status == SUCCESS); 
    printf("start data = %d\n", data); 
    show_list(p_list, "After pop_start():"); 

    status = pop_end(p_list, &data); 
    assert(status == SUCCESS); 
    printf("end data = %d\n", data); 
    show_list(p_list, "After pop_end():"); 

    status = remove_start(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "After remove_start():"); 

    status = remove_end(p_list); 
    assert(status == SUCCESS); 
    show_list(p_list, "After remove_end():"); 

    status = remove_data(p_list, 0); 
    assert(status == SUCCESS); 
    show_list(p_list, "After remove_data():"); 

    if(is_list_empty(p_list) == FALSE)
        puts("List is not empty at the moment"); 

    if(find_data(p_list, 200) == TRUE)
        puts("200 is present in list at the moment"); 

    if(find_data(p_list, -5214) == FALSE)
        puts("-2514 is not present in list at the moment"); 

    status = destroy_list(p_list); 
    p_list = NULL; 
    assert(status == SUCCESS); 

    // extreme_testing(); 
    puts("SUCCESS"); 
    return (EXIT_SUCCESS); 
}

/* Interface routines declarations */ 
struct node* create_list(void)
{
    return get_new_node(-1); 
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

    return (SUCCESS); 
}

int insert_at_end(struct node* p_list, int new_data)
{

}

int insert_after_data(struct node* p_list, int ext_data, int new_data)
{

}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{

}  

int get_start(struct node* p_list, int* p_start_data)
{

}

int get_end(struct node* p_list, int* p_end_data)
{

}

int pop_start(struct node* p_list, int* p_start_data)
{

}

int pop_end(struct node* p_list, int* p_end_data)
{

}

int remove_start(struct node* p_list)
{

}

int remove_end(struct node* p_list)
{

}

int remove_data(struct node* p_list, int r_data)
{

}

int get_length(struct node* p_list)
{

}

int is_list_empty(struct node* p_list)
{

}

int find_data(struct node* p_list, int f_data)
{

}

void show_list(struct node* p_list, const char* msg)
{

}

int destroy_list(struct node* p_list)
{

}

int concat_lists(struct node* p_list_1, struct node* p_list_2, 
                    struct node** pp_concat_list); 

int append_list(struct node* p_list_1, struct node* p_list_2); 
int merge_lists(struct node* p_list_1, struct node* p_list_2, 
                struct node** pp_merged_list); 

int to_array(struct node* p_list_1, int** pp_arr, int* p_size); 
int to_list(int* p_arr, int N, struct node** pp_list); 

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list); 
int reverse_list(struct node* p_list); 


/* Helper routines declaration */ 
struct node* get_new_node(int new_data)
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)malloc(sizeof(struct node)); 
    assert(p_new_node != NULL); 
    p_new_node->data = new_data; 
    p_new_node->prev = NULL; 
    p_new_node->next = NULL; 

    return (p_new_node); 
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

    return (p_run); 
}