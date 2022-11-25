#include <stdio.h>
#include <stdlib.h>

void to_upper(char c);
/*void add_of_int(int num1, int num2);
void add_of_float(float num_f1, float num_f2);
void add_of_double(double num_d1, double num_d2);*/

int main(void)
{
   char c_value = 67;
   int value1 = 10;
   int value2 = 20;
   float f_value1 = 11.2;
   float f_value2 = 22.2;
   double d_value1 = 44.65456;
   double d_value2 = 66.3546;

   to_upper(c_value);
   /*add_of_int(value1, value2);
   add_of_float(f_value1, f_value2);
   add_of_double(d_value1, d_value2);
*/
    exit(0);
}

void to_upper(char c)
{
    if((c > 97) && (c < 122))
    {
        c = c-32;
    }
    printf("c = %c\n",c);
}