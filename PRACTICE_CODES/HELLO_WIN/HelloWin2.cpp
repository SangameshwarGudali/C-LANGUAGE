#include <windows.h>
#include <stdio.h>
#include <assert.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static char szAppName[] = TEXT("The Standerd Window");
    static char szWindowName[] = TEXT("CoreCode Programming Academy MasterClass in C");

    HWND hWnd = NULL;
    HCURSOR hCursor = NULL;
    HICON hIcon = NULL;
    HICON hIconSm = NULL;
    HBRUSH hBrush = NULL;

    WNDCLASSEX wndEx;
    MSG msg;

    ZeroMemory(&wndEx, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
    assert(hBrush);

    hIcon = LoadIcon(NULL, IDI_APPLICATION);
    assert(hIcon);

    hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    assert(hIconSm);

    wndEx.cbSize = sizeof(WNDCLASSEX);
    wndEx.cbClsExtra = 0;
    wndEx.cbWndExtra = 0;
    wndEx.hInstance = hInstance;
    wndEx.hCursor = hCursor;
    wndEx.hIcon = hIcon;
    wndEx.hIconSm = hIconSm;
    wndEx.hbrBackground = hBrush;
    wndEx.style = CS_HREDRAW | CS_VREDRAW;
    wndEx.lpszClassName = szAppName;
    wndEx.lpszMenuName = NULL;
    wndEx.lpfnWndProc = WndProc;

    ATOM bRet = RegisterClassEx(&wndEx);
    assert(bRet);

    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szAppName, szWindowName, WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT , CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                            NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, nShowCmd);
    UpdateWindow(hWnd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    #define BUFFER_SIZE 32
    static int cxScreen, cyScreen;
    static char buffer[BUFFER_SIZE];

    PAINTSTRUCT ps;
    HDC hdc = NULL;

    TEXTMETRIC tm;
    static int cxChar, cyChar;

    switch(uMsg)
    {
        case WM_SIZE:
            cxScreen = LOWORD(lParam);
            cyScreen = HIWORD(lParam);
            sprintf(buffer, "width = %d, height = %d\n", cxScreen, cyScreen);
            break;

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // All painting occurs here, between BeginPaint and EndPaint.
            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
            EndPaint(hWnd, &ps);
            break;
        }
        
        case WM_CREATE:
        {
            hdc = GetDc(hWnd);
            GetTextMetrics(hdc, &tm);
            cxChar = tm.tmAveCharWidth;
            cyChar = tm.tmHeight + tm.tmExternalLeading;
            break;
        }
            
        case WM_RBUTTONDOWN:
            MessageBox(hWnd, buffer, "current size", MB_OK);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return(DefWindowProc(hWnd, uMsg, wParam, lParam));
}


