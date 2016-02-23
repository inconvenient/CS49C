#include <stdio.h>

void invite_a_friend(int me, int invites);  // declaration

int main(void)
{
    /* how many total invitations are available? */
    int invitations;
    scanf("%d", &invitations);
    
    /* start by inviting Friend_1 */
    invite_a_friend(1, invitations);
    return 0;
}

void invite_a_friend(int me, int invites)
{
     if (invites > 0) 
     {
        
        /* one invitation for me */
        printf("Friend_%d is invited.\n", me);
        invites--;
        
        /* give other invitations to my two best friends */
        int friend1 = 2 * me;
        int friend2 = 2 * me + 1;
        int invites2 = invites/2;
        int invites1 = invites-invites2;
        invite_a_friend(friend1, invites1);        
        invite_a_friend(friend2, invites2);
     }
}