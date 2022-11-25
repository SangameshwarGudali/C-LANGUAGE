int* get_num_3_v1()
{
    int n = 10; 

    return &n;  // DANGLING POINTER 
}
/* (ha varcha code kashatahi chalat nahi)*/
//////////////////////////////////////////

int* get_num_3_v2()
{
    static int n = 10;
     
    return &n;  // NO DANGLING POINTER 
                // BUT NOT THREAD SAFE 
}
/*(get_num_3_v2  ha single threded application madhe work hoil
but multithreaded application madhe nahi)*/
