#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Prompt user to use a positive float
float get_positive_float();

int main(void)
{
    float dollars = get_positive_float();
    // Convert dollars into cents
    int cents = round(dollars * 100);
    // Count the number of coins
    int n = 0;
    // This while loops test if we can use a quarter
    // by substracting 25 to the cents and checking if 
    // the result is positive
    while (cents - 25 >= 0)
    {
        // If the result is positive, increment n and substract 25 to cents
        n++ ;
        cents = cents - 25;
    }
    while (cents - 10 >= 0)
    {
        n++ ;
        cents = cents - 10;
    }
    while (cents - 5 >= 0)
    {
        n++ ;
        cents = cents - 5; 
    }
    while (cents - 1 >= 0) 
    {
        n++ ;
        cents = cents - 1;
    }
    printf("%i\n", n);
}


float get_positive_float(void)
{
    float x;
    do
    {
        x = get_float("%s", "Change owned: ");
    }
    while (x < 0);
    return x;
}