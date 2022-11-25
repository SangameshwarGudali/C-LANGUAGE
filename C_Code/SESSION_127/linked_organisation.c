#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct node 
{
    int data; 
    struct node* next; 
}; 

int main(void)
{
    /*  p_start_node is dedicated to store the address of  the 
        first node 
    */ 
    int choice; 
    int num; 
    struct node* p_start_node = NULL; 
    struct node* p_run = NULL; 
    struct node* tmp_next = NULL; 

    while(1)
    {
        printf("Do you further want to add a number?[Yes->1|No->Otherwise]:"); 
        scanf("%d", &choice); 

        if(choice != 1)
            break; 

        printf("Enter a number:"); 
        scanf("%d", &num); 

        if(p_start_node == NULL)
        {
            p_start_node = (struct node*)malloc(sizeof(struct node)); 
            assert(p_start_node != NULL); 
            p_start_node->data = num; 
            p_start_node->next = NULL; 
            continue; 
        }

        p_run = p_start_node; 
        while(p_run->next != NULL)
        {
            p_run = p_run->next; 
        }

        p_run->next = (struct node*)malloc(sizeof(struct node)); 
        assert(p_run->next != NULL); 

        p_run->next->data = num; 
        p_run->next->next = NULL; 
    }

    p_run = p_start_node; 
    while(p_run != NULL)
    {
        printf("Address(p_run)=%llu\tp_run->data = %d\n", 
                (unsigned long long int)p_run, p_run->data); 
        p_run = p_run->next; 
    }    

    p_run = p_start_node; 
    while(p_run != NULL)
    {
        tmp_next = p_run->next; 
        printf("freeing node at address=%llu\n", (unsigned long long int)p_run); 
        free(p_run);  
        p_run = tmp_next; 
    }    
    p_start_node = NULL; 
    
    return (0); 
}

/* 
p_start_node == NULL

Let us add first integer 

p_start_node == 10k 
10K
[100|NULL]

Let us add second integer 
p_start_node == 10k 

10k             20k 
[100|20K]      [200|NULL]

Let us add third integer 

p_start_node == 10K 

10K         20K         30K 
[100|20K]   [200|30K]   [300|NULL]

struct node 
{
    int data;           // offset of data = 0 
    struct node* next;  // offset of next = 8
} 

10K 
[100|20K]

M[10000:10003] == 100 
M[10008:10015] == 20K 

Let p be a pointer. Pointer variable spans from M[2000:2007]
Let us store the address of the first node in p. 

M[2000:2007] <- 10K 

p = p->next; 

Evaluate p->next 

p->next == (*p).next 
        == CONTENT(address in p + offset of (next))
        == CONTENT(address in M[2000:2007] + offset of(next))
        == CONTENT(10K + 8)
        == CONTENT(10008)   How many bytes to access after 10008? 
                            Ans: 8 bytes? why? Because next field is 
                            a pointer whose size is 8 bytes. 
        == CONTENT(10008:10015)
        == 20K

p = 20K 
M[2000:2007] <- 20K

*/ 

/* 

p_run = p_start_node; 
while(p_run != NULL)
{
    //  do something on p_run that does not 
    //  involve modificaiton of link
    //  Whatever you do, will be done on all! 
    p_run = p_run->next; 
}

*/ 