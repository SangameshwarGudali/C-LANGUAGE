#include <Windows.h> 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pszCmdLine, int nShowCmd) 
{
    HANDLE hMutex = NULL; 

    // We could have used any kernel object instead of Mutex which can be named 
    hMutex = CreateMutex(NULL, FALSE, "{FA531CC1-0497-11d3-A180-00105A276C3E}"); 
    if(hMutex == NULL)
    {
        if(GetLastError() == ERROR_ALREADY_EXISTS)
        {
            // One instance of this application is already running 
            return 0; 
        }
    }

    // The first instance of application is running 


    // Close the mutex handle 
    CloseHandle(hMutex); 
    hMutex = NULL; 

    return 0; 
}