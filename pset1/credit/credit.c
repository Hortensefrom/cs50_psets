#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card = get_long("%s","Number: ");
    string result = "INVALID\n";
    long checksum = 0;
    if ( (card - card % 10000000000000 ) == 340000000000000 || (card - card % 10000000000000) == 370000000000000)
    {
        result = "AMEX\n";
    }
    if ( (card - card % 100000000000000 ) == 5100000000000000 || (card - card % 100000000000000) == 5200000000000000
        || (card - card % 100000000000000 ) == 5300000000000000 || (card - card % 100000000000000 ) == 5400000000000000
        || (card - card % 100000000000000 ) == 5500000000000000 )
    {
        result = "MASTERCARD\n";
    }
    if ( (card - card % 100000000000000 ) == 4000000000000000 || (card - card % 100000000000) == 4000000000000)
    {
        result = "VISA\n";
    }
    int x = 0;
    for (int i = 0; i < 9; i++)
    {
        int exp = pow(10,2 * i + 2);
        x = round(((card % exp) / (exp / 10))) * 2;
        if ( x > 9 )
        {
            x = round(( x % 100 ) / 10) + x % 10;
        }            
        checksum = checksum + x;
    }
    for (int i = 0; i < 9 ; i++)
    {
        int exp = pow(10,2 * i + 1);
        x = round(((card % exp) / (exp / 10)));
        checksum = checksum + x;
    }
    if (checksum % 10 != 0)
    {
        result = "INVALIIIID\n";
    }
    printf("%s",result);
}

