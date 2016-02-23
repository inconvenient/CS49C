#include <stdio.h>

int main(void)
{
    char symbol1, symbol2, symbol3;
    scanf("%c%c%c", &symbol1, &symbol2, &symbol3);
    char payout; // ASCII : S = 83, T = 84, W = 87
    
    /*
     Start with 83 (S) then add the return values of statements depending
     on the 3 symbols inputted. 
     */
    payout = 83 + (symbol1==symbol3 || symbol2==symbol3) + (symbol1==symbol2 && symbol1==symbol3)*3 ;
    
    printf("Payout is %c\n", payout);
    return 0;
}