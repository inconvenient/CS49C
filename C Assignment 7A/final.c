#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int i, j;
    char text[200];
    char minions[200] = "";
    char minion[10]; // useful for intermediate strings
    char temp[200];
    char dl[1] = "-"; // delimiter
    char *split; // split token
    
    // Read the raw text
    scanf("%s", text);
  
    // Replace all non-uppercase into a temp array to modify
    for (i = 0; i < strlen(text); i++)
    {
        if (!isupper(text[i]))
        {
            temp[i] = '-'; // Replaces all non-uppercase with a - char
        }
        else temp[i] = text[i];
    }
    
    split = strtok(temp, dl); // First token of temp
    while (split != NULL ) 
    {
        
        strcpy (minion, split);
        
        if(minion[0] > 'G') // G = 71 for GRU
        {
            strcpy (minions, minion);
            for(i = 1; i < strlen(minions); i++)
            {
                minions[i] = tolower(minions[i]);
            }
            printf("%s\n", minions);
        }
        else if(minion[0] = 'G')
        {
            if (tolower(minion[1]) > 'r')
            {
                strcpy(minions, minion);
                for(i = 1; i < strlen(minions); i++)
                {
                    minions[i] = tolower(minions[i]);
                }
                printf("%s\n", minions);
            }
        }
        split = strtok(NULL, dl); // Restart the strtok checker.
    }
    return 0;
}