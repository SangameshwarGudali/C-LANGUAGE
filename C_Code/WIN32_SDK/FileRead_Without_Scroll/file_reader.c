#include <Windows.h> 
#include <assert.h> 
#include <stdio.h> 

#define _text TEXT

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

typedef struct tagCmdLine
{
    LPSTR lpCmdLine; 
}CMDLINEDATA, *PCMDLINEDATA; 

FILE* g_fp = NULL; 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = _text("Standard Window"); 
    static TCHAR szWindowName[] = _text("The TextOut Exercise"); 

    HBRUSH hBrush = NULL; 
    HCURSOR hCursor = NULL; 
    HICON hIcon = NULL; 
    HICON hIconSm = NULL; 
    HWND hWnd = NULL; 

    LPCREATESTRUCTA p_cs = NULL; 
    PCMDLINEDATA p_cld = NULL; 
    WNDCLASSEX wndEx; 
    MSG msg; 

    ZeroMemory(&wndEx, sizeof(WNDCLASSEX)); 
    ZeroMemory(&msg, sizeof(MSG)); 

    p_cs = (CREATESTRUCT*)malloc(sizeof(CREATESTRUCTA)); 
    if(p_cs == NULL)
    {
        fprintf(stderr, "fatal:out of memory\n"); 
        ExitProcess(EXIT_FAILURE); 
    }
    ZeroMemory(p_cs, sizeof(CREATESTRUCTA)); 

    p_cld = (PCMDLINEDATA)malloc(sizeof(CMDLINEDATA)); 
    if(p_cld == NULL)
    {
        fprintf(stderr, "fatal:out of memory\n"); 
        ExitProcess(EXIT_FAILURE); 
    }
    p_cld->lpCmdLine = strdup(lpCmdLine); 

    fopen_s(&g_fp, "Log.txt", "w"); 
    if(g_fp == NULL)  
    {
        fprintf(stderr, "Log file could not opened\n"); 
        exit(EXIT_FAILURE); 
    }

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

    p_cs->lpCreateParams = (LPVOID)p_cld; 
    fprintf(g_fp, "WinMain:p_cs->lpCreateParams = %s\n", ((PCMDLINEDATA)(p_cs->lpCreateParams))->lpCmdLine); 
    p_cs->x = CW_USEDEFAULT; 
    p_cs->y = CW_USEDEFAULT; 
    p_cs->cx = CW_USEDEFAULT; 
    p_cs->cy = CW_USEDEFAULT; 
    p_cs->dwExStyle = WS_EX_APPWINDOW; 
    p_cs->style = WS_OVERLAPPEDWINDOW; 
    p_cs->hInstance = hInstance; 
    p_cs->hMenu = NULL; 
    p_cs->hwndParent = NULL; 
    p_cs->lpszClass = szClassName; 
    p_cs->lpszName = szWindowName; 
    
    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szWindowName, WS_OVERLAPPEDWINDOW, 
                    CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
                    (HWND)NULL, (HMENU)NULL, hInstance, (LPVOID)p_cs); 
    assert(hWnd); 
    
    ShowWindow(hWnd, nShowCmd); 
    UpdateWindow(hWnd); 

    while(GetMessage(&msg, (HWND)NULL, 0, 0))
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    }

    //free(((PCMDLINEDATA)(p_cs->lpCreateParams))->lpCmdLine);
    free(p_cs->lpCreateParams);  
    free(p_cs); 
    p_cs = NULL; 

    fclose(g_fp); 
    g_fp = NULL; 

    return (msg.wParam); 
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int cxChar, cyChar, cxCaps; 
    static int cxSize, cySize; 
    PCMDLINEDATA pCmdData = NULL; 
    LPSTR lpszFilePath = NULL; 

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
            pCmdData = ((PCMDLINEDATA)(((LPCREATESTRUCTA)lParam)->lpCreateParams)); 
            lpszFilePath = pCmdData->lpCmdLine; 
            fprintf(g_fp, "PathName=%s\n", lpszFilePath); 

            break; 

        case WM_SIZE: 
            cxSize = LOWORD(lParam); 
            cySize = HIWORD(lParam); 
            break; 

        case WM_PAINT: 
            hdc = BeginPaint(hWnd, &ps); 
            SetTextAlign(hdc, TA_CENTER); 
            TextOut(hdc, cxSize/2, cySize/2, _text("Hello,World!"), 
                    lstrlen(_text("Hello,World!"))); 
            EndPaint(hWnd, &ps); 
            break; 

        case WM_DESTROY: 
            PostQuitMessage(EXIT_SUCCESS); 
            break; 
    }

    return (DefWindowProc(hWnd, uMsg, wParam, lParam)); 
}