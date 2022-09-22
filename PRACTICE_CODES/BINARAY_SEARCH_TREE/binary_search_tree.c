#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
    unsigned long long int nr_of_elements;
};


int insert_at_bst(struct bst* p_bst , int new_key);
struct bst* create_bst(void);
struct bst_node* get_new_key(int new_key);
void show_bst(struct bst* p_bst, char* msg);

int main(void)
{
    int status;
    int i;
    struct bst* p_bst = NULL;

    p_bst = create_bst();
    status = insert_at_bst(p_bst, 100);

    for(i = 0; i < 10; ++i)
    {
        status = insert_at_bst(p_bst, (i+2)*10);
        assert(status == SUCCESS);
    }
    show_bst(p_bst, "After insert bst");

    free(p_bst);
    p_bst = NULL;

    return(p_bst);
}

struct bst* create_bst(void)
{
    struct bst* p_new_bst = NULL;

    p_new_bst = (struct bst*)malloc(sizeof(struct bst));
    if(p_new_bst == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    p_new_bst->p_root_node = NULL;
    p_new_bst->nr_of_elements = 0;

    return(p_new_bst);
}

struct bst_node* get_new_key(int new_key)
{
    struct bst_node* p_new_node = NULL;

    p_new_node = (struct bst_node*)malloc(sizeof(struct bst_node));
    if(p_new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    p_new_node->key = new_key;
    p_new_node->left = NULL;
    p_new_node->right = NULL;
    p_new_node->parent = NULL;

    return(p_new_node);
}

int insert_at_bst(struct bst* p_bst, int new_key)
{
    struct bst_node* p_new_node = NULL;
    struct bst_node* p_run = NULL;

    p_new_node = get_new_key(new_key);
    p_run = p_bst->p_root_node;
    
    if(p_run == NULL)
    {
        p_bst->p_root_node = p_new_node;
        p_bst->nr_of_elements += 1;
        return(SUCCESS);
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
            p_run = p_run->right;
        }
    }
    p_bst->nr_of_elements += 1;
    return(SUCCESS);
    
}

void show_bst(struct bst* p_bst, char* msg)
{
    struct bst_node* p_run = NULL;
    if(msg)
        puts(msg);
    p_run = p_bst->p_root_node;
    printf("[START]->");

    while(1)
    {
        if(p_run->left == NULL)
            break;
        else
        {
            printf("[%d]->", p_run->key);
            p_run = p_run->left;
        }

        if(p_run->right == NULL)
            break;
        else
        {
            printf("[%d]->", p_run->key);
            p_run = p_run->right;   
        }
    }
    printf("[END]\n");
    printf("nr_of_elements = %lld\n", p_bst->nr_of_elements);
}