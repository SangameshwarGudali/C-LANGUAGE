typedef int day_t; 
typedef int month_t; 
typedef int year_t; 
typedef int status_t; 

struct Date 
{
    day_t day;  
    month_t month; 
    year_t year; 
}; 

typedef struct Date Date_t; 

Date_t* create_date(day_t init_day, month_t init_month, year_t init_year); 
day_t get_day(Date_t* pDate); 
month_t get_month(Date_t* pDate); 
year_t get_year(Date_t* pDate); 
status_t set_day(Date_t* pDate, day_t new_day); 
status_t set_month(Date_t* pDate, month_t new_moth); 
status_t set_year(Date_t* pDate, year_t new_year); 

#include <Windows.h> 

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
                    LPSTR lpCmdLine, int nShowCmd)
{
    
}
