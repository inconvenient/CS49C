/*
 * controller.h
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "track.h"
#include "playlist.h"

typedef struct controller {
    Track *playing;
    Track *cued;
    Playlist loaded;
} Controller;
void init_controller(Controller *ctrl);
void load_command(Controller *ctrl, FILE *fp);
void cue_command(Controller *ctrl);
void play_command(Controller *ctrl);
#endif CONTROLLER_H