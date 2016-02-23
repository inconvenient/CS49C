#include <stdio.h>

int match(char *str, char *pattern);

int main(void)
{
    // Read a crossword pattern
    char pattern[100];
    scanf("%s", pattern);
    
    // Read a string
    char str[100];
    scanf("%s", str);

    // Read strings until '#' is found
    while (str[0] != '#') {
        
        // Print strings that match the pattern
        if (match(str, pattern))
            printf("%s\n", str);
        
        // Read the next string
        scanf("%s", str);        
    }
    
    return 0;
}

int match(char *str, char *pattern)
{
    // YOUR CODE HERE
    // Iterate through pattern until you find a non-underscore char.
    // get the position that the char is located in the string.
    // get the length of pattern
    // Iterate through the string to the position stored locally.
    // If that position in the string is the non-underscore char, print the string.
    
    int i, pos, final = 0;
    
    for (i = 0; pattern[i] != '\0'; i++)
    {
        if (pattern[i] != '_')
        {
            pos = i; // Pos is the position of the known char.
        }
    }
    
    if (strlen(str) == strlen(pattern))
    {
        if(str[pos] == pattern[pos])
        {
            final = 1;
        }
    }
    return final;
}
