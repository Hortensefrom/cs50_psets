#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int x = get_float("Number: ");
    int n = get_int("Rang: ");
    int exp = pow(10,n);
    x = round((x % exp)/(exp/10));
    printf("%i\n",x);
}
