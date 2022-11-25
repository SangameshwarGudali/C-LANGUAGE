#include <Windows.h> 
#include <assert.h> 

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib") 
#pragma comment(lib, "user32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window"); 
    static TCHAR szWindowName[] = TEXT("HelloWin!");    

    HWND hWnd = NULL; 
    HBRUSH hBrush = NULL; 
    HCURSOR hCursor = NULL; 
    HICON hIcon = NULL; 
    HICON hIconSm = NULL; 

    WNDCLASSEX wndEx; 
    MSG msg; 

    ZeroMemory(&wndEx, sizeof(WNDCLASSEX)); 
    ZeroMemory(&msg, sizeof(MSG)); 

    hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    assert(hBrush); 

    hCursor = LoadCursor(NULL, IDC_ARROW); 
    assert(hCursor); 
 
    hIcon = LoadIcon(NULL, IDI_APPLICATION); 
    assert(hIcon); 

    hIconSm = LoadIcon(NULL, IDI_APPLICATION); 
    assert(hIconSm); 

    wndEx.cbSize = sizeof(WNDCLASSEX); 
    wndEx.cbClsExtra = 0; 
    wndEx.cbWndExtra = 0; 
    wndEx.hbrBackground = hBrush; 
    wndEx.hCursor = hCursor; 
    wndEx.hIcon = hIcon; 
    wndEx.hIconSm = hIconSm; 
    wndEx.hInstance = hInstance; 
    wndEx.lpfnWndProc = WndProc; 
    wndEx.lpszClassName = szClassName; 
    wndEx.lpszMenuName = NULL; 
    wndEx.style = CS_HREDRAW | CS_VREDRAW; 

    ATOM bRet = RegisterClassEx(&wndEx); 
    assert(bRet); 
    
    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szWindowName, 
                            WS_OVERLAPPED | WS_THICKFRAME | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, 
                            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                            NULL, NULL, hInstance, NULL); 
    assert(hWnd != NULL); 

    ShowWindow(hWnd, nShowCmd); 
    UpdateWindow(hWnd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
        // -> Operating. wndEx.lpfnWndProc(lpMsg->hWnd, lpMsg->uMsg, lpMsg->wParam, lpMsg->lParam); 
    }

    return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // When control flow is here, then you can be sure that 
    //      1.some event occurred on one of the windows whose handle is hWnd (1st param)
    //      of the current thread
    //      2. The type of the event / event code is present in uMsg 
    //      3. event type / message type specific data is present in wParam & lParam 
    //      You should write WndProc under above assumption 
    switch(uMsg)
    {
        case WM_DESTROY: 
            PostQuitMessage(0); 
            break; 
    }

    return (DefWindowProc(hWnd, uMsg, wParam, lParam)); 
}


// click on close button/select close from sys menu / 
// press alt+F4 when app window is on the foreground 
//  -> results into posting WM_DESTROY message on msg queue 

// When WM_DESTROY is dispatched (i.e. WndProc is called with 
//  uMsg == WM_DESTROY) then we execute PostQuitMessage(status)
//  and this API posts WM_QUIT message on message queue 
//  the message that is posted on message queue by 
//  PostQuitMessage and uMsg == WM_QUIT 
//  wParam == status 

//  and when GetMessage receive msg with uMsg == WM_QUIT 
//  then it returns 0 and thus application comes out 
//  of message loop 

//  WinMain must return now with the exist status 
//  exit status is present in msg.wParam (remember that 
//  exit status is first given PostQuitMessage which gives it 
//  to wParam member of MSG structure that is posted on queue)
//  therefore, after getting out of while loop msg.wParam 
//  allows us to access exit status given by application 
// programmer to PostQuitMessage() function 
