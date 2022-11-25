#include <Windows.h> 

/* 
typedef struct tagCPA_Security_Descriptor
{
    T1 mem1; 

    Tn memn; 
}CPA_SECURITY_DESCRIPTOR; 

CPA_SECURITY_DESCRIPTOR csd; 
*/ 

VOID Test(VOID)
{
    SECURITY_ATTRIBUTES sa; 
    extern LPVOID pSD; 
    sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
    sa.lpSecurityDescriptor = pSD; 
    sa.bInheritHandle = FALSE; 

    HANDLE hFileMapping = NULL; 

    // Create a kernel object with customized security descriptor 
    hFileMapping = CreateFileMapping(INVALID_HANDLE_VALUE, &sa, PAGE_READWRITE, 
                                    0, 1024, "MyFileMapping"); 

    // Gain access to existing kernel object using Open** calls. 
    // While gaining an access to existing kernel object we must specify the 
    // inteded operation that we wish to perfrom on gaining access to kernel object 
    HANDLE hFileMapping_2 = OpenFileMapping(FILE_MAP_READ, FALSE, "MyFileMapping"); 

}

// Inheritable Handle 

VOID TEST_1(VOID)
{
    SECURITY_ATTRIBUTES sa; 
    extern LPVOID pSD; 

    sa.nLength = sizeof(SECURITY_ATTRIBUTES); 
    sa.lpSecurityDescriptor = pSD; 
    sa.bInheritHandle = TRUE; 

    HANDLE hMutex = NULL; 

    hMutex = CreateMutex(&sa, FALSE, NULL); // Let us assume that 5 is the handle 

    // CreateProcessEx(); 
    // BOOL bInheritHandles flag of CreateProcessEx must be TRUE 

    // Parent Process, while creating a new resource can make it inheritable resource 
    // by making bInheritHandle of SECURITY_ATTRIBUTE TRUE 

    // But for child to actually get the benefit of all inheritable handle of its parent 
    // the parent must pass TRUE for bInheritHandle Parameter of CreateProcessEx() function 

    // Also, the child must know the handle positions in its handle table which are 
    // inherited from the parent 

    // Its parent's process responsibility to convey this information to the child 

    // different ways of doing this -> (not exhaustive list)
    // i) Command line arguments (can be programmatically sent in CreateProcessEx())
    // ii) Environmental variable (can be programmatically sent in CreateProcessEx())
    // iii) Some other form interprocess communication such as sending a message on 
    // message queue (in case of GUI application). The parent process can block itself 
    // by calling WaitForInputIdle() API. After the child process initialization is complete 
    // the parent unblocks from the WaitForInputIdle() API and then it can send a message 
    // on childs message queue containing the handle positions it has inherited 

    // This technique works ONLY because the handle is inherited by the child at exactly 
    // same index position where the parent has its handle indexed
}