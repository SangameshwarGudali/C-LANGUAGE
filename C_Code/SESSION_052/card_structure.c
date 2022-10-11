/* 
    DATE: 
    month 
    year 


    CREDIT CARD 

    card_holder_name -> sequence of characters (string)
    card_number      -> unsigned long long int 
    cvv field        -> unsigned short 
    valid thru date  -> Date (struct Date)
    expiry date      -> Date (struct Date)
*/ 

struct CC_Date
{
    int month; 
    int year; 
}; 

struct credit_card
{
    char* cc_holder_name; 
    unsigned long long int cc_number; 
    unsigned short cc_cvv; 
    struct CC_Date cc_valid_thru_date; 
    struct CC_Date cc_expiry_date; 
}; 