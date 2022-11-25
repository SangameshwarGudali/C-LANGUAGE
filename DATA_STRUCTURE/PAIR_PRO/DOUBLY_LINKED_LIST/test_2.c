#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS             1
#define LIST_DATA_FOUND     2
#define LIST_DATA_NOT_FOUND 3
#define LIST_IS_EMPTY       4
#define LIST_IS_NOT_EMPTY   5


struct node* create_list(void);
struct node* get_new_node(int data);
struct node* search_node(struct node* p_list, int search_data);

int insert_at_end(struct node* p_list, int new_data);
int insert_at_start(struct node* p_list, int new_data);
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

int concat_lists(struct node* p_list_1, struct node* p_list_2, 
                    struct node** pp_concat_list); 

int append_list(struct node* p_list_1, struct node* p_list_2); 
int merge_lists(struct node* p_list_1, struct node* p_list_2, 
                struct node** pp_merged_list); 

int to_array(struct node* p_list_1, int** pp_arr, int* p_size); 
int to_list(int* p_arr, int N, struct node** pp_list); 

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list); 
int reverse_list(struct node* p_list); 

void destroy_list(struct node* p_list);
void show_list(struct node* p_list, char* msg);


void test_suite(void);
void test_suite_2(void);
void test_suite_3(void);
void test_suite_4(void);


struct node {
    int data;
    struct node* prev;
    struct node* next;
};

int main(void)
{
    //test_suite();
    //test_suite_2();
    //test_suite_3();
    test_suite_4();

    return (0);
}

struct node* create_list(void)
{
    struct node* p = NULL;

    p = get_new_node(-1);

    return p;
}

struct node* get_new_node(int new_data)
{
    struct node* p = NULL;

    p = (struct node*)malloc(sizeof(struct node));
    assert(p != NULL);

    p->data = new_data;
    p->next = NULL;
    p->prev = NULL;
    
    return (p);
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
    p_run->next = p_new_node;

    return(SUCCESS);
}

int insert_after_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_ext_node = NULL;
    struct node* p_new_node = NULL;

    if(p_list->next == NULL)
        return (LIST_IS_EMPTY);

    p_ext_node = search_node(p_list, ext_data);
    if(p_ext_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    p_new_node = get_new_node(new_data);

    p_new_node->next=p_ext_node->next;
    p_new_node->prev= p_ext_node;
    p_ext_node->next = p_new_node;

    return (SUCCESS);
}

int insert_before_data(struct node* p_list, int ext_data, int new_data)
{
    struct node* p_ext_node = NULL;
    struct node* p_new_node = NULL;

    if(p_list->next == NULL)
        return(LIST_IS_EMPTY);

    p_ext_node = search_node(p_list, ext_data);
    if(p_ext_node == NULL)
        return(LIST_DATA_NOT_FOUND);
    
    p_new_node = get_new_node(new_data);

    p_new_node->next = p_ext_node->prev->next;
    p_new_node->prev = p_ext_node->prev;
    p_ext_node->prev->next = p_new_node;

    return(SUCCESS);
    
}   

int get_start(struct node* p_list, int* p_start_data)
{
    if(p_list->next == NULL)
        return (LIST_IS_EMPTY);
    
    *p_start_data = p_list->next->data;

    return (SUCCESS);
}

int get_end(struct node* p_list, int* p_end_data)
{ 
   struct node* p_run = NULL;

    if(p_list->next == NULL)
        return (LIST_IS_EMPTY);

    p_run = p_list;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    *p_end_data = p_run->data;  
    return (SUCCESS);
}

int pop_start(struct node* p_list, int* p_start_data)
{
    struct node* p_remove_node = NULL;

    if(p_list->next == NULL)
      return (LIST_IS_EMPTY);
    
    *p_start_data = p_list->next->data;

    p_remove_node = p_list->next;
    p_list->next = p_remove_node->next;
    free(p_remove_node);
    
    return (SUCCESS);
    
}

int pop_end(struct node* p_list, int* p_end_data)
{
    struct node* p_run = NULL;

    if(p_list->next == NULL)
        return (LIST_IS_EMPTY);

    p_run = p_list;
    while(p_run->next != NULL)
    {
        p_run = p_run->next;
    }

    *p_end_data = p_run->data;

    p_run->prev->next = p_run->next;
    free(p_run);

    return (SUCCESS);
}

int remove_start(struct node* p_list)
{
    struct node* p_remove_node = NULL;

    if(p_list->next == NULL)
      return (LIST_IS_EMPTY);
    
    p_remove_node = p_list->next;
    p_list->next = p_remove_node->next;
    free(p_remove_node);
    
    return (SUCCESS);
}


int remove_end(struct node* p_list)
{
    struct node* p_run = NULL;

    if(p_list->next == NULL)
        return (LIST_IS_EMPTY);

    p_run = p_list;
    while(p_run->next != NULL)
        p_run = p_run->next;
    
    p_run->prev->next = p_run->next;
    free(p_run);

    return (SUCCESS);
}

int remove_data(struct node* p_list, int r_data)
{
    struct node* p_search_node = NULL;

    if(p_list->next == NULL)
      return (LIST_IS_EMPTY);

    p_search_node = search_node(p_list, r_data);

    p_search_node->prev->next = p_search_node->next;
    
    free(p_search_node);
    p_search_node = NULL;

    return (SUCCESS);
}


struct node* search_node(struct node* p_list, int search_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(p_run->data == search_data)
            break; 
        p_run = p_run->next;
    }

    return (p_run); 
}

void show_list(struct node* p_list, char* msg)
{
    int i;
    struct node* p_run = NULL;

    if(msg)
        puts(msg);
    
    printf("[START]-");
    p_run = p_list->next;
    while(p_run != NULL)
    {
        printf("<->[%d]", p_run->data);
        p_run = p_run->next;
    }
    printf("-[END]\n");
}

void destroy_list(struct node* p_list)
{
    struct node* p_run_next = NULL;
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        p_run_next = p_run->next;
        free(p_run);
        p_run = p_run_next;
    }
    free(p_list);
    p_list = NULL;
}

void test_suite(void)
{
    int ret, i;
    struct node* p_list_1 = NULL;
    
    //Creating new List for Test
    p_list_1 = create_list();

    //Test - Insert At Start
    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_start(p_list_1, (i+1)*100);
        assert(ret == SUCCESS);
    }
    show_list(p_list_1, "Showing list p_list_1");

    ret = insert_at_start(p_list_1, 1000);
    assert(ret == SUCCESS);
    
    //Test - Insert At End
    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_list_1, (i + 1)* 500);
        assert(ret == SUCCESS);
    }
    show_list(p_list_1, "Showing After insert at end");

    ret = insert_after_data(p_list_1, 100, 999);
    assert(ret == SUCCESS);

    show_list(p_list_1, "Showing Insert_after_Data 100 -> 999");

    ret = insert_before_data(p_list_1, 1500, 88);
    assert(ret == SUCCESS);
    
    show_list(p_list_1, "Showing Insert_before_Data 1500 -> 88");

    int start_data, end_data;
    
    ret = get_start(p_list_1, &start_data);
    assert(ret == SUCCESS);
    printf("Start Data = %d\n", start_data);

    ret = get_end(p_list_1, &end_data);
    assert(ret == SUCCESS);
    printf("End Data = %d\n", end_data);

    ret = pop_start(p_list_1, &start_data);
    assert(ret == SUCCESS);
    printf("Pop Start Data: %d\n", start_data);
    show_list(p_list_1, "After Pop Start Data:");

    ret = pop_end(p_list_1, &end_data);
    assert(ret == SUCCESS);
    printf("PoP End Data= %d\n", end_data);
    show_list(p_list_1, "After Pop end Data:");

    ret = remove_start(p_list_1);
    assert(ret ==SUCCESS);
    show_list(p_list_1, "After Remove Start");

    ret = remove_end(p_list_1);
    assert(ret == SUCCESS);
    show_list(p_list_1, "After Remove End");

    ret = remove_data(p_list_1, 88);
    assert(ret == SUCCESS);
    show_list(p_list_1, "After Remove Data");
    
    destroy_list(p_list_1);
}

 
int get_length(struct node* p_list)
{
    struct node* p_run = NULL;
    int i = 0;

    p_run = p_list;
    while(p_run->next != NULL)
    {
        i++;
        p_run = p_run->next;
    }

    return (i);

}

int is_list_empty(struct node* p_list)
{
    return (p_list->prev == NULL && p_list->next == NULL);
}

int find_data(struct node* p_list, int f_data)
{
    struct node* p_run = NULL;

    p_run = p_list->next;
    while(p_run != NULL)
    {
        if(p_run->data == f_data)
            return(1);
        p_run = p_run->next;
    }
    return(0);
}

void test_suite_2(void)
{
    struct node* p_list_1;
    p_list_1 = create_list();
    int length, ret, i;

    show_list(p_list_1, "Show list before filling list");
    length = get_length(p_list_1);
    printf("List Length = %d\n", length);

    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_list_1, (i+1) * 100);
        assert(ret == SUCCESS);
    }

    show_list(p_list_1, "Show list After filling list");
   
    length = get_length(p_list_1);
    printf("List Length = %d\n", length);


    ret = is_list_empty(p_list_1);
    printf("ret = %d\n", ret);

    ret = find_data(p_list_1, 200);
    if(ret == 1)
        puts("Data is available");
    else
        puts("Data is not available");
    
    destroy_list(p_list_1);
    p_list_1 = NULL;

}

int concat_lists(struct node* p_list_1, struct node* p_list_2, struct node** pp_concat_list)
{
    struct node* p_concat_list = NULL;
    struct node* p_run = NULL;
    int ret;

    p_concat_list = create_list();

    p_run = p_list_1->next;
    while (p_run != NULL)
    {
        ret = insert_at_end(p_concat_list, p_run->data);
        assert(ret == SUCCESS);
        p_run = p_run->next;
    }

    p_run = p_list_2->next;
    while (p_run != NULL)
    {
        ret = insert_at_end(p_concat_list, p_run->data);
        assert(ret == SUCCESS);
        p_run = p_run->next;
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

    return(SUCCESS);
}


int merge_lists(struct node* p_list_1, struct node* p_list_2, struct node** pp_merged_list)
{
    struct node* p_merged_list = NULL;
    struct node* p_run_1= NULL;
    struct node* p_run_2 = NULL;
    int ret;
    
    p_merged_list = create_list();
    
    p_run_1= p_list_1->next;
    p_run_2 = p_list_2->next;
    
    while(1)
    {
        if(p_run_1 == NULL)
        {
            while(p_run_2 != NULL)
            {
                ret = insert_at_end(p_merged_list, p_run_2->data);
                assert(ret == SUCCESS);
                p_run_2 = p_run_2->next;
            }

            break;
        }

        if(p_run_2 == NULL)
        {
            while(p_run_1 != NULL)
            {
                ret = insert_at_end(p_merged_list, p_run_1->data);
                assert(ret == SUCCESS);
                p_run_1 = p_run_1->next;
            }
            break;
        }

        int data;
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

        ret = insert_at_end(p_merged_list, data);
        assert(ret == SUCCESS);
    }

    *pp_merged_list = p_merged_list;

    return (SUCCESS);

}

void test_suite_3(void)
{
    struct node* p_list_1 = NULL;
    struct node* p_list_2 = NULL;

    struct node* p_list_3 = NULL;
    struct node* p_list_4 = NULL;
    int i, ret;
    unsigned long long int num;
    unsigned long long int num_2;

    p_list_1 = create_list();
    p_list_2 = create_list();

    for(i = 0; i < 5; ++i)
    {
    
        ret = insert_at_end(p_list_1, (i + 1) * 100 );
        assert(ret == SUCCESS);
        ret = insert_at_end(p_list_2, (i + 2) * 10);
        assert(ret == SUCCESS);
    }
   
    show_list(p_list_1, "Original p_list_1");
    show_list(p_list_2, "Original p_list_2");

    struct node* p_concat_list = NULL;

    p_concat_list = create_list();
    
    puts("Starting Concatinating the lists");
    puts("\n");
    
    ret = concat_lists(p_list_1, p_list_2, &p_concat_list);
    assert(ret == SUCCESS);

    show_list(p_concat_list, "Showing Concatenated List:");
    puts("\n");

    puts("Starting Appending the lists");
    ret = append_list(p_list_1, p_list_2);
    assert(ret == SUCCESS);
    show_list(p_list_1, "Showing Appended List:");

    destroy_list(p_list_1);

    puts("Starting Merging list");
    puts("\n");

    p_list_3 = create_list();
    p_list_4 = create_list();
    struct node* p_merged_list = NULL;

    puts("creating new lists");

    for(i = 0; i < 5; ++i)
    {
        ret = insert_at_end(p_list_3, ( i+1 ) * 60);
        assert(ret == SUCCESS);
        num_2 = rand();
        ret = insert_at_end(p_list_4, (i + 2 * 60));
        assert(ret == SUCCESS);
    }

    show_list(p_list_3, "Showing Original list 1 before Merging the Lists:");
    show_list(p_list_4, "Showing Original list 2 before Merging the Lists:");

    ret = merge_lists(p_list_3, p_list_4, &p_merged_list);
    assert(ret == SUCCESS);
    show_list(p_merged_list, "Showing Merged List:");

    destroy_list(p_list_3);
    destroy_list(p_list_4);
    destroy_list(p_merged_list);
    
    p_list_3=NULL;
    p_list_4=NULL;
    p_merged_list = NULL;
}

void test_suite_4(void)
{
    int* p_arr = NULL;
    struct node* p_list = NULL;
    int size = 0;
    int ret , i;

    p_list = create_list();
    for(i = 0; i < 10; ++i)
    {
        ret = insert_at_end(p_list, (i+1)*2);
        assert(ret == SUCCESS);
    }
    show_list(p_list, "Showing Original List");

    to_array(p_list, &p_arr, &size);
    for(i = 0; i < size; ++i)
        printf("p_arr[%d] = %d\n", i, p_arr[i]);

    destroy_list(p_list);
    p_list = NULL;
    free(p_arr);
    p_arr= NULL;
}

/*
int to_list(int* p_arr, int N, struct node** pp_list); 

int get_reversed_list(struct node* p_list, struct node** pp_reversed_list); 
int reverse_list(struct node* p_list); 
*/

int to_array(struct node* p_list_1, int** pp_arr, int* p_size)
{
    int* p_arr = NULL;
    int count = 0;
    int i;
    struct node* p_run = NULL;

    p_run = p_list_1->next;
    while(p_run != NULL)
    {
        count++;
        p_run = p_run->next;
    }
    
    p_arr = (int*)calloc(count, sizeof(int));
    assert(p_arr != NULL);

    p_run = p_list_1->next;
    for(i = 0; i < count; ++i)
    {
        p_arr[i] = p_run->data;
        p_run = p_run->next;
    }
    *pp_arr = p_arr;
    *p_size = count;

    return(SUCCESS);
}