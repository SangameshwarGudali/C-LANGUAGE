#include <Windows.h> 

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    MessageBox(NULL, TEXT("Hello, Win32 SDK"), TEXT("Welcome"), MB_OK); 
    ExitProcess(EXIT_SUCCESS); 
}

/* 
typedef char CHAR; 
typedef unsigned short wchar_t; 
typedef wchar_t WCHAR; 
MessageBox(HWND, CHAR*, CHAR*, DWORD);  //ASCII 

MessageBox(HWND, WCHAR*, WCHAR*, DWORD);    // UNICODE 

MessageBoxA(HWND, CHAR*, CHAR*, CHAR*); 
MessageBoxW(HWND, WCHAR*, WCHAR*, DWORD); 

#ifdef UNICODE 
#define MessageBox MessageBoxW 
#else 
#define MessageBox MessageBoxA 
#endif 
*/ 