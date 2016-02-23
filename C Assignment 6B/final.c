#include <stdio.h>
#define SIZE 6

int main(void)
{
    int diagonal[SIZE][SIZE];
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            diagonal[i][j] = (j - i > 0 ? j - i : i -j);
        }
    }
    
    // Get the "color" characters
    char colors[SIZE];
    for (i = 0; i < SIZE; i++)
        colors[i] = getchar();
    
    
    // Cycle the colors for each of the frames
    int frame;
    for (i = 0; i < SIZE; i++) {
        
        // Frames are printed horizonally
        for (frame = 0; frame < SIZE; frame++) 
        {
            for (j = 0; j < SIZE; j++) 
            {
                diagonal[j][frame] = colors[j];
                printf("%c", diagonal[j][frame]);
            }
            printf("      ");
        }
        putchar('\n');
    }
}

