#include <stdio.h>

////FORBIDDEN \%c

const char ASCII64 = 'A' - 1;

int cipher[50];  // Phrase as numeric codes
char phrase[50]; // Phrase to be displayed

int main(void)
{
    int i;
    // Read the codes for letters (1-26), spaces(0) and end (-1)
    for (i = 0; i < 50; i++) {
        scanf("%d", &cipher[i]);
        if (cipher[i] < 0) break;
    }

    // Read the cipher array, convert the # into a char using const char ASCII64
    // Place the char into the phrase array.
    
    int x;
    
    for(x = 0; x < 50; x++)
    {
        if(cipher[x] == 0)
        {
            phrase[x] = ' ';
        }
        else if(cipher [x] < 0)
        {
            break;
        }
        else(phrase[x] = cipher[x] + ASCII64);       
    }
    
    printf("%s\n", phrase);

    return 0;
}