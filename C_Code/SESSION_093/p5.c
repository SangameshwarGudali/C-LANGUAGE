int main(void)
{
       
       /* MY PRACTICE CODE 
        int (*(*(*pfn)(void))[5])(int, int); 

        int (*(*ptr)[5])(int, int);

        int (*arr[5])(int, int);

        int arr[0](int, int);

        int function(int ,int )
*/

        int (*(*p)[5])(int, int); 
        int i; 
        int ret; 

        pfn = get_function_ptr_arr; 
        p = pfn(); 
        for(i = 0; i < 5; ++i)
            (*p)[i](n1, n2); 

}

struct node
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 


