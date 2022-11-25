struct student
{
    int st_id; 
    char st_name[32]; 
    char st_addr[128]; 

    float st_marks; 
    float st_attnd;
}; 

// Preferred option
struct node
{
    struct student* p_student; 
    struct node* prev; 
    struct node* next; 
}; 

struct node
{
    struct student s; // not so desirable (keep poitner as show above)
    struct node* prev; 
    struct node* next; 
};  