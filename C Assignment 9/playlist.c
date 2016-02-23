/*
 * playlist.c
 */

#include "playlist.h"

void add_last(Playlist *plist, Track *tp)
{
    // Add a track to the tail of playlist
    if (plist->tail) 
    {   // When the list is not empty
        plist->tail->next = tp;
    }
    else
    {
        plist->head = tp;
    }
    plist->tail = tp;
}

Track *delete_first(Playlist *plist)
{
    // Delete track from front of playlist
    Track *tp;
    if (tp = plist->head)
    {
        if (tp->next)
        {   // When there is a following node
            plist->head = tp->next;
        }
        else
        {   // When this is the only node
            plist->head = plist->tail = NULL;
        }
        tp->next = NULL;
    }
    return tp;
}
