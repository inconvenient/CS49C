/*
 * playlist.c
 */

#include "playlist.h"

void add_last(Playlist *plist, Track *tp) {
    // add a track to end of the playlist
    if (plist->tail)
        // when the list is not empty
        plist->tail->next = tp;
    else
        // when the list is empty
        plist->head = tp;

    plist->tail = tp;
}

Track *delete_first(Playlist *plist) {
    // delete a track from the front of the playlist

    Track *tp;
    if (tp = plist->head) {

        if (tp->next)
            // when there is a following node
            plist->head = tp->next;
        else
            // when it is the only node
            plist->head = plist->tail = NULL;

        tp->next = NULL;
    }
    return tp;
}
