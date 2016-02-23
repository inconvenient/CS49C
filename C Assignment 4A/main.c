#include <stdio.h>

////REQUIRED \[.*\].*\=

int hall[10];  // Map of the hallway

int main(void)
{
    int x;
    scanf("%d", &x); // Read the donuts' location 
    
    hall[x] = 0;
    
    int k; // k variable works for the steps BEFORE the donut.
    for(k = 1; k < 10; k++)
    {
        hall[x-k] = k;
    }
    
    int j; // j variable works for the steps AFTER the donut.
    for(j = 1; j < 10; j++)
    {
        hall[x+j] = j;
    }
    
    // Print the map
    int i;
    for (i = 0; i < 10; i++)
        printf("%d", hall[i]);
    putchar('\n');
    
    return 0;
}