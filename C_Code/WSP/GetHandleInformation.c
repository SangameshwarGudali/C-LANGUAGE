#include <Windows.h> 

VOID TEST(VOID)
{
    HANDLE hFileMapping = NULL; 
    SECURITY_ATTRIBUTES sa; 
    extern LPVOID pSD; 

    sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
    sa.lpSecurityDescriptor = pSD; 
    sa.bInheritHandle = TRUE; 

    hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, &sa, PAGE_READWRITE, 
                                    0, 1024, "MyFileMapping"); 

    DWORD dwFlags; 

    GetHandleInformation(hFileMapping, &dwFlags); 

    BOOL bIsHandleInheritable, bIsHandleProtectedFromClose; 

    bIsHandleInheritable = (0 != (dwFlags & HANDLE_FLAG_INHERIT)); 
    bIsHandleProtectedFromClose = (0 != (dwFlags & HANDLE_FLAG_PROTECT_FROM_CLOSE)); 
}