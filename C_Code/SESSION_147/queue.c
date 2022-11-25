#include "list.h"

typedef list_t queue_t; 

#define QUEUE_EMPTY STACK_EMPTY 

queue_t* create_queue(void); 
status_t insert(queue_t* pQ, data_t new_element); 
status_t peek(queue_t* pQ, data_t* p_peeked_data); 
queue_t delete(queue_t* pQ, data_t* p_deleted_data); 
bool is_queue_empty(queue_t* pQ); 
status_t destroy_queue(queue_t** ppQ); 
