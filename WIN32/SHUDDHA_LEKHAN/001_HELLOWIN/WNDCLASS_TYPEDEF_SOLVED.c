//////////////////////////////////////////
typedef struct tagWNDCLASSEXA 
{
    CHAR 
    LPSTR 
    LPCSTR 
}WNDCLASSEXA;
//////////////////////////////////////////
typedef struct tagWNDCLASSEXW
{
    WCHAR 
    LPWSTR 
    LPCWSTR 
}WNDCLASSEXW; 
//////////////////////////////////////////
#ifndef UNICODE 
    #define WNDCLASSEX  WNDCLASSEXW 
#else 
    #define WNDCLASSEX  WNDCLASSEXA 
#endif 
//////////////////////////////////////////
API 

APIA
APIW

DATA_TYPEA
DATA_TYPEW
////////////////////////////////////////