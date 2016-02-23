#include <stdio.h>
#include <string.h>

int main(void)
{
    // Read the raw text
    char text[200];
    scanf("%s", text);
    
    // Get strlen
    // Iterate through string
    // If it is uppercase, print it. If it is not, skip it
    
    int length = strlen(text);
    int i;
    
    for (i = 0; i < length; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", text[i]);
        }
    }   
    return 0;
}
