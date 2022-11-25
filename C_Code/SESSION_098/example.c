#define TEST_1(a, b)    a * b 

#define TEST_2(a, b)  ((a) * (b))

int main(void)
{
    int m1, n1; 
    float f1, f2; 
    double d1, d2; 

    TEST_1(m1, n1);     //  m1 * n1
    TEST_1(f1, f2);     //  f1 * f2 
    TEST_1(d1, d2);     //  d1 * d2 

    TEST_1(m1+n1, m1-n1); // m1+n1 * m1-n1

    TEST_1(int, float); 

    TEST_2(m1+n1, m1-n1); // ((m1+n1) * (m1-n1))

    return (0); 
}