#include <Windows.h> 
#include <stdio.h> 
#include <assert.h> 

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window"); 
    static TCHAR szWindowTitle[] = TEXT("CPA MSTC 2 - Hello World!"); 

    HBRUSH hBrush = NULL; 
    HCURSOR hCursor = NULL; 
    HICON hIcon = NULL; 
    HICON hIconSm = NULL; 
    HWND hWnd = NULL; 

    WNDCLASSEX wndEx; 
    MSG msg; 

    ZeroMemory(&wndEx, sizeof(WNDCLASSEX)); 
    ZeroMemory(&msg, sizeof(MSG)); 

    hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH); 
    assert(hBrush != NULL); 

    hCursor = LoadCursor(NULL, IDC_ARROW); 
    assert(hCursor != NULL); 

    hIcon = LoadIcon(NULL, IDI_APPLICATION); 
    assert(hIcon != NULL); 

    hIconSm = LoadIcon(NULL, IDI_APPLICATION); 
    assert(hIconSm != NULL); 

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

    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szWindowTitle, WS_OVERLAPPEDWINDOW, 
                            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                            NULL, NULL, hInstance, NULL); 
    assert(hWnd != NULL); 

    ShowWindow(hWnd, nShowCmd); 
    UpdateWindow(hWnd); 

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }

    return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    #define BUFFER_SIZE 32
    static int cxScreen, cyScreen; 
    static char buffer[BUFFER_SIZE]; 

    switch(uMsg)
    {
        case WM_SIZE: 
            cxScreen = LOWORD(lParam); 
            cyScreen = HIWORD(lParam); 
            ZeroMemory(buffer, BUFFER_SIZE); 
            sprintf(buffer, "Width=%d, Height=%d\n", cxScreen, cyScreen); 
            break; 

        case WM_LBUTTONDOWN: 
            MessageBoxA(hWnd, buffer, "Current Size", MB_OK); 
            break; 

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hWnd, uMsg, wParam, lParam)); 
}


/*

*(WORD*)&lParam  = LOWORD(lParam); 
*(WORD*((CHAR*)lParam + 2) = HIWORD(lParam)
*/ 

