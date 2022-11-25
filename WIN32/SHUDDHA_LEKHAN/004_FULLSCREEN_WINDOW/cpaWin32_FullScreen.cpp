#include <Windows.h> 

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

#define VK_F    0x46 

#define EXIT_IF(cond, lpszMsg, lpszCaption)     do\
                                                {\
                                                    if((cond))\
                                                    {\
                                                        MessageBox((HWND)NULL,\
                                                                    TEXT(lpszMsg),\
                                                                    TEXT(lpszCaption),\
                                                                    MB_ICONERROR);\
                                                        ExitProcess(EXIT_FAILURE);\
                                                    }\
                                                }while(0) 


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

/* Global variables */ 
HWND ghWnd = NULL; 
BOOL gbFullScreen = FALSE; 
DWORD dwWindowStyle; 

WINDOWPLACEMENT gpPreviousWindowPlacement; 

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) 
{
    static TCHAR szAppName[] = TEXT("FullScreen"); 
    static TCHAR szWindowClassName[] = TEXT("The Standard GDI Window"); 

    HBRUSH hBrush = NULL; 
    HCURSOR hCursor = NULL; 
    HICON hIcon = NULL; 
    HICON hIconSm = NULL; 
    HWND hWnd = NULL; 

    ATOM bClassRegistrationStatus = 0; 

    WNDCLASSEX wnd; 
    MSG msg; 

    ZeroMemory((void*)&wnd, sizeof(WNDCLASSEX)); 
    ZeroMemory((void*)&msg, sizeof(MSG)); 

    hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    EXIT_IF(hBrush == NULL, "Error in loading brush", "GetStockObject"); 

    hCursor = LoadCursor((HINSTANCE)NULL, IDC_ARROW); 
    EXIT_IF(hCursor == NULL, "Error in Loading cursor", "LoadCursor"); 

    hIcon = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION); 
    EXIT_IF(hIcon == NULL, "Error in loading icon", "LoadIcon"); 

    hIconSm = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION); 
    EXIT_IF(hIconSm == NULL, "Error in loading icon", "LoadIcon"); 

    wnd.cbSize = sizeof(WNDCLASSEX); 
    wnd.cbClsExtra = 0; 
    wnd.cbWndExtra = 0; 
    wnd.hbrBackground = hBrush; 
    wnd.hCursor = hCursor; 
    wnd.hIcon = hIcon; 
    wnd.hInstance = hInstance; 
    wnd.hIconSm = hIconSm; 
    wnd.lpfnWndProc = WndProc; 
    wnd.lpszClassName = szWindowClassName; 
    wnd.lpszMenuName = NULL; 
    wnd.style = CS_HREDRAW | CS_VREDRAW; 

    bClassRegistrationStatus = RegisterClassEx(&wnd); 
    EXIT_IF(bClassRegistrationStatus == 0, "Failed to register a window class",
            "RegisterClassEx"); 
    
    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szWindowClassName, szAppName, WS_OVERLAPPEDWINDOW, 
                            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                            (HWND)NULL, (HMENU)NULL, hInstance, NULL); 
    EXIT_IF(hWnd == NULL, "Failed to create a window in memory", "CreateWindowEx"); 

    ShowWindow(hWnd, nShowCmd); 
    UpdateWindow(hWnd); 

    ghWnd = hWnd; 

    while(GetMessage(&msg, (HWND)NULL, 0U, 0U))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }

    return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    void ToggleFullScreen(void); 
    switch(uMsg)
    {
        case WM_KEYDOWN: 
            switch(wParam)
            {
                case VK_ESCAPE: 
                    DestroyWindow(hWnd); 
                    break; 

                case VK_F: 
                    if(gbFullScreen == FALSE)
                    {
                        ToggleFullScreen(); 
                        gbFullScreen = TRUE; 
                    }
                    else 
                    {
                        ToggleFullScreen(); 
                        gbFullScreen = FALSE; 
                    }
                    break; 
            }
            break; 

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hWnd, uMsg, wParam, lParam)); 
}

void ToggleFullScreen(void)
{
    MONITORINFO mi; 
    HMONITOR hMonitor; 
    BOOL bVar; 

    if(gbFullScreen == FALSE)
    {
        dwWindowStyle = GetWindowLong(ghWnd, GWL_STYLE); 
        if(dwWindowStyle & WS_OVERLAPPEDWINDOW)
        { 
            gpPreviousWindowPlacement.length = sizeof(WINDOWPLACEMENT); 
            bVar = GetWindowPlacement(ghWnd, &gpPreviousWindowPlacement); 
            mi.cbSize = sizeof(MONITORINFO); 
            hMonitor = MonitorFromWindow(ghWnd, MONITORINFOF_PRIMARY); 
            GetMonitorInfo(hMonitor, &mi); 
            if(bVar && hMonitor) 
            {
                SetWindowLong(ghWnd, GWL_STYLE, dwWindowStyle & ~WS_OVERLAPPEDWINDOW); 
                SetWindowPos(ghWnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, 
                                mi.rcMonitor.right - mi.rcMonitor.left, mi.rcMonitor.bottom - mi.rcMonitor.top, 
                                SWP_NOZORDER | SWP_FRAMECHANGED); 
            }
        }
        ShowCursor(FALSE); 
    }
    else
    {
        SetWindowLong(ghWnd, GWL_STYLE, dwWindowStyle & WS_OVERLAPPEDWINDOW); 
        gpPreviousWindowPlacement.length = sizeof(WINDOWPLACEMENT); 
        SetWindowPlacement(ghWnd, &gpPreviousWindowPlacement); 
        SetWindowPos(ghWnd, HWND_TOP, 0, 0, 0, 0, 
                        SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED); 
        ShowCursor(TRUE); 
    }
}
