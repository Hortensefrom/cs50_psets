#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);


// Readability function
int main(void) 
{
    // Input text from user
    string text = get_string("Text: ");
    
    // Number of letters, words and sentences
    int L = count_letters(text);
    int W = count_words(text);
    int S = count_sentences(text);
    
    printf("%i letters %i words %i sentences", L W S);
    // Index computation  
    int grade = round(0.0588 * ((float) L / W) * 100 - 0.296 * ((float) S / W) * 100 - 15.8); 

    // Print grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    } 
    else if (grade >= 16) 
    {
        printf("Grade 16+\n");
    } 
    else 
    {
        printf("Grade %d\n", grade);
    }
}



// Count letters function
int count_letters(string s)
{
    int L = 0;
    for (int i = 0, n = strlen(s); i < n; i++) 
    {
        if ((s[i] >= 'a' && s[i] <= 'z')
            || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            L++;
        }
    }
    return L;
}

// Count words function
int count_words(string s)
{
    int W = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            W++;
        }
    }
    return W;
}

// Count sentences function
int count_sentences(string s)
{
    int S = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            S++;
        }
    }
    return S;
}