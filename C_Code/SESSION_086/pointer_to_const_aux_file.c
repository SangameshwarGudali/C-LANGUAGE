
struct Date {int dd; int mm; int yy}; 

char make_lower(char c); 
int is_even(int n); 
float make_square(float f); 

void make_lower_1(char* p); 
void is_even_1(int* p); 
void make_square_1(float* fp); 

void show_date(const struct Date* p_date); 

int main(void)
{
    char c='A'; 
    int n=10; 
    float f=3.14f; 



    char upper_c = make_lower(c); 
    int ans = is_even(n); 
    float sqr_of_f = make_square(f); 

    struct Date cpa_birth_date = {1, 10, 2009}; 
    show_date(&cpa_birth_date); 

}
