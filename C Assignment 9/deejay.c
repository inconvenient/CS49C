#include <stdio.h>
#include <stdlib.h>
#include "track.h"

#include "fgetline.h"
#include "controller.h"

int main(void) {
    char tracks_file[] = "tracks.txt";
    char commands_file[] = "commands.txt";
    FILE *trks_fp, *cmds_fp;
    
    // Define and initialize controller
    Controller deejay3030;
    init_controller(&deejay3030);
    
    // Commands
    char *command;
    
    //////////////END OF DELCARAIONS//////////////
    
    while(command = fgetline(cmds_fp))
    {
        printf("Command: %s\n", command);
        // execute command
        if(!strcmp(command, "LOAD"))
            load_command(&deejay3030, trks_fp);
        else if (!strcmp(command, "CUE"))
            cue_command(&deejay3030);
        else if(!strcmp(command, "PLAY"))
            play_command(&deejay3030);
        else
            fprintf(stderr, "Unrecognized command: %s\n", command);
        
        fputc('\n', stdout);
    }

    // open the tracks database file
    if ((trks_fp = fopen(tracks_file, "r")) == NULL) {
        fprintf(stderr, "Error while opening \"%s\".\n", tracks_file);
        exit(EXIT_FAILURE);
    }
    
    // open the command sequence file
    if ((trks_fp = fopen(commands_file, "r")) == NULL)
    {
        fprintf(stderr, "Error while opening \"%s\".\n", commands_file);
        exit(EXIT_FAILURE);
    }
    
    // close all opened files
    if(fclose(trks_fp) == EOF || fclose(cmds_fp) == EOF)
    {
        fprintf(stderr, "Error while closing files\n");
        exit(EXIT_FAILURE);
    }

    // get tracks until EOF
    Track *tp;
    while (tp = get_track(trks_fp)) {
        show_track(tp, stdout);
        free_track(tp);
    }
    
    // close the tracks database
    if (fclose(trks_fp) == EOF) {
        fprintf("Error while closing \"%s\".\n", tracks_file);
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
