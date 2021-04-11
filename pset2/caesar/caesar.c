#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int verify_key(string s);


int main(int argc, string argv[])
{
    // Verify key validity
    // verify right number of arguments
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else 
    {
        //Verify right type of argument
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }
    }
    
    //Turn string arg into integer
    int k = atoi(argv[1]);
    string s = get_string("plaintext: ");
    
    // Ciphertext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Uppercase characters
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = (s[i] + k - 64) % 26 + 64;
            printf("%c", s[i]);
        }
        // Lowercase characters
        else if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = (s[i] + k - 96) % 26 + 96;
            printf("%c", s[i]);
        }
        // Other characters
        else
        {
            printf("%c", s[i]);
        }

    }
    printf("\n");
}