#include <Windows.h> 
#include <stdio.h>
#include <assert.h> 
#include <wingdi.h>

#define _text TEXT

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("SHIV-SAN");
    static TCHAR szWindowName[] = TEXT("MAIN WINDOW");
    
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
    assert(hBrush); 

    hCursor = LoadCursor((HINSTANCE)NULL, IDC_ARROW); 
    assert(hCursor); 

    hIcon = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION); 
    assert(hIcon); 

    hIconSm = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION); 
    assert(hIconSm); 

    wndEx.cbSize = sizeof(WNDCLASSEX); 
    wndEx.cbClsExtra = 0; 
    wndEx.cbWndExtra = 0; 
    wndEx.hbrBackground = hBrush; 
    wndEx.hCursor = hCursor; 
    wndEx.hIcon = hIcon; 
    wndEx.hIconSm = hIconSm; 
    wndEx.hInstance = hInstance; 
    wndEx.lpszClassName = szClassName; 
    wndEx.lpszMenuName = (LPCSTR)NULL;
    wndEx.lpfnWndProc = WndProc; 
    wndEx.style = CS_HREDRAW | CS_VREDRAW; 

    ATOM bRet = RegisterClassEx(&wndEx); 
    assert(bRet); 

    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szWindowName, WS_OVERLAPPEDWINDOW, 
                    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                    (HWND)NULL, (HMENU)NULL, hInstance, NULL); 
    assert(hWnd); 
    
    ShowWindow(hWnd, nShowCmd); 
    UpdateWindow(hWnd); 

    while(GetMessage(&msg, (HWND)NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }

    return (msg.wParam); 
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int cxChar, cyChar, cxCaps; 
    static int cxSize, cySize; 

    HDC hdc = NULL; 

    PAINTSTRUCT ps; 
    TEXTMETRIC tm;

    switch(uMsg)
    {
        case WM_CREATE: 
            hdc = GetDC(hWnd); 
            GetTextMetrics(hdc, &tm); 
            cxChar = tm.tmAveCharWidth; 
            cxCaps = (tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar/2; 
            cyChar = tm.tmHeight; 
        
            ReleaseDC(hWnd, hdc); 
            hdc = NULL;            
            break; 

        case WM_SIZE: 
            cxSize = LOWORD(lParam); 
            cySize = HIWORD(lParam); 
            break; 

        case WM_PAINT: 
            hdc = BeginPaint(hWnd, &ps); 
            SetTextAlign(hdc, TA_CENTER); 
            TextOut(hdc, cxSize/2, cySize/2, "Hello,World!", strlen("Hello,World!")); 
            EndPaint(hWnd, &ps); 
            break; 

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hWnd, uMsg, wParam, lParam)); 
}

/*

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    #define BUFFER_SIZE 32

    static int cxScreen , cyScreen;
    static int cxChar, cyChar;
    static char buffer[BUFFER_SIZE];
    static char buffer1[BUFFER_SIZE];
    HDC hdc = NULL;
    PAINTSTRUCT ps;

    TEXTMETRICA tm;
    int Ascent, height;

    switch(uMsg)
    {
        case WM_CREATE:
            hdc = GetDC (hWnd);
            GetTextMetrics (hdc, &tm);
            cxChar = tm.tmAveCharWidth;
            cyChar = tm.tmHeight + tm.tmExternalLeading;
            ZeroMemory(buffer1, BUFFER_SIZE);
            sprintf(buffer1, "tm.tmAveCharWidth = %d,  tmHeight= %d", cxChar, cyChar);
            TextOutA(hdc, cxChar, cyChar, "sizes of the tmAveCharWidth", strlen("sizes of the tmAveCharWidth"));
            break;

        case WM_SIZE:
            cxScreen = HIWORD(lParam);
            cyScreen = LOWORD(lParam);

            Ascent = tm.tmAscent;
            height = tm.tmHeight;
            ZeroMemory(buffer, BUFFER_SIZE);
            ZeroMemory(buffer1, BUFFER_SIZE);
            sprintf(buffer, "Width = %d, Height = %d", cxScreen, cyScreen);
            break;

        case WM_RBUTTONDOWN:
            MessageBoxA(hWnd, buffer, "current size", MB_OK);
            break;

        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            SetTextAlign(hdc, TA_CENTER);
            TextOutA(hdc, cxScreen, cyScreen, "Hi Sangameshwar", strlen("Hi Sangameshwar"));
            EndPaint(hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage(EXIT_SUCCESS);
            break;
    }

    return(DefWindowProc(hWnd, uMsg, wParam, lParam));

}

*/