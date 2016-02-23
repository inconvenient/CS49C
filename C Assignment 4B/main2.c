#include <stdio.h>

////FORBIDDEN \%c

const char ASCII64 = 'A' - 1;

int cipher[50]; // Phrase as numeric codes
char phrase[50]; // Phrase to be displayed
char guess[6]; // Player's guessed letters
char temp[50]; // Convert cipher (int) into phrase (char) for comparison

int main(void) {
    int i;

    // Read the codes for letters (1-26), spaces(0) and end (-1)    
    for (i = 0; i < 50; i++) {
        scanf("%d", &cipher[i]);
        if (cipher[i] < 0) break;
    }

    // Read the player's guessed letters
    for (i = 0; i < 6; i++)
        while ((guess[i] = getchar()) == ' ')
            ; // skip any spaces

    // Temporarily convert the cipher, which is an int, into phrase,
    // which is a char, since guess is a char. You want to compare guess and temp.
    int x;
    for (x = 0; x < 50; x++) {
        if (cipher[x] == 0) {
            temp[x] = ' ';
        } else if (cipher [x] < 0) {
            break;
        } else(temp[x] = cipher[x] + ASCII64);
    }

    // Fill in every char with an underscore first. Underscore is ASCII # 95
    for (i = 0; i < 50; i++) {
        if (cipher[i] > 0) {
            phrase[i] = ASCII64 + 31; 
        } else if (cipher[i] == 0) {
            phrase[i] = ' ';
        } else if (cipher[i] < 0) {
            break;
        }
    }

    // Compare guess with temp to see if it matches. If it does, add to phrase.
    // When it adds the char into phrase, it will overwrite the _ that was
    // added in the previous loop.
    int g;
    for (g = 0; g < 6; g++) {
        for (i = 0; i < 50; i++) {
            if (guess[g] == temp[i]) {
                phrase[i] = guess[g];
            }
        }
    }

    printf("%s\n", phrase);

    return 0;
}