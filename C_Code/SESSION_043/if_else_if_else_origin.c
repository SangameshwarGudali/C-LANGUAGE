GO TO BACKERY 

if(Is Good day available?)
{
    BUY Good day; 
}
else
{
    if(Is Parle G available?)
    {
        Buy Parle G;
    }
    else
    {
        if(Is 50-50 available?)
        {
            BUY 50-50;
        }
        else
        {
            if(Is monaco available?)
            {
                BUY Monaco; 
            }
            else
            {
                BUY Toast;
            }
        }
    }
}

COME HOME 

////////////////////////////////////////

GOTO BACKERY 

if(is Good day available?)
{
    BUY Good day; 
}
else if(is Parle G available?)
{
    BUY Parle G; 
}
else if(is 50-50 available?)
{
    BUY 50-50;
}
else if(is Monaco available?)
{
    BUY Monaco; 
}
else
{
    BUY Toast; 
}

COME HOME


/* 

if(COND-if)
{
    BLOCK;
}
else if(CONDei-1)
{
    BLOCK;
}
else if(CONDei-2)
{
    BLOCK;
}
.
.
.
.
else if(CONDei-N)
{
    BLOCK;
}
else
{
    BLOCK;    
}

OUT STATEMENT; 
*/ 