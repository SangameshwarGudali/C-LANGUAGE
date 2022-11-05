#include <stdio.h> 

/* Option 1 */ 

struct Date 
{
    int day; 
    int month; 
    int year; 
}; 

typedef struct Date Date_t; 
////////////////////////////////////

/* Option 2 */ 

typedef 

struct Date 
{
    int day; 
    int month; 
    int year; 
}

Date_t; 

///////////////////////////////////////////

/* option 3 */ 

typedef struct Date Date_t; 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

///////////////////////////////////////////