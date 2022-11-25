#include "header.h"

int main(void)
{
   test_suite_1();
   //test_suite_2();
   //test_suite_3();

   exit(EXIT_SUCCESS);
}              


void test_suite_3()
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



void test_suite_2(void)
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

    ret = concat_list(p_list_1, p_list_2, &p_concat_list);
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


    ret = merge_list(p_merge_list_input, p_merge_list_input_2, &p_merged_list);
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
    
    ret = to_list(p_arr, &nr_of_element, &p_list_tolist);
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

void test_suite_1(void)
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

    ret = insert_before_data(p_list, 20, 300);
    assert(ret == SUCCESS);
    show_list(p_list, "Insert before 20: 300");

    ret = get_start(p_list, &data);
    printf("Start Data: %d\n", data);

    ret = get_end(p_list, &data);
    printf("End data: %d\n", data);

    ret = pop_start(p_list, &data);
    printf("After Pop start: %d\n", data);
    show_list(p_list, "After Pop_Start:");
/*
    ret = pop_end(p_list, &data);
    printf("After Pop End: %d\n", data);
    show_list(p_list, "After Pop_End:");
*/
    ret = remove_start(p_list);
    show_list(p_list, "After Remove Start:\n");

    ret = remove_end(p_list);
    show_list(p_list, "After Remove End:\n");

    ret = remove_data(p_list, 400);
    show_list(p_list, "After Remove data 400:\n");
/*
    ret = is_list_empty(p_list);
    if(ret == LIST_EMPTY)
        puts("List is empty");
    else if(ret == LIST_NOT_EMPTY)  
        puts("List is Not Empty");
    else    
        puts("List is Invalid");
*/
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