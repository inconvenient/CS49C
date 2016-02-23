#include <stdio.h>

int count_char(char *str);

int main(void)
{
    // Read a desired string length
    int len;
    scanf("%d", &len);
    
    // Read a string
    char str[100];    
    scanf("%s", str);
    
    // Read strings until '#' is found
    while (str[0] != '#') {
        
        // Print strings with the correct length
        if (len == count_char(str))
            printf("%s\n", str);
        
        scanf("%s", str);        
    }
    
    return 0;
}

int count_char(char *str)
{
    // YOUR CODE HERE
    int i , count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
