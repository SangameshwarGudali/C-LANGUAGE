int (*(*(*(*(*(*(*p1)[3])[4])(int(*)[3]))(int))[4])(int))[3]; 
int (*(*(*(*(*p2)(int))[4])(float, float))[3])(int); 
int (*(*(*p3)[4])(int, int))[5]; 
void (*signal(int, void (*)(int)))(int); 

int main(void)
{
    puts("Complicated declarations validated"); 
    return (0); 
}
