#include "list.h"

typedef list_t stack_t; 

#define STACK_EMPTY LIST_EMPTY 

stack_t* create_stack(void); 
status_t push(stack_t* p_stack, data_t new_element); 
status_t top(stack_t* p_stack, data_t* p_new_element); 
bool is_stack_empty(stack_t* p_stack); 
status_t destroy_stack(stack_t** pp_stack); 

int main(void)
{

}

stack_t* create_stack(void)
{
    return create_list(); 
}

status_t push(stack_t* p_stack, data_t new_element)
{
    return insert_end(p_stack, new_element); 
}

status_t top(stack_t* p_stack, data_t* p_top_element)
{
    return get_end(p_stack, p_top_element)
}

status_t pop(stack_t* p_stack, data_t* p_poped_element)
{
    return pop_end(p_stack, p_poped_element)
}

bool is_stack_empty(stack_t* p_stack)
{
    return is_list_empty(p_stack); 
}

status_t destroy_stack(stack_t** pp_stack)
{
    return destroy_list(pp_stack); 
}

