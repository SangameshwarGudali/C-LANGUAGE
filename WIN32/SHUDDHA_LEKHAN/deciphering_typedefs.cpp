#include <Windows.h> 

(1) LRESULT 
typedef long long int LONG_PTR; 
typedef LONG_PTR LRESULT; 

(2) CALLBACK 
#define CALLBACK __stdcall 

(3) HWND 
typedef struct HWND__ HWND__
typedef HWND__* HWND; 

(4) UINT 
typedef unsigned int UINT; 

(5) WPARAM 
typedef unsigned long long int UINT_PTR; 
typedef UINT_PTR WPARAM; 

(6) LPARAM 
typedef long long int LONG_PTR; 
typedef LONG_PTR LPARAM; 

(7) WINAPI 
#define WINAPI __stdcall 

(8) HINSTANCE 
typedef struct HINSTANCE__ HINSTANCE__; 
typedef HINSTANCE__* HINSTANCE; 

(9) LPSTR 
typedef char CHAR; 
typedef CHAR* LPSTR; 

(10) TCHAR 
typedef wchar_t WCHAR; 
typedef WCHAR TCHAR; 

(11) HBRUSH 
typedef struct HBRUSH__ HBRUSH__; 
typedef HBRUSH__* HBRUSH; 

HBRUSH x; 
struct HBRUSH__* x; 

(12) HICON 
typedef struct HICON__ HICON__; 
typedef HICON__* HICON; 

(13) HCURSOR 
typedef HICON HCURSOR; 

(14) 
#define CONST const
typedef char CHAR; 
typedef CHAR* LPSTR; 
typedef CONST CHAR* LPCSTR; 
typedef wchar_t WCHAR; 
typedef WCHAR* LPWSTR; 
typedef CONST WCHAR* LPCWSTR; 

(14) WNDPROC 
typedef LRESULT CALLBACK (*WNDPROC)(HWND, UINT, WPARAM, LPARAM); 

(15) ATOM 
typedef unsigned short WORD; 
typedef WORD ATOM; 
typedef unsigned long DWORD; 

(16) LRESULT 
typedef long long LONG_PTR; 
typedef LONG_PTR LRESULT 

(13) WPARAM

typedef unsigned long long int UINT_PTR; 
typedef UINT_PTR WPARAM; 

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPaRAM wParam, LPARAM lParam); 

long long __stdcall WndProc(struct HWND__* hWnd, unsigned int uMsg, 
                            unsigned long long int wParam, 
                            long long int lParam); 

(14) lpfnWndProc 
    lp -> long pointer 
    fn -> function 
    WndProc -> Window Procedure 

    Declare a pointer to a function which accepts 
        1) Handle to a window 
        2) unsigned integer 
        3) unsigned long long int 
        4) long long int 
        and returns 
        long long int 

long long int (*pfn)(struct HWND__*, unsigned int, unsigned long long int, long long int); 

LRESULT(*lpfnWndProc)(HWND, UINT, WPARAM, LPARAM); 

typedef struct tagWNDCLASSEXW
{
    UINT cbSize; 
    int cbClsExtra; 
    int cbWndExtra; 
    HBRUSH hBrush; 
    HCURSOR hCursor; 
    HICON hIcon; 
    HICON hIconSm; 
    HINSTANCE hInstance; 
    LRESULT CALLBACK(*lpfnWndProc)(HWND, UINT, WPARAM, LPARAM); 
    LPCSTR lpszClassName; 
    LPCSTR lpszMenuName; 
    DWORD style; 
}WNDCLASSEXW;

#define UNICDE 

WNDCLASSEX -> WNDCLASSEXW 

WNDCLASSEX wndEx; 

wndEx.cbSize = sizeof(WNDLCASSEX); 
wndEx.cbClsExtra = 0; 
wndEx.cbWndExtra = 0; 
wndEx.hbrBackground = hBrush; 
wndEx.hCursor = hCusor; 
wndEx.hIcon = hIcon; 
wndEx.hIconSm = hIconSm; 
wndEx.hInstance = hInstance; 
wndEx.lpfnWndProc = WndProc; 

