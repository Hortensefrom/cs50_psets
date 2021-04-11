#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    // Ensure proper number of arguments
    if (argc != 2)
    {
        printf("Usage: only one argument allowed.\n");
        return 1;
    }

    // Open input file
    FILE *card = fopen(argv[1], "r");

    // Ensure input file open properly
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }
    
    BYTE buffer[BUFFER_SIZE];
    FILE *img;
    int jpegCounter = 0;
    char filename[32];

    // While loop checks if we've reached EOF
    while ((fread(buffer, BUFFER_SIZE, 1, card) != 0))
    {
        // Looks for the start of a new jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // First jpeg or not ?
            if (jpegCounter == 0)
            {
                sprintf(filename, "%03i.jpg", jpegCounter);
                img = fopen(filename, "w");
                fwrite(buffer, BUFFER_SIZE, 1, img);
                jpegCounter++;
            }
            // New jpeg
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", jpegCounter);

                img = fopen(filename, "w");
                fwrite(buffer, BUFFER_SIZE, 1, img);
                jpegCounter++;
            }

        }
        // Keeps writing in img file if not new jpeg
        else
        {
            fwrite(buffer, BUFFER_SIZE, 1, img);
        }

    }
    
    // Close last .jpeg
    fclose(img);
    
    // Close card
    fclose(card);
    
    // Success
    return 0;
}


