#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // Check for the right number of CL argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    // Check for the length of the key
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    
    // Check for non-alphabetic characters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!(islower(argv[1][i]) || isupper(argv[1][i])))
        {
            printf("Key must contain alphabetical characters only.");    
            return 1;
        }
    }
    
    // Check for repeated characters
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    
    // Prompt plain text from user
    string text = get_string("plaintext: ");
    
    // Iterate over each character and substitute
    for (int i = 0; i < strlen(text); i++)
    {
        if (islower(text[i]))
        {
            text[i] = tolower(argv[1][text[i] - 97]);
        }
        else if (isupper(text[i]))
        {
            text[i] = toupper(argv[1][text[i] - 65]);
        }
    }
    
    printf("ciphertext: %s\n", text);
    return 0;
}