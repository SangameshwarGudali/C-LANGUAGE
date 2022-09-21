/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define SUCCESS 1
struct ListNode* get_new_node(int new_data);
int insert_at_end(struct ListNode* p_list, int new_data);


struct ListNode* create_list(void)
{
    struct ListNode* p_new_list = NULL;
    p_new_list = get_new_node(-1);
    return(p_new_list);
}

struct ListNode* get_new_node(int new_data)
{
    int status;
    struct ListNode* p_new_node = NULL;
    
    p_new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    assert(p_new_node != NULL);
    
    p_new_node->val = new_data;
    p_new_node->next = NULL;
    
    return(p_new_node);
}

int insert_at_end(struct ListNode* p_list, int new_data)
{
    struct ListNode* p_last_node = NULL; 
    struct ListNode* p_new_node = NULL; 

    p_last_node = p_list; 
    while(p_last_node->next != NULL)
        p_last_node = p_last_node->next; 
    p_new_node = get_new_node(new_data); 
    p_last_node->next = p_new_node; 
    p_new_node->next = NULL; 

    return (SUCCESS); 
}



struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    int status;
    int data = 0;
    struct ListNode* p_run1 = NULL;
    struct ListNode* p_run2 = NULL;
    struct ListNode* p_merged_list = NULL;
    
    p_merged_list = create_list();
    
    p_run1 = list1;
    p_run2 = list2;
    
    while(1)
    {
        if(p_run1 == NULL)
        {
            while(p_run2 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run2->val);
                assert(status == SUCCESS);
                p_run2 = p_run2->next;
            }
            break;
        }
        
        if(p_run2 == NULL)
        {
            while(p_run1 != NULL)
            {
                status = insert_at_end(p_merged_list, p_run1->val); 
                assert(status == SUCCESS); 
                p_run1 = p_run1->next; 
            }
            break;
        }
         if(p_run1->val <= p_run2->val)
        {
            data = p_run1->val; 
            p_run1 = p_run1->next;
        }
        else
        {
            data = p_run2->val; 
            p_run2 = p_run2->next; 
        }
        status = insert_at_end(p_merged_list, data);
        assert(status == SUCCESS);
    }
    
    return(p_merged_list->next);
}