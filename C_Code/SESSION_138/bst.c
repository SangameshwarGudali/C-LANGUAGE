#include <stdio.h> 
#include <stdlib.h> 

#define SUCCESS 1 

struct bst_node
{
    int key; 
    struct bst_node* left; 
    struct bst_node* right; 
    struct bst_node* parent; 
}; 

struct bst 
{
    struct bst_node* p_root_node; 
    unsigned long long int nr_elements; 
}; 

struct bst* bst_create(void); 
int bst_insert(struct bst* p_bst, int new_key); 

struct bst_node* get_bst_node(int key); 

/* Client that uses BST */ 
int main(void)
{
    struct bst* p_bst = NULL; 

    p_bst = bst_create(); 

    return (0); 
}

/* Implementation of server routines */ 

struct bst* bst_create(void)
{
    struct bst* p_bst = NULL; 

    p_bst = (struct bst*)malloc(sizeof(struct bst)); 
    if(NULL == p_bst)
    {
        printf("Memory allocation failed\n"); 
        exit(EXIT_FAILURE); 
    }

    p_bst->p_root_node = NULL; 
    p_bst->nr_elements = 0; 

    return (p_bst); 
}

int bst_insert(struct bst* p_bst, int new_key)
{
    struct bst_node* p_new_node = NULL; 
    struct bst_node* p_run = NULL; 

    p_new_node = get_bst_node(new_key); 
    p_run = p_bst->p_root_node; 
    if(p_run == NULL)
    {
        p_bst->p_root_node = p_new_node; 
        p_bst->nr_elements += 1; 
        return (SUCCESS); 
    }

    while(1)
    {
        if(new_key <= p_run->key)
        {
            if(p_run->left == NULL)
            {
                p_run->left = p_new_node; 
                p_new_node->parent = p_run; 
                break; 
            }
            else 
                p_run = p_run->left; 
        }
        else 
        {
            if(p_run->right == NULL)
            {
                p_run->right = p_new_node; 
                p_new_node->parent = p_run; 
                break; 
            }
            else 
                p_run = p_run->right; 
        }
    }
    
    p_bst->nr_elements += 1; 
    return (SUCCESS); 
}

struct bst_node* get_bst_node(int key)
{
    struct bst_node* p_new_bst_node = NULL; 

    p_new_bst_node = (struct bst_node*)malloc(sizeof(struct bst_node)); 
    if(p_new_bst_node == NULL)
    {
        printf("Memory allocation failed\n"); 
        exit(EXIT_FAILURE); 
    }

    p_new_bst_node->key = key; 
    p_new_bst_node->left = NULL; 
    p_new_bst_node->right = NULL; 
    p_new_bst_node->parent = NULL; 

    return (p_new_bst_node); 
}