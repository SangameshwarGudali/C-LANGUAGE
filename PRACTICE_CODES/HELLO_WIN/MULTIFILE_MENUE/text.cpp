#include <Windows.h>
#include <assert.h>
#include <dwrite.h>

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void UpdateGraph(HWND hWnd, HDC dc);

void AddMenus(HWND);
HMENU hMenu;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("SHIV-SAN APP");
    static TCHAR szWindowName[] = TEXT("MY WINDOW"); 

    HWND hWnd = NULL;
    HBRUSH hBrush = NULL;
    HICON hIcon = NULL;
    HICON hIconSm = NULL; 
    HCURSOR hCursor = NULL;

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

    hCursor = LoadCursor(NULL, IDC_ARROW);
    assert(hCursor);

    wndEx.cbSize = sizeof(WNDCLASSEX);
    wndEx.cbClsExtra = 0;
    wndEx.hInstance = hInstance;
    wndEx.hbrBackground = hBrush;
    wndEx.hIcon = hIcon;
    wndEx.hIconSm = hIconSm;
    wndEx.hCursor = hCursor;
    wndEx.lpfnWndProc = WndProc;
    wndEx.lpszClassName = szClassName;
    wndEx.lpszMenuName = NULL;
    wndEx.style = CS_HREDRAW | CS_VREDRAW;

    ATOM bRet = RegisterClassEx(&wndEx);
    assert(bRet != NULL);

    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szWindowName,
                        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
                        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                        NULL, NULL, hInstance, NULL);
    assert(hWnd);

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
    switch(uMsg)
    {
        case WM_PAINT:
        {
            RECT rToPaint;
            if (!GetUpdateRect(hWnd, &rToPaint, FALSE))
                break;    //No regions to update, leave procedure
            PAINTSTRUCT ps;
            BeginPaint(hWnd, &ps);

            //Do graphical paint
            UpdateGraph(hWnd, ps.hdc);

            EndPaint(hWnd, &ps);

            break;        //End of procedure
        }
    
        case WM_CREATE:
        
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }
    return(DefWindowProc(hWnd, uMsg, wParam, lParam));
}



void UpdateGraph(HWND hWnd, HDC dc)
{
  RECT rc;
  LPCWSTR santext;
  santext = (LPCWSTR("Hello world I am here"));
  GetClientRect(hWnd, &rc);
  DrawTextW(dc, santext, -1, &rc, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
}