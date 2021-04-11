#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over height
    for (int i = 0; i < height; i++) 
    {
        // Iterate over width
        for (int j = 0; j < width; j++)
        {
            // Calculate the average rgbt
            float average = (image[i][j].rgbtRed 
                             + image[i][j].rgbtGreen 
                             + image[i][j].rgbtBlue) / 3.0;
            // Update rgbt                    
            image[i][j].rgbtRed = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtBlue = round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    
    // Iterate over height
    for (int i = 0; i < height; i++)
    {
        // Iterate over width
        for (int j = 0; j < width; j++)
        {
            // Attribute to new values to new values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
           
            // Calculate new sepia rgbt
            float sepiaRed =  .393 * originalRed 
                              + .769 * originalGreen 
                              + .189 * originalBlue;
            float sepiaGreen = .349 * originalRed 
                               + .686 * originalGreen 
                               + .168 * originalBlue;
            float sepiaBlue = .272 * originalRed 
                              + .534 * originalGreen 
                              + .131 * originalBlue;
                            
            // Ensuring values are correct
            if (sepiaRed > 255) 
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
           
            // Rounding values and updating rgbt
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Iterate over height
    for (int i = 0; i < height; i++)
    {
        // Iterate over half the width
        for (int j = 0, midwidth = floor(width / 2) ; j < midwidth; j++)
        {
            // Switch pixels between j and width - 1 - j
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a new space to store blurred rbgts
    RGBTRIPLE(*blurred)[width] = calloc(height, width * sizeof(RGBTRIPLE));

    // Iterate over height
    for (int i = 0; i < height; i++)
    {
        // Iterate over width
        for (int j = 0; j < width; j++)
        {
    
            int total, blurRed, blurGreen, blurBlue;
            
            // First line of pixels
            if (i == 0)
            {
                // First pixel (corner)
                if (j == 0) 
                {
                    blurRed = image[i][j].rgbtRed + image[i][j + 1].rgbtRed 
                              + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;
                    
                    blurGreen = image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen
                                + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;
                    
                    blurBlue =  image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue
                                + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;
                    total = 4;
                }
                // Last pixel (corner)
                else if (j == width - 1)
                {
                    blurRed = image[i][j - 1].rgbtRed + image[i][j].rgbtRed 
                              + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed;
                    
                    blurGreen = image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen
                                + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen;
                    
                    blurBlue = image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue
                               + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue;
                    total = 4;
                } 
                // Remaining of first line (edge)
                else
                {
                    blurRed = image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed
                              + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;
                    
                    blurGreen = image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen
                                + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;
                    
                    blurBlue = image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue
                               + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;
                    total = 6;
                }
            } 
            // Last line of pixels
            else if (i == height - 1)
            {
                // First pixel (corner)
                if (j == 0)
                {
                    blurRed = image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed 
                              + image[i][j].rgbtRed + image[i][j + 1].rgbtRed;
                    
                    blurGreen = image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen 
                                + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen;
                    
                    blurBlue = image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue 
                               + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue;
                    total = 4;
                }
                // Last pixel (corner)
                else if (j == width - 1)
                {
                    blurRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed 
                              + image[i][j - 1].rgbtRed + image[i][j].rgbtRed;
                    
                    blurGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen  
                                + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen;
                    
                    blurBlue =  image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue 
                                + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue;
                    total = 4;
                }
                // Remaining of last line (edge)
                else
                {
                    blurRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed 
                              + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed;
                    
                    blurGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen 
                                + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen;
                    
                    blurBlue =  image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue 
                                + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue;
                    total = 6;
                }
            }
            // Remainging lines of pixel
            else 
            {
                // First column of pixels (edge)
                if (j == 0)
                {
                    blurRed = image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed 
                              + image[i][j].rgbtRed + image[i][j + 1].rgbtRed
                              + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;
                    
                    blurGreen = image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen 
                                + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen
                                + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;
                    
                    blurBlue = image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue 
                               + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue
                               + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;
                    total = 6;
                }
                // Last column of pixels (edge)
                else if (j == width - 1)
                {
                    blurRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed
                              + image[i][j - 1].rgbtRed + image[i][j].rgbtRed
                              + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed;
                    
                    blurGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen 
                                + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen
                                + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen;
                    
                    blurBlue =  image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue 
                                + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue
                                + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue;
                    total = 6;
                }
                // Middle pixels
                else 
                {
                    blurRed = image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed 
                              + image[i][j - 1].rgbtRed + image[i][j].rgbtRed + image[i][j + 1].rgbtRed
                              + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed;
                    
                    blurGreen = image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen 
                                + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen
                                + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen;
                    
                    blurBlue =  image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue 
                                + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue
                                + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue;
                    total = 9;
                }
            }
            
            // Calculate new average values and store into blurred
            blurred[i][j].rgbtRed = round((float) blurRed / total);
            blurred[i][j].rgbtGreen = round((float) blurGreen / total);
            blurred[i][j].rgbtBlue = round((float) blurBlue / total);
        }
    }
    
    // Iterate over height
    for (int i = 0; i < height; i++)
    {
        // Iterate over width
        for (int j = 0; j < width; j++)
        {
            // Update image with blurred
            image[i][j] = blurred[i][j];
        }
    }
    return;
}

