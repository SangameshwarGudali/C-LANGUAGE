#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "test_suit.h"


#define    SUCCESS             1
#define    LIST_EMPTY          2
#define    LIST_NOT_EMPTY      3
#define    LIST_DATA_FOUND     4 
#define    LIST_DATA_NOT_FOUND 5 


struct node
{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* create_list(void);
struct node* get_new_node(int new_data);

int insert_at_start(struct node* p_list, int new_data);
int insert_at_end(struct node* p_list, int new_data);

int get_start(struct node* p_list, int* get_data);
int get_end(struct node* p_list, int* get_e);

int remove_start(struct node* p_list);
int remove_end(struct node* p_list);

int pop_start(struct node* p_list, int* pop_start_data);
int pop_end(struct node* p_list, int* pop_data);

int insert_after_data(struct node* p_list, int ext_data, int new_data);
int insert_before_data(struct node* p_list, int ext_data,int new_data);

int merge_list(struct node* p_list_1, struct node* p_list_2, struct node** pp_merged_list);

int append_list(struct node* p_list_1, struct node* p_list_2);

int concat_list(struct node* p_list_1, struct node* p_list_2, struct node** pp_concat_list);

int to_array(struct node* p_list_1, int** pp_arr, int* p_arr_size);
int to_list(int* p_arr, int* p_arr_size, struct node** pp_list);

int get_length(struct node* p_list);
struct node* search_data(struct node* p_list, int search_data);

int remove_data(struct node* p_list, int r_data);

void show_list(struct node* p_list, char* msg);
void destroy_list(struct node* p_list);

int get_reversed_list(struct node* p_list, struct node** p_rev_list);
int find_data(struct node* p_list, int f_data);

#endif