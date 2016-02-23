// Complete the following program which fills and prints this array.
//
//   012345
//   101234
//   210123
//   321012
//   432101
//   543210
//
// In other words, put 0's on the main diagonal,
// 1's on the elements next to those,
// 2's on the elements next to those, and so on.

#include <stdio.h>
#define SIZE 6

int main(void)
{
    int diagonal[SIZE][SIZE];
    int i, j;
    for (i = 0; i < SIZE; i++) 
    {
        for (j = 0; j < SIZE; j++)
        {
            diagonal[i][j] = (j - i > 0 ? j - i : i -j);        
        }          
    }
    
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d", diagonal[i][j]);
        }
        putchar('\n');
    }
}