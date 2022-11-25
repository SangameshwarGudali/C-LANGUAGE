void callee_1(char* p); 
void callee_2(char** pp); 

void caller_1(void)
{
    char c; 
    callee_1(&c); 
}

void callee_1(char* p)
{
    *p = 'A'; 
}

////////////////////////////////////////////

void caller_2(void)
{
    char* p_str = 0; 
    callee_2(&p_str);
    // use p_str 
    free(p_str); 
    p_str = 0; 

}

void callee_2(char** pp_str)
{
    char* p = 0; 

    p = malloc(16); 
    *pp_str = p; 

}

char** callee_3()
{
    char** p_to_array_of_strings = 0; 
    int i; 

    p_to_array_of_strings = malloc(5 * sizeof(char*)); 
    for(i = 0; i < 5; ++i)
        p_to_array_of_strings[i] = malloc(8 * sizeof(char)); 

    return p_to_array_of_strings; 
}

// OR 

void caller_3()
{
    char** pp_str = 0; 
    int size; 
    int i; 
    callee_3_v2(&pp_str, &size); 

    for(i = 0; i < 5; ++i)
        pp_str[i];  // -> access all strings 

    // release pp_str 
    for(i = 0; i < 5; ++i)
        free(pp_str[i]); 
    free(pp_str); 
    pp_str = 0; 
}

void callee_3_v2(char*** ppp_str, int* p_size)
{
    char** p_to_array_of_strings = 0; 
    int i; 

    p_to_array_of_strings = malloc(5 * sizeof(char*)); 
    for(i = 0; i < 5; ++i)
        p_to_array_of_strings[i] = malloc(8 * sizeof(char)); 

    *ppp_str = p_to_array_of_strings; 
    *p_size = 5; 

}

int split_string(const char* p_str, const char* p_sep, int max_split, 
                    char*** ppp_str, int* p_size); 


int main(void)
{
    const char* p_str = "yogeshwar:x:1000:1000:Yogeshwar Shukla,,,:/home/yogeshwar:/bin/bash"; 
    const char* p_sep = ":"; 
    char** pp_str = 0; 
    int size; 
    int status; 
    int i; 

    status = split_string(p_str, p_sep, -1, &pp_str, &size); 

    for(i = 0; i < size; ++i)
        printf("pp_str[%d]:%s\n", i, pp_str[i]); 

    for(i = 0; i < size; ++i)
        free(pp_str[i]); 

    free(pp_str); 

}

int main(int argc, char* argv[])
{
    int i; 
    for(i = 0; i < argc; ++i)
        argv[i]; 
}

int cpa_join(char** pp_str, char* p_sep, char** pp_str_output, int* p_size)
{

}

int main(void)
{
    char* p[] = {"Core", "Programming", "Academy"}; 
    char* p_sep="##"; 
    char* p_output = 0; 
    int size; 

    join(p, p_sep, &p_output, &size); 

}