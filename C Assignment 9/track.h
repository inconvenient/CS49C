/*
 * track.h
 */
#ifndef TRACK_H // If not defined, define it, if it is, ignore.
#define TRACK_H // Define it

#include <stdio.h>

typedef struct track
{
	char *artist;
	char *title;
        struct track *next; // Points to next track
} Track;

Track *get_track(FILE *fp);
void free_track(Track *tp);
void show_track(const Track *tp, FILE *fp);

#endif TRACK_H