/* 
    @goal: To implement ADT of singly linked list with 
            (i) Head node approach 
            (ii) Client - Server separation (but in single file)
    
    @author: Yogeshwar 
*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data;           /*  member to store data value */ 
    struct node* next;  /*  member to store the address of next node 
                            a.k.a. forward link */ 
}; 

/*  Declarations of functions which allow us to 
    create, process and destroy singly linked list 
    a.k.a. list interface functions 
    (interface = माध्यम, ज्या माध्यमातून लिस्ट वापरता येईल, अशी functions)
*/ 

struct node* create_list(void); 

int insert_at_start(struct node* p_head_node, int new_data); 

int insert_at_end(struct node* p_head_node, int new_data); 

int insert_after_data(struct node* p_head_node, int e_data, int new_data); 

int insert_before_data(struct node* p_head_node, int e_data, int new_data); 