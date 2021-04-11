#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt name from user
    string name = get_string("What is your name ?\n");
    // Print result
    printf("hello, %s\n", name);
}