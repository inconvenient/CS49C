/*
 * controller.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "controller.h"

void init_controller(Controller *ctrl)
{
    ctrl->playing = NULL;
    ctrl->cued = NULL;
    ctrl->loaded.head = NULL;
    ctrl->loaded.tail = NULL;
}

void load_command(Controller *ctrl, FILE *fp)
{
    Track *tp = get_track(fp);
    if (tp)
    {
        add_last(&ctrl->loaded, tp);
        
        fprintf(stdout, "Loaded :");
        show_track(tp, stdout);
    }
}

void cue_command(Controller *ctrl)
{
    Track *tp = delete_first(&ctrl->loaded);
    if (tp)
    {
        if(ctrl->cued)
        {
            free_track(ctrl->cued);
        }
        ctrl->cued = tp;
        fprintf(stdout, "Now cued: ");
        show_track(ctrl->cued, stdout);
    }
    else
    {
        fprintf(stdout, "No tracks loaded.\n");
    }
}

void play_command(Controller *ctrl)
{
    if(ctrl->cued)
    {   // free up any currently playing track
        if(ctrl->playing)
        {
            free_track(ctrl->playing);
        }
        // Play the cued track
        ctrl->playing = ctrl->cued;
        ctrl->cued = NULL;
        fprintf(stdout, "Now playing: ");
        show_track(ctrl->playing, stdout);
        
        // Automatically cue the next track
        cue_command(ctrl);
    }
    else
    {
        fprintf(stdout, "No track cued.\n");
    }
}