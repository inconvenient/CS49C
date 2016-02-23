/*
 * track.h
 */
#ifndef TRACK_H
#define TRACK_H
#include <stdio.h>

typedef struct track {
    char *artist;
    char *title;
    struct track *next;
} Track;
Track *get_track(FILE *fp);
void free_track(Track *tp);
void show_track(const Track *tp, FILE *fp);
#endif TRACK_H