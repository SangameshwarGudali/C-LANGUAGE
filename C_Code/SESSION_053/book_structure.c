#include <stdio.h> 
#include <stdlib.h> 

/* 
    book
    title:                  bk_title:       string(char*)
    authors:                bk_authors:     string(char*) 
    publisher:              bk_publisher:   string(char*) 
    isbn:                   bk_isbn:        string(char*) 
    date_of_publication:    bk_pub_date:    struct Date 
    edition:                bk_edition:     int 
    number of pages:        bk_nr_pages:    int 
    reprint:                bk_reprint:     int 
    price:                  bk_price:       float 
*/ 

struct Date
{
    int day; 
    int month; 
    int year; 
}; 

struct book
{
    char* bk_title; 
    char* bk_authors; 
    char* bk_publisher; 
    char* bk_isbn; 
    struct Date bk_pub_date; 
    int bk_edition; 
    int bk_nr_pages; 
    int bk_reprint; 
    float bk_price; 
}; 

int main(void)
{
    struct book alg_book; 

    alg_book.bk_title = "Introduction to Algorithms"; 
    alg_book.bk_authors = "Cormen/Leiserson/Rivest/Stein"; 
    alg_book.bk_publisher = "MIT Press"; 
    alg_book.bk_isbn = "978-0-262-03384-8"; 
    alg_book.bk_pub_date.day = 20; 
    alg_book.bk_pub_date.month = 8; 
    alg_book.bk_pub_date.year = 2009; 
    alg_book.bk_edition  = 3; 
    alg_book.bk_nr_pages = 1292; 
    alg_book.bk_reprint = 1; 
    alg_book.bk_price = 4499.0; 

    printf("Book Title = %s\n", alg_book.bk_title); 
    printf("Book Authors = %s\n", alg_book.bk_authors); 
    printf("Book Publisher = %s\n", alg_book.bk_publisher); 
    printf("Book isbn = %s\n", alg_book.bk_isbn); 
    printf("Book publication day = %d\n", alg_book.bk_pub_date.day); 
    printf("Book publication month = %d\n", alg_book.bk_pub_date.month); 
    printf("Book publication year = %d\n", alg_book.bk_pub_date.year); 
    printf("Book Edition = %d\n", alg_book.bk_edition); 
    printf("Book Number of Pages = %d\n", alg_book.bk_nr_pages); 
    printf("Book Reprint = %d\n", alg_book.bk_reprint); 
    printf("Book price = %.2f\n", alg_book.bk_price); 

    exit(0); 
}