/*
 * playlist.h
 */

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "track.h"

typedef struct playlist {
    Track *head;
    Track *tail;
} Playlist;

void add_last(Playlist *Plist, Track *tp); // Adds a track to the tail
Track *delete_first(Playlist *plist); // Delete the head, return the deleted file

#endif PLAYLIST_H