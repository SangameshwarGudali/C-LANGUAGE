#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SUCCESS 1
#define FAILURE 0

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


struct bst* create_bst(void);
struct bst_node* get_new_key(int new_key);

int insert_at_bst(struct bst* p_bst , int new_key);
//void show_bst(struct bst* p_bst, char* msg);
void preorder(struct bst* p_bst);
void preorder_nodelevel(struct bst_node* p_root_node);
void inorder(struct bst* p_bst);
void inorder_nodelevel(struct bst_node* p_root_node);
void postorder(struct bst* p_bst);
void postorder_nodelevel(struct bst_node* p_root_node);
void bst_destroy(struct bst* p_bst);
void bst_destroy_nodelevel(struct bst_node* p_root);

int bst_search(struct bst* p_bst, int search_key);
struct bst_node* bst_search_nodelevel(struct bst_node* p_root, int search_key);




int main(void)
{
    int status;
    int i;
    int ret;
    struct bst* p_bst = NULL;

    int keys[] = {100, 50, 150, 25, 75, 200, 20, 70, 80, 175, 250, 24};
    int non_keys[] = {-541, -6, -45451, -564964, -164985, -1168489};
    p_bst = create_bst();

    for(i = 0; i < sizeof(keys)/sizeof(int); ++i)
    {
        assert(insert_at_bst(p_bst, keys[i] ) == SUCCESS);
    }

    puts("Test case for existing key element in keys[]");
    for(i = 0; i < sizeof(keys)/sizeof(int); ++i)
    {
        ret = bst_search(p_bst, keys[i]);
        if(ret == SUCCESS)        
            printf("%d is avilable in BTree as keys[%d]\n", i, keys[i]);
        else
        {
            printf("%d is NOT avilable in BTree as keys[%d]\n", i, keys[i]);
            puts("something went wrong");
            bst_destroy(p_bst);
            p_bst = NULL;
            exit(EXIT_FAILURE);
        }
    }

    puts("Test case for NON existing key element in keys[]");
    for(i = 0; i < sizeof(non_keys)/sizeof(int); ++i)
    {
        ret = bst_search(p_bst, non_keys[i]);
        if(ret == SUCCESS)        
            printf("%d is NOT avilable in BTree as keys[%d]\n", i, non_keys[i]);
        else
        {
            printf("%d is avilable in BTree as keys[%d]\n", i, non_keys[i]);
            puts("something went wrong");
            bst_destroy(p_bst);
            p_bst = NULL;
            exit(EXIT_FAILURE);
        }
    }

    preorder(p_bst);
    inorder(p_bst);
    postorder(p_bst);
    bst_destroy(p_bst);

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

void preorder(struct bst* p_bst)
{
    puts("Preorder");
    printf("[START]<->");
    preorder_nodelevel(p_bst->p_root_node);
    printf("[END]\n");
}

void preorder_nodelevel(struct bst_node* p_root_node)
{
    if(p_root_node != NULL)
    {
        printf("[%d]<->", p_root_node->key);
        preorder_nodelevel(p_root_node->left);
        preorder_nodelevel(p_root_node->right);
    }

}

void inorder(struct bst* p_bst)
{
    puts("Inorder");
    printf("[START]<->");
    inorder_nodelevel(p_bst->p_root_node);
    printf("[END]\n");
}

void inorder_nodelevel(struct bst_node* p_root_node)
{
    if(p_root_node != NULL)
    {
        inorder_nodelevel(p_root_node->left);
        printf("[%d]<->", p_root_node->key);
        inorder_nodelevel(p_root_node->right);
    }
}

void postorder(struct bst* p_bst)
{
    puts("Postorder");
    printf("[START]<->");
    postorder_nodelevel(p_bst->p_root_node);
    printf("[END]\n");
}

void postorder_nodelevel(struct bst_node* p_root_node)
{
    if(p_root_node != NULL)
    {
        postorder_nodelevel(p_root_node->left);
        postorder_nodelevel(p_root_node->right);
        printf("[%d]<->", p_root_node->key);
    }
}

void bst_destroy(struct bst* p_bst)
{
    bst_destroy_nodelevel(p_bst->p_root_node);
}

void bst_destroy_nodelevel(struct bst_node* p_root)
{
    if(p_root != NULL)
    {
        bst_destroy_nodelevel(p_root->left);
        bst_destroy_nodelevel(p_root->right);
        free(p_root);
    }
}

int bst_serach(struct bst* p_bst, int search_key)
{
    int ret;
    ret = (bst_search_nodelevel(p_bst->p_root_node, search_key)!= NULL);
    if(ret == SUCCESS);
        return(SUCCESS);
    retuern(FAILURE);
}

struct bst_node* bst_search_nodelevel(struct bst_node* p_root, int search_key)
{
    struct bst_node* p_run =  NULL;

    p_run = p_root;
    while(p_run != NULL)
    {
        if(p_run == p_root)
            break;
        else if(p_run <= p_root)
            p_run = p_run->left;
        else
            p_run = p_run->right;
    }
    return(p_run);
}