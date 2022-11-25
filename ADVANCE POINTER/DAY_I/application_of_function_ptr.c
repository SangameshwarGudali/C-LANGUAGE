void test(void)
{
    const char* lib_path = "cpa.dll"; 
    HMODULE hModule = NULL; 
    int (*pfn_add)(int, int); 
    int rs; 
    hModule = LoadLibrary(lib_path); 

    pfn_add = GetProcAddress(hModule, "cpa_add"); 

    rs = pfn_add(10, 20)
    printf("rs = %d\n", rs); 

    FreeLibrary(hModule); 
    hModule = NULL;
}

#include <dlfcn.h> 

void test(void)
{
    const char* lib_path = "libcpa.so"; 
    void* lib_ptr = NULL; 
    int (*pfn_add)(int, int); 
    int rs; 

    lib_ptr = dlopen(lib_path, RTLD_NOW); 
    pfn_add = dlsym(lib_ptr, "cpa_add"); 
    rs = pfn_add(10, 20); 
    printf("rs = %d\n", rs); 
    dlclose(lib_ptr); 
    lib_ptr = NULL; 
}


