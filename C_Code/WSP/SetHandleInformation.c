#include <Windows.h> 

VOID TEST(VOID)
{
    extern LPVOID pSD; 

    SECURITY_ATTRIBUTES sa; 
    HANDLE hFileMapping = NULL; 

    sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
    sa.lpSecurityDescriptor = pSD; 
    sa.bInheritHandle = FALSE; 

    // Create a kernel object with customized security descriptor 
    hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, &sa, PAGE_READWRITE, 
                                    0, 1024, "MyFileMapping"); 

    // Set the InheritHandle flag 
    SetHandleInformation(hFileMapping, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);  

    // Turn off InheritHandle flg 
    SetHandleInformation(hFileMapping, HANDLE_FLAG_INHERIT, 0); 

    // Set the PROTECT FROM CLOSE flag 
    SetHandleInformation(hFileMapping, HANDLE_FLAG_PROTECT_FROM_CLOSE, 
                        HANDLE_FLAG_PROTECT_FROM_CLOSE); 

    CloseHandle(hFileMapping); // Raise an exception 


    // Turn off protect from close flag 
    SetHandleInformation(hFileMapping, HANDLE_FLAG_PROTECT_FROM_CLOSE, 0); 
}