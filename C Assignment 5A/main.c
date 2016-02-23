#include <stdio.h>

typedef struct {
    int green;
    int red;
} dice;

dice roll[10];
dice score;

int main(void)
{
    // Read the dice rolls
    int i;
    for (i = 0; i < 10; i++) {
        scanf("%d %d", &roll[i].green, &roll[i].red); // Store the dice roll in roll array.
    }
    
    for(i = 0; i < 10; i++)
    {
        score.green = score.green + roll[i].green;
        score.red = score.red + roll[i].red;
    }
    
    
    printf("Jean has %d points\n", score.green);
    printf("Fred has %d points\n", score.red);
    
    if (score.green > score.red)
        printf("Jean wins!\n");
    else if (score.red > score.green)
        printf("Fred wins!\n");
    else
        printf("It's a draw\n");
    
    return 0;
}
