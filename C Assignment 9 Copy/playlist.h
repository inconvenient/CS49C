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
void add_last(Playlist *plist, Track *tp);
Track *delete_first(Playlist *plist);
#endif PLAYLIST_H