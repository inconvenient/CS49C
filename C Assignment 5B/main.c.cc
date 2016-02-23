#include <stdio.h>

void what_game(char *schedule[], int day);

int main(void)
{
    char *sharks[] = { "Sharks",
        "", "Devils", "", "Hurricanes", "",
        "Penguins", "", "Canadiens", "", "",
        "Maple Leafs", "", "Blue Jackets", "Islanders", "",
        "Rangers", "", "Panthers", "", "Ducks",
        "", "Capitals", "", "Flames", "Oilers",
        "", "Jets", "", "Avalanche", "", ""
    };
    
    int day;
    scanf("%d", &day);
    what_game(sharks, day);
    return 0;
}

void what_game(char *schedule[], int day)
{
    // Print game information for this day

    
    
}