#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt intenger from user
    int height = get_int("Height: ");
    // Checks wether height is between 1 and 8
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    
    // Iterate over each line
    for (int i = 0; i < height; i++)
    {
        // Print espaces
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Print left hahshes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // Print the gap
        printf("  ");
        // Print right hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        // Return
        printf("\n");
    }
}