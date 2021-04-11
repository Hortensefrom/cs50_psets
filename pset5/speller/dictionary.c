// Implements a dictionary's functionality

#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 500;

// Hash table
node *table[N];

// Word count
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);
    char *word_copy = malloc(sizeof(char) * (n + 2));
    for (int i = 0; i < n + 1; i++)
    {
        word_copy[i] = tolower(word[i]);
    }
    
    int index = hash(word_copy);
    
    node *cursor = table[index];
    
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word_copy) == 0)
        {
            free(word_copy);
            return true;
        }
        cursor = cursor->next;
    }
    
    free(word_copy);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *infile = fopen(dictionary, "r");
    if (infile == NULL)
    {
        return false;
    }
    
    char *word = malloc(sizeof(char) * LENGTH);
    if (word == NULL)
    {
        return false;
    }
    
    while (fscanf(infile, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        unsigned int index = hash(word);
        strcpy(n->word, word);
        n->next = table[index];
        table[index] = n;
        word_count++;
    }
    
    free(word);
    
    fclose(infile);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *cursor = table[i]->next;
            free(table[i]);
            table[i] = cursor;
        }
    }
    return true;
}
