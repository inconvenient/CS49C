#include <stdio.h>

////REQUIRED \[.*\].*\=

int room[10][10];  // Map of the room

int main(void)
{
    int x, y;
    scanf("%d %d", &x, &y); // Read the donuts' location
    
    room[x][y] = 0;
    
    
    // This assigns the map's values.
    int a, b;
    for (a = 0; a < 10; a++) // Loop through rows
    {
        for(b = 0; b < 10; b++) // Loop through columns
        {
            if(abs(a - x) > abs(b - y)) // If rows - x value of donut is greater than col - y value of donut
            {
                room[a][b] = abs(a - x); // Assign the greater value.
            }
            else(room[a][b] = abs(b - y)); // Else assign the smaller value.
        }
    }

    // This prints the map.
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            printf("%d", room[i][j]);
        }
        putchar('\n');
    } 
    return 0;
}