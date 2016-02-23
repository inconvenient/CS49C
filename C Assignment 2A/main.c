#include <stdio.h>

int main(void)
{
    int jar;                       // the total number of coins in the jar
    int minnie, maxine;            // the number of quarters they each request
    int extra;                     // extra coins leftover after the 2 girls ask for coins
    int extraMinnie, extraMaxine;  // amount of coins + extra coins if there are any.
    
    scanf("%d %d %d", &jar, &minnie, &maxine);
    
    if(minnie + maxine <= jar)
    {
       extra = jar - minnie - maxine;
       
       if(minnie < maxine)
       {
           extraMinnie = minnie + extra;
           extraMaxine = maxine;
       }
       else if(maxine < minnie)
       {
           extraMaxine = maxine + extra;
           extraMinnie = minnie;
       }

       else
       {
           extraMinnie = minnie;
           extraMaxine = maxine;
       }
       
       printf("Minnie gets $%4.2f \n", extraMinnie*.25);
       printf("Maxine gets $%4.2f \n", extraMaxine*.25); 
    }
    
    else if(minnie + maxine >= jar)
    {
        if(minnie < maxine)
        {
            minnie = maxine;
            maxine = jar - minnie;
        }
     
        else if(maxine < minnie)
        {
            maxine = minnie;
            minnie = jar - maxine;
        }
        
        else
        {
            minnie = jar/2;
            maxine = jar/2;
        }
        
        printf("Minnie gets $%4.2f \n", minnie*.25);
        printf("Maxine gets $%4.2f \n", maxine*.25);
    }
}