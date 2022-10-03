#include <windows.h>
#include <assert.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib")

#define _text TEXT


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
BOOL PrintMyPage (HWND) ;
extern HINSTANCE hInst ;
extern TCHAR szAppName[] ;
extern TCHAR szCaption[] ;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = _text("Standard Window"); 
    static TCHAR szWindowName[] = _text("The TextOut Exercise"); 

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
void PageGDICalls (HDC hdcPrn, int cxPage, int cyPage)
{
    static TCHAR szTextStr[] = TEXT ("Hello, Printer!") ;
    Rectangle (hdcPrn, 0, 0, cxPage, cyPage) ;
    MoveToEx (hdcPrn, 0, 0, NULL) ;
    LineTo (hdcPrn, cxPage, cyPage) ;
    MoveToEx (hdcPrn, cxPage, 0, NULL) ;
    LineTo (hdcPrn, 0, cyPage) ;
    SaveDC (hdcPrn) ;
    SetMapMode (hdcPrn, MM_ISOTROPIC) ;
    SetWindowExtEx (hdcPrn, 1000, 1000, NULL) ;
    SetViewportExtEx (hdcPrn, cxPage / 2, -cyPage / 2, NULL) ;
    SetViewportOrgEx (hdcPrn, cxPage / 2, cyPage / 2, NULL) ;
    Ellipse (hdcPrn, -500, 500, 500, -500) ;
    SetTextAlign (hdcPrn, TA_BASELINE | TA_CENTER) ;
    TextOut (hdcPrn, 0, 0, szTextStr, lstrlen (szTextStr)) ;
    RestoreDC (hdcPrn, -1) ;
}
LRESULT CALLBACK WndProc (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int cxClient, cyClient ;
    HDC hdc ;
    HMENU hMenu ;
    PAINTSTRUCT ps ;
    switch (message)
    {
    case WM_CREATE:
        hMenu = GetSystemMenu (hwnd, FALSE) ;
        AppendMenu (hMenu, MF_SEPARATOR, 0, NULL) ;
        AppendMenu (hMenu, 0, 1, TEXT ("&Print")) ;
        return 0 ;
    case WM_SIZE:
        cxClient = LOWORD (lParam) ;
        cyClient = HIWORD (lParam) ;
        return 0 ;
    case WM_SYSCOMMAND:
        if (wParam == 1)
        {
            if(!PrintMyPage (hwnd))
            {
                MessageBox (hwnd, TEXT ("Could not print page!"),
                szAppName, MB_OK | MB_ICONEXCLAMATION) ;
                return 0 ;
            }
            
        }
        break ;
    case WM_PAINT :
        hdc = BeginPaint (hwnd, &ps) ;
        PageGDICalls (hdc, cxClient, cyClient) ;
        EndPaint (hwnd, &ps) ;
        return 0 ;
    case WM_DESTROY :
        PostQuitMessage (0) ;
        return 0 ;
 }
 return DefWindowProc (hwnd, message, wParam, lParam) ;
}
