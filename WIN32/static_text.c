#include <windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "gdi32.lib")

#define WM_SETFONT                      0x0030

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                    PWSTR lpCmdLine, int nCmdShow) {

    MSG  msg;    
    WNDCLASSW wc = {0};
    wc.lpszClassName = L"Static Control";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

  
    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Criminal",
                  WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                  100, 100, 500, 700, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {
  
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    static wchar_t *lyrics =  L"HON. KEN THOMPSON GROUP";

    switch(msg) {

        case WM_CREATE:
            CreateWindowW(L"Static", lyrics, WS_CHILD | WS_VISIBLE | SS_LEFT,500, 500, 200, 200, hwnd, (HMENU) 1, NULL, NULL);
            case WM_SETFONT:

            break;
        
        case WM_DESTROY:

            PostQuitMessage(0);
            break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

