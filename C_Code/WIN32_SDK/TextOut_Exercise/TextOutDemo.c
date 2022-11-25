#include <Windows.h> 
#include <assert.h> 

#define _text TEXT

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = _text("Standard Window"); 
    static TCHAR szWindowName[] = _text("MSTC 3 MEETING"); 

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
            TextOut(hdc, cxSize/2, cySize/2, _text("Hello,PRADYUMNA JOSHI!"), 
                    lstrlen(_text("Hello,PRADYUMNA JOSHI!"))); 
            EndPaint(hWnd, &ps); 
            break; 

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hWnd, uMsg, wParam, lParam)); 
}